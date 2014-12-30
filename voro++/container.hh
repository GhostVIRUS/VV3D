#ifndef VOROPP_CONTAINER_HH
#define VOROPP_CONTAINER_HH

#include <cstdio>
#include <vector>

#include "config.hh"
#include "v_base.hh"
#include "cell.hh"
#include "c_loops.hh"
#include "v_compute.hh"
#include "rad_option.hh"

namespace voro {

	class wall {
	public:
		virtual ~wall() {}
		virtual bool point_inside(double x, double y, double z) = 0;
		virtual bool cut_cell(voronoicell &c, double x, double y, double z) = 0;
		virtual bool cut_cell(voronoicell_neighbor &c, double x, double y, double z) = 0;
	};

	class wall_list {
	public:
		wall **walls;
		wall **wep;

		wall_list();
		~wall_list();

		inline void add_wall(wall *w) {
			if (wep == wel) increase_wall_memory();
			*(wep++) = w;
		}
		inline void add_wall(wall &w) { add_wall(&w); }
		void add_wall(wall_list &wl);

		inline bool point_inside_walls(double x, double y, double z) {
			for (wall **wp = walls; wp < wep; wp++) if (!((*wp)->point_inside(x, y, z))) return false;
			return true;
		}

		template<class c_class>
		bool apply_walls(c_class &c, double x, double y, double z) {
			for (wall **wp = walls; wp < wep; wp++) if (!((*wp)->cut_cell(c, x, y, z))) return false;
			return true;
		}
		void deallocate();
	protected:
		void increase_wall_memory();
		wall **wel;
		int current_wall_size;
	};

	class container_base : public voro_base, public wall_list {
	public:
		const double ax;
		const double bx;
		const double ay;
		const double by;
		const double az;
		const double bz;

		const bool xperiodic;
		const bool yperiodic;
		const bool zperiodic;

		int **id;
		double **p;
		int *co;
		int *mem;
		const int ps;

		container_base(double ax_, double bx_, double ay_, double by_, double az_, double bz_,
			int nx_, int ny_, int nz_, bool xperiodic_, bool yperiodic_, bool zperiodic_,
			int init_mem, int ps_);
		~container_base();

		bool point_inside(double x, double y, double z);

		template<class v_cell>
		inline bool initialize_voronoicell(v_cell &c, int ijk, int q, int ci, int cj, int ck,
			int &i, int &j, int &k, double &x, double &y, double &z, int &disp) {
			double x1, x2, y1, y2, z1, z2, *pp = p[ijk] + ps*q;
			x = *(pp++); y = *(pp++); z = *pp;
			if (xperiodic) { x1 = -(x2 = 0.5*(bx - ax)); i = nx; }
			else { x1 = ax - x; x2 = bx - x; i = ci; }
			if (yperiodic) { y1 = -(y2 = 0.5*(by - ay)); j = ny; }
			else { y1 = ay - y; y2 = by - y; j = cj; }
			if (zperiodic) { z1 = -(z2 = 0.5*(bz - az)); k = nz; }
			else { z1 = az - z; z2 = bz - z; k = ck; }
			c.init(x1, x2, y1, y2, z1, z2);
			if (!apply_walls(c, x, y, z)) return false;
			disp = ijk - i - nx*(j + ny*k);
			return true;
		}

		inline void initialize_search(int ci, int cj, int ck, int ijk, int &i, int &j, int &k, int &disp) {
			i = xperiodic ? nx : ci;
			j = yperiodic ? ny : cj;
			k = zperiodic ? nz : ck;
			disp = ijk - i - nx*(j + ny*k);
		}

		inline void frac_pos(double x, double y, double z, double ci, double cj, double ck,
			double &fx, double &fy, double &fz) {
			fx = x - ax - boxx*ci;
			fy = y - ay - boxy*cj;
			fz = z - az - boxz*ck;
		}

		inline int region_index(int ci, int cj, int ck, int ei, int ej, int ek, double &qx, double &qy, double &qz, int &disp) {
			if (xperiodic) { if (ci + ei < nx) { ei += nx; qx = -(bx - ax); } else if (ci + ei >= (nx << 1)) { ei -= nx; qx = bx - ax; } else qx = 0; }
			if (yperiodic) { if (cj + ej < ny) { ej += ny; qy = -(by - ay); } else if (cj + ej >= (ny << 1)) { ej -= ny; qy = by - ay; } else qy = 0; }
			if (zperiodic) { if (ck + ek < nz) { ek += nz; qz = -(bz - az); } else if (ck + ek >= (nz << 1)) { ek -= nz; qz = bz - az; } else qz = 0; }
			return disp + ei + nx*(ej + ny*ek);
		}
	protected:
		void add_particle_memory(int i);
		bool put_locate_block(int &ijk, double &x, double &y, double &z);
		inline bool put_remap(int &ijk, double &x, double &y, double &z);
		inline bool remap(int &ai, int &aj, int &ak, int &ci, int &cj, int &ck, double &x, double &y, double &z, int &ijk);
	};

	class container : public container_base, public radius_mono {
	public:
		container(double ax_, double bx_, double ay_, double by_, double az_, double bz_,
			int nx_, int ny_, int nz_, bool xperiodic_, bool yperiodic_, bool zperiodic_, int init_mem);

		void clear();
		void put(int n, double x, double y, double z);
		void put(particle_order &vo, int n, double x, double y, double z);

		void compute_all_cells();
		double sum_cell_volumes();
		bool find_voronoi_cell(double x, double y, double z, double &rx, double &ry, double &rz, int &pid);
		template<class v_cell, class c_loop>
		inline bool compute_cell(v_cell &c, c_loop &vl) {
			return vc.compute_cell(c, vl.ijk, vl.q, vl.i, vl.j, vl.k);
		}
		template<class v_cell>
		inline bool compute_cell(v_cell &c, int ijk, int q) {
			int k = ijk / nxy, ijkt = ijk - nxy*k, j = ijkt / nx, i = ijkt - j*nx;
			return vc.compute_cell(c, ijk, q, i, j, k);
		}
		template<class v_cell>
		inline bool compute_ghost_cell(v_cell &c, double x, double y, double z) {
			int ijk;
			if (put_locate_block(ijk, x, y, z)) {
				double *pp = p[ijk] + 3 * co[ijk]++;
				*(pp++) = x; *(pp++) = y; *pp = z;
				bool q = compute_cell(c, ijk, co[ijk] - 1);
				co[ijk]--;
				return q;
			}
			return false;
		}
	private:
		voro_compute<container> vc;
		friend class voro_compute < container > ;
	};

}

#endif
