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

#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include <memory>
#include <string>

namespace sfge::services
{
    struct ISoundLoaderService {
        virtual ~ISoundLoaderService() = default;

        virtual bool init() = 0;
        virtual bool loadFromSamples(const std::string &key, const std::vector<sf::Int16> &samples,
                                     uint32_t nbChannel, uint32_t rate) = 0;
        virtual bool loadFromFile(const std::string &key, const std::string &path) = 0;
        virtual bool remove(const std::string &key) = 0;
        virtual void clear() = 0;

        [[nodiscard]] virtual std::unique_ptr<sf::Sound> getSound(const std::string &key) const = 0;
    };
}// namespace sfge::services