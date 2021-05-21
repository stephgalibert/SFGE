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

#define WIDTH_KEY_NAME "Width"
#define HEIGHT_KEY_NAME "Height"
#define ANTI_ALIASING_KEY_NAME "AntiAliasing"
#define MAX_FPS_KEY_NAME "MaxFps"
#define VSYNC_KEY_NAME "VSync"
#define TEXTURE_SMOOTH_KEY_NAME "TextureSmooth"

namespace sfge::config
{
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
        setValue(WIDTH_KEY_NAME, value);
    }

    int Renderer::getWidth() const
    {
        return getValueInt(WIDTH_KEY_NAME);
    }

    void Renderer::setHeight(int value)
    {
        setValue(HEIGHT_KEY_NAME, value);
    }

    int Renderer::getHeight() const
    {
        return getValueInt(HEIGHT_KEY_NAME);
    }

    void Renderer::setAntiAliasing(int value)
    {
        setValue(ANTI_ALIASING_KEY_NAME, value);
    }

    int Renderer::getAntiAliasing() const
    {
        return getValueInt(ANTI_ALIASING_KEY_NAME);
    }

    void Renderer::setMaxFps(int value)
    {
        setValue(MAX_FPS_KEY_NAME, value);
    }

    int Renderer::getMaxFps() const
    {
        return getValueInt(MAX_FPS_KEY_NAME);
    }

    void Renderer::setVSync(bool value)
    {
        setValue(VSYNC_KEY_NAME, value);
    }

    bool Renderer::getVSync() const
    {
        return getValueBool(VSYNC_KEY_NAME);
    }

    void Renderer::setTextureSmooth(bool value)
    {
        setValue(TEXTURE_SMOOTH_KEY_NAME, value);
    }

    bool Renderer::getTextureSmooth() const
    {
        return getValueBool(TEXTURE_SMOOTH_KEY_NAME);
    }

    const std::set<KeyInfo> &Renderer::getKeys() const
    {
        static const std::set<KeyInfo> keys = {
                {{WIDTH_KEY_NAME, Type::Int, "1280"},
                 {HEIGHT_KEY_NAME, Type::Int, "720"},
                 {ANTI_ALIASING_KEY_NAME, Type::Int, "8"},
                 {MAX_FPS_KEY_NAME, Type::Int, "60"},
                 {VSYNC_KEY_NAME, Type::Bool, "true"},
                 {TEXTURE_SMOOTH_KEY_NAME, Type::Bool, "true"}}};
        return keys;
    }
}// namespace sfge::config
