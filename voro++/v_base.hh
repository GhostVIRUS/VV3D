#ifndef VOROPP_V_BASE_HH
#define VOROPP_V_BASE_HH

#include "worklist.hh"

namespace voro {

	class voro_base {
	public:
		const int nx;
		const int ny;
		const int nz;

		const int nxy;
		const int nxyz;

		const double boxx;
		const double boxy;
		const double boxz;

		const double xsp;
		const double ysp;
		const double zsp;

		double *mrad;

		static const unsigned int wl[wl_seq_length*wl_hgridcu];
		bool contains_neighbor(const char* format);
		voro_base(int nx_, int ny_, int nz_, double boxx_, double boxy_, double boxz_);
		~voro_base() { delete[] mrad; }
	protected:
		inline int step_int(double a) { return a < 0 ? int(a) - 1 : int(a); }
		inline int step_mod(int a, int b) { return a >= 0 ? a%b : b - 1 - (b - 1 - a) % b; }
		inline int step_div(int a, int b) { return a >= 0 ? a / b : -1 + (a + 1) / b; }
	private:
		void compute_minimum(double &minr, double &xlo, double &xhi, double &ylo, double &yhi, double &zlo, double &zhi, int ti, int tj, int tk);
	};

}

#endif
