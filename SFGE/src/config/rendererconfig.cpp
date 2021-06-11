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
    std::string Renderer::GetWidthKeyName()
    {
        return "Width";
    }

    std::string Renderer::GetHeightKeyName()
    {
        return "Height";
    }

    std::string Renderer::GetAntiAliasingKeyName()
    {
        return "AntiAliasing";
    }

    std::string Renderer::GetMaxFpsKeyName()
    {
        return "MaxFps";
    }

    std::string Renderer::GetVSyncKeyName()
    {
        return "VSync";
    }

    std::string Renderer::GetTextureSmoothKeyName()
    {
        return "TextureSmooth";
    }

    Renderer::Renderer()
    {
        reset();
    }

    std::string Renderer::getName() const
    {
        return "Renderer";
    }

    void Renderer::setWidth(int value)
    {
        setValue(GetWidthKeyName(), value);
    }

    int Renderer::getWidth() const
    {
        return getValueInt(GetWidthKeyName());
    }

    void Renderer::setHeight(int value)
    {
        setValue(GetHeightKeyName(), value);
    }

    int Renderer::getHeight() const
    {
        return getValueInt(GetHeightKeyName());
    }

    void Renderer::setAntiAliasing(int value)
    {
        setValue(GetAntiAliasingKeyName(), value);
    }

    int Renderer::getAntiAliasing() const
    {
        return getValueInt(GetAntiAliasingKeyName());
    }

    void Renderer::setMaxFps(int value)
    {
        setValue(GetMaxFpsKeyName(), value);
    }

    int Renderer::getMaxFps() const
    {
        return getValueInt(GetMaxFpsKeyName());
    }

    void Renderer::setVSync(bool value)
    {
        setValue(GetVSyncKeyName(), value);
    }

    bool Renderer::getVSync() const
    {
        return getValueBool(GetVSyncKeyName());
    }

    void Renderer::setTextureSmooth(bool value)
    {
        setValue(GetTextureSmoothKeyName(), value);
    }

    bool Renderer::getTextureSmooth() const
    {
        return getValueBool(GetTextureSmoothKeyName());
    }

    const std::set<KeyDefinition> &Renderer::getKeyDefinitions() const
    {
        static const std::set<KeyDefinition> keys = {
                {{GetWidthKeyName(), Type::Int, 1280},
                 {GetHeightKeyName(), Type::Int, 720},
                 {GetAntiAliasingKeyName(), Type::Int, 8},
                 {GetMaxFpsKeyName(), Type::Int, 60},
                 {GetVSyncKeyName(), Type::Bool, true},
                 {GetTextureSmoothKeyName(), Type::Bool, true}}};
        return keys;
    }
}// namespace sfge::config
