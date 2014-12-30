#include "container.hh"

namespace voro {

	container_base::container_base(double ax_, double bx_, double ay_, double by_, double az_, double bz_,
		int nx_, int ny_, int nz_, bool xperiodic_, bool yperiodic_, bool zperiodic_, int init_mem, int ps_)
		: voro_base(nx_, ny_, nz_, (bx_ - ax_) / nx_, (by_ - ay_) / ny_, (bz_ - az_) / nz_),
		ax(ax_), bx(bx_), ay(ay_), by(by_), az(az_), bz(bz_),
		xperiodic(xperiodic_), yperiodic(yperiodic_), zperiodic(zperiodic_),
		id(new int*[nxyz]), p(new double*[nxyz]), co(new int[nxyz]), mem(new int[nxyz]), ps(ps_) {
		int l;
		for (l = 0; l < nxyz; l++) co[l] = 0;
		for (l = 0; l < nxyz; l++) mem[l] = init_mem;
		for (l = 0; l < nxyz; l++) id[l] = new int[init_mem];
		for (l = 0; l < nxyz; l++) p[l] = new double[ps*init_mem];
	}

	container_base::~container_base() {
		int l;
		for (l = 0; l < nxyz; l++) delete[] p[l];
		for (l = 0; l < nxyz; l++) delete[] id[l];
		delete[] id;
		delete[] p;
		delete[] co;
		delete[] mem;
	}

	container::container(double ax_, double bx_, double ay_, double by_, double az_, double bz_,
		int nx_, int ny_, int nz_, bool xperiodic_, bool yperiodic_, bool zperiodic_, int init_mem)
		: container_base(ax_, bx_, ay_, by_, az_, bz_, nx_, ny_, nz_, xperiodic_, yperiodic_, zperiodic_, init_mem, 3),
		vc(*this, xperiodic_ ? 2 * nx_ + 1 : nx_, yperiodic_ ? 2 * ny_ + 1 : ny_, zperiodic_ ? 2 * nz_ + 1 : nz_) {}

	void container::put(int n, double x, double y, double z) {
		int ijk;
		if (put_locate_block(ijk, x, y, z)) {
			id[ijk][co[ijk]] = n;
			double *pp = p[ijk] + 3 * co[ijk]++;
			*(pp++) = x; *(pp++) = y; *pp = z;
		}
	}

	void container::put(particle_order &vo, int n, double x, double y, double z) {
		int ijk;
		if (put_locate_block(ijk, x, y, z)) {
			id[ijk][co[ijk]] = n;
			vo.add(ijk, co[ijk]);
			double *pp = p[ijk] + 3 * co[ijk]++;
			*(pp++) = x; *(pp++) = y; *pp = z;
		}
	}

	bool container_base::put_locate_block(int &ijk, double &x, double &y, double &z) {
		if (put_remap(ijk, x, y, z)) {
			if (co[ijk] == mem[ijk]) add_particle_memory(ijk);
			return true;
		}
		return false;
	}

	inline bool container_base::put_remap(int &ijk, double &x, double &y, double &z) {
		int l;

		ijk = step_int((x - ax)*xsp);
		if (xperiodic) { l = step_mod(ijk, nx); x += boxx*(l - ijk); ijk = l; }
		else if (ijk < 0 || ijk >= nx) return false;

		int j = step_int((y - ay)*ysp);
		if (yperiodic) { l = step_mod(j, ny); y += boxy*(l - j); j = l; }
		else if (j < 0 || j >= ny) return false;

		int k = step_int((z - az)*zsp);
		if (zperiodic) { l = step_mod(k, nz); z += boxz*(l - k); k = l; }
		else if (k < 0 || k >= nz) return false;

		ijk += nx*j + nxy*k;
		return true;
	}

	inline bool container_base::remap(int &ai, int &aj, int &ak, int &ci, int &cj, int &ck, double &x, double &y, double &z, int &ijk) {
		ci = step_int((x - ax)*xsp);
		if (ci < 0 || ci >= nx) {
			if (xperiodic) { ai = step_div(ci, nx); x -= ai*(bx - ax); ci -= ai*nx; }
			else return false;
		}
		else ai = 0;

		cj = step_int((y - ay)*ysp);
		if (cj < 0 || cj >= ny) {
			if (yperiodic) { aj = step_div(cj, ny); y -= aj*(by - ay); cj -= aj*ny; }
			else return false;
		}
		else aj = 0;

		ck = step_int((z - az)*zsp);
		if (ck < 0 || ck >= nz) {
			if (zperiodic) { ak = step_div(ck, nz); z -= ak*(bz - az); ck -= ak*nz; }
			else return false;
		}
		else ak = 0;

		ijk = ci + nx*cj + nxy*ck;
		return true;
	}

	bool container::find_voronoi_cell(double x, double y, double z, double &rx, double &ry, double &rz, int &pid) {
		int ai, aj, ak, ci, cj, ck, ijk;
		particle_record w;
		double mrs;

		// If the given vector lies outside the domain, but the container
		// is periodic, then remap it back into the domain
		if (!remap(ai, aj, ak, ci, cj, ck, x, y, z, ijk)) return false;
		vc.find_voronoi_cell(x, y, z, ci, cj, ck, ijk, w, mrs);

		if (w.ijk != -1) {

			// Assemble the position vector of the particle to be returned,
			// applying a periodic remapping if necessary
			if (xperiodic) { ci += w.di; if (ci < 0 || ci >= nx) ai += step_div(ci, nx); }
			if (yperiodic) { cj += w.dj; if (cj < 0 || cj >= ny) aj += step_div(cj, ny); }
			if (zperiodic) { ck += w.dk; if (ck < 0 || ck >= nz) ak += step_div(ck, nz); }
			rx = p[w.ijk][3 * w.l] + ai*(bx - ax);
			ry = p[w.ijk][3 * w.l + 1] + aj*(by - ay);
			rz = p[w.ijk][3 * w.l + 2] + ak*(bz - az);
			pid = id[w.ijk][w.l];
			return true;
		}

		// If no particle if found then just return false
		return false;
	}

	void container_base::add_particle_memory(int i) {
		int l, nmem = mem[i] << 1;

		// Allocate new memory and copy in the contents of the old arrays
		int *idp = new int[nmem];
		for (l = 0; l < co[i]; l++) idp[l] = id[i][l];
		double *pp = new double[ps*nmem];
		for (l = 0; l < ps*co[i]; l++) pp[l] = p[i][l];

		// Update pointers and delete old arrays
		mem[i] = nmem;
		delete[] id[i]; id[i] = idp;
		delete[] p[i]; p[i] = pp;
	}

	void container::clear() {
		for (int *cop = co; cop < co + nxyz; cop++) *cop = 0;
	}

	void container::compute_all_cells() {
		voronoicell c;
		c_loop_all vl(*this);
		if (vl.start()) do compute_cell(c, vl);
		while (vl.inc());
	}

	double container::sum_cell_volumes() {
		voronoicell c;
		double vol = 0;
		c_loop_all vl(*this);
		if (vl.start()) do if (compute_cell(c, vl)) vol += c.volume(); while (vl.inc());
		return vol;
	}

	bool container_base::point_inside(double x, double y, double z) {
		if (x<ax || x>bx || y<ay || y>by || z<az || z>bz) return false;
		return point_inside_walls(x, y, z);
	}

	wall_list::wall_list() : walls(new wall*[init_wall_size]), wep(walls), wel(walls + init_wall_size),
		current_wall_size(init_wall_size) {}

	wall_list::~wall_list() {
		delete[] walls;
	}

	void wall_list::add_wall(wall_list &wl) {
		for (wall **wp = wl.walls; wp < wl.wep; wp++) add_wall(*wp);
	}

	void wall_list::deallocate() {
		for (wall **wp = walls; wp < wep; wp++) delete *wp;
	}

	void wall_list::increase_wall_memory() {
		current_wall_size <<= 1;
		wall **nwalls = new wall*[current_wall_size], **nwp = nwalls, **wp = walls;
		while (wp < wep) *(nwp++) = *(wp++);
		delete[] walls;
		walls = nwalls; wel = walls + current_wall_size; wep = nwp;
	}

}
