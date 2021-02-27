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

#include "mock/scriptablestates.hpp"

#include <algorithm>

void ScriptableStates::insert(ScriptableState state)
{
    m_states.push_back(state);
}

std::size_t ScriptableStates::size() const
{
    return m_states.size();
}

bool ScriptableStates::operator==(ScriptableState state) const
{
    return std::all_of(m_states.begin(), m_states.end(), [state](ScriptableState o) {
        return state == o;
    });
}