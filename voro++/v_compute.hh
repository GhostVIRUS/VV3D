#ifndef VOROPP_V_COMPUTE_HH
#define VOROPP_V_COMPUTE_HH

#include "config.hh"
#include "worklist.hh"
#include "cell.hh"

namespace voro {

	struct particle_record {
		int ijk;
		int l;
		int di;
		int dj;
		int dk;
	};

	template <class c_class>
	class voro_compute {
	public:
		c_class &con;

		const double boxx;
		const double boxy;
		const double boxz;

		const double xsp;
		const double ysp;
		const double zsp;

		const int hx;
		const int hy;
		const int hz;

		const int hxy;
		const int hxyz;

		const int ps;

		int **id;
		double **p;
		int *co;

		voro_compute(c_class &con_, int hx_, int hy_, int hz_);
		~voro_compute() {
			delete[] qu;
			delete[] mask;
		}
		template<class v_cell>
		bool compute_cell(v_cell &c, int ijk, int s, int ci, int cj, int ck);
		void find_voronoi_cell(double x, double y, double z, int ci, int cj, int ck, int ijk, particle_record &w, double &mrs);
	private:
		const double bxsq;
		unsigned int mv;
		int qu_size;
		const unsigned int *wl;
		double *mrad;
		unsigned int *mask;
		int *qu;
		int *qu_l;
		template<class v_cell>
		bool corner_test(v_cell &c, double xl, double yl, double zl, double xh, double yh, double zh);
		template<class v_cell>
		inline bool edge_x_test(v_cell &c, double x0, double yl, double zl, double x1, double yh, double zh);
		template<class v_cell>
		inline bool edge_y_test(v_cell &c, double xl, double y0, double zl, double xh, double y1, double zh);
		template<class v_cell>
		inline bool edge_z_test(v_cell &c, double xl, double yl, double z0, double xh, double yh, double z1);
		template<class v_cell>
		inline bool face_x_test(v_cell &c, double xl, double y0, double z0, double y1, double z1);
		template<class v_cell>
		inline bool face_y_test(v_cell &c, double x0, double yl, double z0, double x1, double z1);
		template<class v_cell>
		inline bool face_z_test(v_cell &c, double x0, double y0, double zl, double x1, double y1);
		bool compute_min_max_radius(int di, int dj, int dk, double fx, double fy, double fz, double gx, double gy, double gz, double& crs, double mrs);
		bool compute_min_radius(int di, int dj, int dk, double fx, double fy, double fz, double mrs);
		inline void add_to_mask(int ei, int ej, int ek, int *&qu_e);
		inline void scan_bits_mask_add(unsigned int q, unsigned int *mijk, int ei, int ej, int ek, int *&qu_e);
		inline void scan_all(int ijk, double x, double y, double z, int di, int dj, int dk, particle_record &w, double &mrs);
		void add_list_memory(int*& qu_s, int*& qu_e);
		inline void reset_mask() {
			for (unsigned int *mp(mask); mp < mask + hxyz; mp++) *mp = 0;
		}
	};

}

#endif
