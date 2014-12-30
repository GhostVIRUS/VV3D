#ifndef VOROPP_RAD_OPTION_HH
#define VOROPP_RAD_OPTION_HH

#include <cmath>

namespace voro {

	class radius_mono {
	protected:
		inline void r_init(int ijk, int s) {}
		inline void r_prime(double rv) {}
		inline bool r_ctest(double crs, double mrs) { return crs > mrs; }
		inline double r_cutoff(double lrs) { return lrs; }
		inline double r_max_add(double rs) { return rs; }
		inline double r_current_sub(double rs, int ijk, int q) { return rs; }
		inline double r_scale(double rs, int ijk, int q) { return rs; }
		inline bool r_scale_check(double &rs, double mrs, int ijk, int q) { return rs < mrs; }
	};

}
#endif
