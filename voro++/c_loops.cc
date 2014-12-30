#include "c_loops.hh"

namespace voro {

	void particle_order::add_ordering_memory() {
		int *no = new int[size << 2], *nop = no, *opp = o;
		while (opp < op) *(nop++) = *(opp++);
		delete[] o;
		size <<= 1; o = no; op = nop;
	}

}
