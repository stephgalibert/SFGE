//
// This file is part of SFGE.
// Copyright (C) 2020-2021 sgalibert (stephane.galibert.perso@outlook.com)
//
// SFGE is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// SFGE is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with SFGE. If not, see <https://www.gnu.org/licenses/>.
//

#pragma once

/*
** PIMPL design pattern
** This implementation may be a lil bit overkill but always good to have it somewhere.
** https://en.wikipedia.org/wiki/Opaque_pointer
*/

#define PIMPL_DECLARE_PRIVATE(Cls)                                               \
    std::unique_ptr<Cls##Private> d_ptr;                                         \
    inline std::unique_ptr<Cls##Private> &d_func() { return d_ptr; }             \
    inline const std::unique_ptr<Cls##Private> &d_func() const { return d_ptr; } \
    friend class Cls##Private;

#define PIMPL_DECLARE_PUBLIC(Cls)                      \
    Cls *q_ptr;                                        \
    inline Cls *q_func() { return q_ptr; }             \
    inline const Cls *d_func() const { return q_ptr; } \
    friend class Cls

#define PIMPL_Q(Cls) \
    Cls *q = q_func()

#define PIMPL_D(Cls) \
    std::unique_ptr<Cls##Private> &d = d_func()
