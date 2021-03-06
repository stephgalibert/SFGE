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

#include "sfge/services/imusicloaderservice.hpp"

#include <unordered_map>

namespace sfge
{
    struct ILogger;
}

namespace sfge::resources
{
    class MusicLoader : public services::IMusicLoaderService
    {
    public:
        bool init() override;
        bool openFromFile(const std::string &key, const std::string &path) override;
        bool remove(const std::string &key) override;
        void clear() override;

        [[nodiscard]] std::shared_ptr<sf::Music> getMusic(const std::string &key) const override;

    private:
        std::shared_ptr<ILogger> m_logger;
        std::unordered_map<std::string, std::shared_ptr<sf::Music>> m_musics;
    };
}// namespace sfge::resources