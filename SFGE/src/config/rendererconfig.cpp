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

#include "rendererconfig.hpp"

namespace sfge::config
{
    std::string Renderer::KeyToString(Key key)
    {
        static const std::unordered_map<Key, std::string> map = {
                {{Key::Width}, {"Width"}},
                {{Key::Height}, {"Height"}},
                {{Key::AntiAliasing}, {"AntiAliasing"}},
                {{Key::MaxFps}, {"MaxFps"}},
                {{Key::VSync}, {"VSync"}}};
        return map.at(key);
    }

    const auto &Renderer::GetDefault()
    {
        static const std::unordered_map<std::string, std::string> values = {
                {{KeyToString(Key::Width)}, {"1280"}},
                {{KeyToString(Key::Height)}, {"720"}},
                {{KeyToString(Key::AntiAliasing)}, {"8"}},
                {{KeyToString(Key::MaxFps)}, {"60"}},
                {{KeyToString(Key::VSync)}, {"1"}}};
        return values;
    }

    Renderer::Renderer()
    {
        reset();
    }

    std::string Renderer::getName() const
    {
        return "Renderer";
    }

    const std::unordered_map<std::string, std::string> &Renderer::getKeysValues() const
    {
        return m_values;
    }

    void Renderer::setValue(const std::string &key, const std::string &value)
    {
        m_values[key] = value;
    }

    void Renderer::reset()
    {
        m_values = GetDefault();
    }

    std::string Renderer::getValue(Key key) const
    {
        return m_values.at(KeyToString(key));
    }

    void Renderer::setValue(Key key, int value)
    {
        setValue(KeyToString(key), std::to_string(value));
    }

    void Renderer::setValue(Key key, float value)
    {
        setValue(KeyToString(key), std::to_string(value));
    }

    void Renderer::setValue(Key key, const std::string &value)
    {
        setValue(KeyToString(key), value);
    }
}// namespace sfge::config
