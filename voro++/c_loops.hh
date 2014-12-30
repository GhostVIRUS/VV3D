#ifndef VOROPP_C_LOOPS_HH
#define VOROPP_C_LOOPS_HH

#include "config.hh"

namespace voro {

	enum c_loop_subset_mode {
		sphere,
		box,
		no_check
	};

	class particle_order {
	public:
		int *o;
		int *op;

		int size;

		particle_order(int init_size = init_ordering_size)
			: o(new int[init_size << 1]), op(o), size(init_size) {}
		~particle_order() {
			delete[] o;
		}

		inline void add(int ijk, int q) {
			if (op == o + size) add_ordering_memory();
			*(op++) = ijk; *(op++) = q;
		}
	private:
		void add_ordering_memory();
	};

	class c_loop_base {
	public:
		const int nx;
		const int ny;
		const int nz;

		const int nxy;
		const int nxyz;

		const int ps;

		double **p;
		int **id;
		int *co;

		int i;
		int j;
		int k;
		int ijk;

		int q;

		template<class c_class>
		c_loop_base(c_class &con) : nx(con.nx), ny(con.ny), nz(con.nz),
			nxy(con.nxy), nxyz(con.nxyz), ps(con.ps),
			p(con.p), id(con.id), co(con.co) {}

		inline void pos(double &x, double &y, double &z) {
			double *pp = p[ijk] + ps*q;
			x = *(pp++); y = *(pp++); z = *pp;
		}

		inline void pos(int &pid, double &x, double &y, double &z, double &r) {
			pid = id[ijk][q];
			double *pp = p[ijk] + ps*q;
			x = *(pp++); y = *(pp++); z = *pp;
			r = ps == 3 ? default_radius : *(++pp);
		}

		inline double x() { return p[ijk][ps*q]; }
		inline double y() { return p[ijk][ps*q + 1]; }
		inline double z() { return p[ijk][ps*q + 2]; }

		inline int pid() { return id[ijk][q]; }
	};

	class c_loop_all : public c_loop_base {
	public:
		template<class c_class>
		c_loop_all(c_class &con) : c_loop_base(con) {}

		inline bool start() {
			i = j = k = ijk = q = 0;
			while (co[ijk] == 0) if (!next_block()) return false;
			return true;
		}

		inline bool inc() {
			q++;
			if (q >= co[ijk]) {
				q = 0;
				do {
					if (!next_block()) return false;
				} while (co[ijk] == 0);
			}
			return true;
		}
	private:
		inline bool next_block() {
			ijk++;
			i++;
			if (i == nx) {
				i = 0; j++;
				if (j == ny) {
					j = 0; k++;
					if (ijk == nxyz) return false;
				}
			}
			return true;
		}
	};

	class c_loop_order : public c_loop_base {
	public:
		particle_order &vo;

		int *cp;
		int *op;

		template<class c_class>
		c_loop_order(c_class &con, particle_order &vo_)
			: c_loop_base(con), vo(vo_), nx(con.nx), nxy(con.nxy) {}

		inline bool start() {
			cp = vo.o; op = vo.op;
			if (cp != op) {
				ijk = *(cp++); decode();
				q = *(cp++);
				return true;
			}
			else return false;
		}

		inline bool inc() {
			if (cp == op) return false;
			ijk = *(cp++); decode();
			q = *(cp++);
			return true;
		}
	private:
		const int nx;
		const int nxy;
		inline void decode() {
			k = ijk / nxy;
			int ijkt = ijk - nxy*k;
			j = ijkt / nx;
			i = ijkt - j*nx;
		}
	};

}

#endif
