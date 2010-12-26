#ifndef J2CPP_CREATE_HPP
#define J2CPP_CREATE_HPP

#include <j2cpp/config.hpp>
#include <j2cpp/local_ref.hpp>

namespace j2cpp {

	template <
		typename Object
	>
	static local_ref<Object> create();

	template <
		typename Object,
		typename A0
	>
	static local_ref<Object> create(A0 const&);

	template <
		typename Object,
		typename A0, typename A1
	>
	static local_ref<Object> create(A0 const&, A1 const&);

	template <
		typename Object,
		typename A0, typename A1, typename A2
	>
	static local_ref<Object> create(A0 const&, A1 const&, A2 const&);

	template <
		typename Object,
		typename A0, typename A1, typename A2, typename A3
	>
	static local_ref<Object> create(A0 const&, A1 const&, A2 const&, A3 const&);

	template <
		typename Object,
		typename A0, typename A1, typename A2, typename A3, typename A4
	>
	static local_ref<Object> create(A0 const&, A1 const&, A2 const&, A3 const&, A4 const&);

	template <
		typename Object,
		typename A0, typename A1, typename A2, typename A3, typename A4, typename A5
	>
	static local_ref<Object> create(A0 const&, A1 const&, A2 const&, A3 const&, A4 const&, A5 const&);

	template <
		typename Object,
		typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6
	>
	static local_ref<Object> create(A0 const&, A1 const&, A2 const&, A3 const&, A4 const&, A5 const&, A6 const&);

} //namespace j2cpp

#endif //J2CPP_CREATE_HPP
