#pragma once

/*
** PIMPL design pattern
** This implementation may be a lil bit overkill but always good to have it somewhere.
** https://en.wikipedia.org/wiki/Opaque_pointer
*/

#define PIMPL_DECLARE_PRIVATE(Cls) \
	std::unique_ptr<Cls##Private> d_ptr; \
	inline std::unique_ptr<Cls##Private> &d_func() { return d_ptr; } \
	inline const std::unique_ptr<Cls##Private> &d_func() const { return d_ptr; } \
	friend class Cls##Private

#define PIMPL_DECLARE_PUBLIC(Cls) \
	Cls *q_ptr; \
	inline Cls *q_func() { return q_ptr; } \
	inline const Cls *d_func() const { return q_ptr; } \
	friend class Cls

#define PIMPL_Q(Cls) \
	Cls *q = q_func()

#define PIMPL_D(Cls) \
	std::unique_ptr<Cls##Private> &d = d_func()

