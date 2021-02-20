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

#include "cavegeneration.hpp"

#include <iostream>

namespace sfge::random
{
    CaveGeneration::CaveGeneration(std::size_t seed, std::size_t w, std::size_t h)
        : m_cave(h, std::vector<bool>(w, false)),
          m_random(seed)
    {
        setWallGenerationPercent(45);
        setSmoothPassCount(5);
    }

    void CaveGeneration::setSeed(std::size_t seed)
    {
        m_random.setSeed(seed);
    }

    void CaveGeneration::setWallGenerationPercent(std::size_t percent)
    {
        m_wallGenerationPercent = percent;
    }

    void CaveGeneration::setSmoothPassCount(std::size_t count)
    {
        m_smoothPassCount = count;
    }

    void CaveGeneration::generate()
    {
        fill();

        for (int i = 0; i < m_smoothPassCount; ++i)
            smooth();
    }

    void CaveGeneration::dump()
    {
        for (auto &col : m_cave) {
            for (auto &&row : col)
                std::cout << row << " ";
            std::cout << std::endl;
        }
    }

    const std::vector<std::vector<bool>> &CaveGeneration::getGenerated() const
    {
        return m_cave;
    }

    void CaveGeneration::fill()
    {
        for (std::size_t j = 0; j < m_cave.size(); ++j) {
            for (std::size_t i = 0; i < m_cave[j].size(); ++i) {
                bool value = true;

                if (j > 0 && j < m_cave.size() - 1 && i > 0 && i < m_cave[j].size() - 1)
                    value = (m_random.genInt(0, 100) < m_wallGenerationPercent);
                m_cave[j][i] = value;
            }
        }
    }

    void CaveGeneration::smooth()
    {
        for (std::size_t j = 0; j < m_cave.size(); ++j) {
            for (std::size_t i = 0; i < m_cave[j].size(); ++i) {
                const uint32_t wallCount = neighborWallCount(i, j);
                // TODO: set wallcount condition settable
                if (wallCount > 4) {
                    m_cave[j][i] = true;
                } else if (wallCount < 4) {
                    m_cave[j][i] = false;
                }
            }
        }
    }

    uint32_t CaveGeneration::neighborWallCount(int x, int y) const
    {
        uint32_t k = 0;

        for (int j = y - 1; j <= y + 1; ++j) {
            for (int i = x - 1; i <= x + 1; ++i) {
                // TODO: remove the signed/unsigned warning
                if (j >= 0 && j < m_cave.size() && i >= 0 && i < m_cave[j].size()) {
                    if (y != j || x != i)
                        k += static_cast<int>(m_cave[j][i]);
                } else {
                    k++;
                }
            }
        }
        return k;
    }
}// namespace sfge::random