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

#include "lehmer32.hpp"

#include <vector>

namespace sfge::random
{
    class CaveGeneration
    {
    public:
        CaveGeneration(std::size_t seed, std::size_t w, std::size_t h);

        void setSeed(std::size_t seed);
        void setWallGenerationPercent(std::size_t percent);
        void setSmoothPassCount(std::size_t count);

        void generate();

        const std::vector<std::vector<bool>> &getGenerated() const;
        void dump();

    private:
        void fill();
        void smooth();
        uint32_t neighborWallCount(int x, int y) const;

    private:
        std::vector<std::vector<bool>> m_cave;// TODO: 1d
        Lehmer32 m_random;
        int m_wallGenerationPercent;
        int m_smoothPassCount;
    };
}// namespace sfge::random