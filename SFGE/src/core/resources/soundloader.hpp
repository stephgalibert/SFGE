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

#include "sfge/services/isoundloaderservice.hpp"

#include <unordered_map>

namespace sfge
{
    struct ILogger;
}

namespace sfge::resources
{
    class SoundLoader : public services::ISoundLoaderService
    {
    public:
        bool init() override;
        bool loadFromSamples(const std::string &key, const std::vector<sf::Int16> &samples,
                             uint32_t nbChannel, uint32_t rate) override;
        bool loadFromFile(const std::string &key, const std::string &path) override;
        bool remove(const std::string &key) override;
        void clear() override;

        [[nodiscard]] std::unique_ptr<sf::Sound> getSound(const std::string &key) const override;

    private:
        bool exists(const std::string &key) const;
        void insert(const std::string &key, std::unique_ptr<sf::SoundBuffer> texture);

    private:
        std::shared_ptr<ILogger> m_logger;
        std::unordered_map<std::string, std::unique_ptr<sf::SoundBuffer>> m_sounds;
    };
}// namespace sfge::resources
