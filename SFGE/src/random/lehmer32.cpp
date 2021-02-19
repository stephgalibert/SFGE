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

#include "lehmer32.hpp"

namespace sfge::random
{
    Lehmer32::Lehmer32(uint32_t seed)
        : m_state(seed)
    {
    }

    void Lehmer32::setSeed(uint32_t seed)
    {
        m_state = seed;
    }

    bool Lehmer32::genBool()
    {
        return next() % 2;
    }

    int Lehmer32::genInt(int min, int max)
    {
        return (next() % (max - min)) + min;
    }

    double Lehmer32::genDouble(double min, double max)
    {
        return (static_cast<double>(next()) / static_cast<double>(0x7fffffff)) * (max - min) + min;
    }

    uint32_t Lehmer32::next()
    {
        m_state += 0xe120fc15;
        uint64_t tmp = static_cast<uint64_t>(m_state) * 0x4a39b70d;
        uint32_t m1 = static_cast<uint32_t>((tmp >> 32) ^ tmp);
        tmp = static_cast<uint64_t>(m1) * 0x12fad5c9;
        uint32_t m2 = static_cast<uint32_t>((tmp >> 32) ^ tmp);
        return m2;
    }
}// namespace sfge::random