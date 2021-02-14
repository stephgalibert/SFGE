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

namespace sfge::ecs
{
    template<typename T>
    decltype(auto) Scriptable::addScript()
    {
        m_scripts.push_back(std::make_unique<T>());
        return m_scripts.back();
    }

    template<typename T>
    void Scriptable::removeScript()
    {
        auto f = [&](const auto &script) {
            if (typeid(T) == typeid(*script)) {
                script->onDestroy();
                return true;
            }
            return false;
        };

        m_scripts.erase(std::remove_if(m_scripts.begin(), m_scripts.end(), f), m_scripts.end());
    }
}// namespace sfge::ecs