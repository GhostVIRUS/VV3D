#ifndef VOROPP_CELL_HH
#define VOROPP_CELL_HH

#include <vector>

#include "config.hh"

namespace voro {

	class voronoicell_base {
	public:
		int current_vertices;
		int current_vertex_order;
		int current_delete_size;
		int current_delete2_size;

		int p;
		int up;

		int **ed;
		int *nu;
		double *pts;

		voronoicell_base();
		~voronoicell_base();
		void init_base(double xmin, double xmax, double ymin, double ymax, double zmin, double zmax);
		void translate(double x, double y, double z);
		double volume();
		double max_radius_squared();
		double total_edge_distance();
		double surface_area();
		int number_of_faces();
		int number_of_edges();
		void vertices(std::vector<double> &v);
		void vertices(double x, double y, double z, std::vector<double> &v);
		void face_areas(std::vector<double> &v);
		void face_vertices(std::vector<int> &v);
		void face_perimeters(std::vector<double> &v);
		template<class vc_class>
		bool nplane(vc_class &vc, double x, double y, double z, double rsq, int p_id);
		bool plane_intersects(double x, double y, double z, double rsq);
		bool plane_intersects_guess(double x, double y, double z, double rsq);
		void construct_relations();
		inline int cycle_up(int a, int p) { return a == nu[p] - 1 ? 0 : a + 1; }
		inline int cycle_down(int a, int p) { return a == 0 ? nu[p] - 1 : a - 1; }
	protected:
		int *mem;
		int *mec;
		int **mep;
		inline void reset_edges();
		template<class vc_class>
		void check_memory_for_copy(vc_class &vc, voronoicell_base* vb);
		void copy(voronoicell_base* vb);
	private:
		int *ds, *stacke;
		int *ds2, *stacke2;
		int current_marginal;
		int n_marg;
		int *marg;

		double px;
		double py;
		double pz;

		double prsq;
		template<class vc_class>
		void add_memory(vc_class &vc, int i, int *stackp2);
		template<class vc_class>
		void add_memory_vertices(vc_class &vc);
		template<class vc_class>
		void add_memory_vorder(vc_class &vc);
		void add_memory_ds(int *&stackp);
		void add_memory_ds2(int *&stackp2);
		template<class vc_class>
		inline bool collapse_order1(vc_class &vc);
		template<class vc_class>
		inline bool collapse_order2(vc_class &vc);
		template<class vc_class>
		inline bool delete_connection(vc_class &vc, int j, int k, bool hand);
		template<class vc_class>
		inline bool search_for_outside_edge(vc_class &vc, int &up);
		template<class vc_class>
		inline void add_to_stack(vc_class &vc, int lp, int *&stackp2);
		inline bool plane_intersects_track(double x, double y, double z, double rs, double g);
		inline void normals_search(std::vector<double> &v, int i, int j, int k);
		inline bool search_edge(int l, int &m, int &k);
		inline int m_test(int n, double &ans);
		int check_marginal(int n, double &ans);
		friend class voronoicell;
		friend class voronoicell_neighbor;
	};

	class voronoicell : public voronoicell_base {
	public:
		using voronoicell_base::nplane;
		inline void operator=(voronoicell &c) {
			voronoicell_base* vb((voronoicell_base*)&c);
			check_memory_for_copy(*this, vb); copy(vb);
		}
		inline bool nplane(double x, double y, double z, double rsq, int p_id) {
			return nplane(*this, x, y, z, rsq, 0);
		}
		inline bool nplane(double x, double y, double z, int p_id) {
			double rsq = x*x + y*y + z*z;
			return nplane(*this, x, y, z, rsq, 0);
		}
		inline bool plane(double x, double y, double z, double rsq) {
			return nplane(*this, x, y, z, rsq, 0);
		}
		inline bool plane(double x, double y, double z) {
			double rsq = x*x + y*y + z*z;
			return nplane(*this, x, y, z, rsq, 0);
		}
		inline void init(double xmin, double xmax, double ymin, double ymax, double zmin, double zmax) {
			init_base(xmin, xmax, ymin, ymax, zmin, zmax);
		}

	private:
		inline void n_allocate(int i, int m) {};
		inline void n_add_memory_vertices(int i) {};
		inline void n_add_memory_vorder(int i) {};
		inline void n_set_pointer(int p, int n) {};
		inline void n_copy(int a, int b, int c, int d) {};
		inline void n_set(int a, int b, int c) {};
		inline void n_set_aux1(int k) {};
		inline void n_copy_aux1(int a, int b) {};
		inline void n_copy_aux1_shift(int a, int b) {};
		inline void n_set_aux2_copy(int a, int b) {};
		inline void n_copy_pointer(int a, int b) {};
		inline void n_set_to_aux1(int j) {};
		inline void n_set_to_aux2(int j) {};
		inline void n_allocate_aux1(int i) {};
		inline void n_switch_to_aux1(int i) {};
		inline void n_copy_to_aux1(int i, int m) {};
		inline void n_set_to_aux1_offset(int k, int m) {};
		inline void n_neighbors(std::vector<int> &v) { v.clear(); };
		friend class voronoicell_base;
	};

}

#endif
