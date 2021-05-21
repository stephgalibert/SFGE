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

#include "config/globalconfig.hpp"
#include "services/iconfigurationmanagerservice.h"
#include "sfge/logger/logger.hpp"
#include "sfge/services/iloggerservice.hpp"
#include "sfge/services/servicelocator.hpp"

#include "musicloader.hpp"

namespace sfge::resources
{
    bool MusicLoader::init()
    {
        auto loggerService = services::ServiceLocator::Get<services::ILoggerService>();
        m_logger = loggerService->getOrCreateLogger("MusicLoader");

        const auto config = services::ServiceLocator::Get<services::IConfigurationManagerService>();
        const auto globalConfig = config->getGlobal();
        m_logger->addLoggingFile(globalConfig->getLoggingFilePath());

        m_logger->info("init");
        return true;
    }

    bool MusicLoader::openFromFile(const std::string &key, const std::string &path)
    {
        if (m_musics.find(key) != m_musics.end()) {
            m_logger->warning("openFromFile: " + key + " already exists");
            return false;
        }

        auto music = std::make_shared<sf::Music>();
        if (!music->openFromFile(path)) {
            m_logger->warning("openFromFile: " + path + " unable to load");
            return false;
        }

        m_musics.insert({key, music});
        m_logger->info("openFromFile: " + key + ": " + path + " loaded");
        return true;
    }

    bool MusicLoader::remove(const std::string &key)
    {
        const auto found = m_musics.find(key);

        if (found == m_musics.end()) {
            m_logger->warning("remove: " + key + " not found");
            return false;
        }
        m_musics.erase(found);
        return true;
    }

    void MusicLoader::clear()
    {
        m_logger->info("clear: " + std::to_string(m_musics.size()) + " music(s) cleared");
        m_musics.clear();
    }

    std::shared_ptr<sf::Music> MusicLoader::getMusic(const std::string &key) const
    {
        const auto found = m_musics.find(key);

        if (found == m_musics.end())
            return nullptr;
        return found->second;
    }
}// namespace sfge::resources