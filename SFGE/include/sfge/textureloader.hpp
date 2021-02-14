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

#include "sfge/logger/logger.hpp"

#include <SFML/Graphics/Texture.hpp>

#include <memory>
#include <unordered_map>

namespace sfge::resource
{
    class TextureLoader
    {
    public:
        static TextureLoader &GetInstance();

        bool load(const std::string &key, const std::string &path);
        sf::Texture *getTexture(const std::string &key) const;

        void clear();

    private:
        TextureLoader();

    private:
        bool m_smoothing;

        std::shared_ptr<ILogger> m_logger;
        std::unordered_map<std::string, std::unique_ptr<sf::Texture>> m_textures;
    };
}// namespace sfge::resource
