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

#include "soundloader.hpp"

#include <SFML/Audio/SoundBuffer.hpp>

namespace sfge::resources
{
    bool SoundLoader::init()
    {
        auto loggerService = services::ServiceLocator::Get<services::ILoggerService>();
        m_logger = loggerService->getOrCreateLogger("SoundLoader");

        const auto config = services::ServiceLocator::Get<services::IConfigurationManagerService>();
        const auto globalConfig = config->getGlobal();
        m_logger->addLoggingFile(globalConfig->getValue(config::Global::Key::LoggingFile));

        m_logger->info("init");
        return true;
    }

    bool SoundLoader::loadFromSamples(const std::string &key, const std::vector<sf::Int16> &samples,
                                      uint32_t nbChannel, uint32_t rate)
    {
        if (exists(key))
            return false;

        auto sound = std::make_unique<sf::SoundBuffer>();
        if (!sound->loadFromSamples(&samples[0], samples.size(), nbChannel, rate)) {
            if (m_logger)
                m_logger->warning("loadFromSamples: " + key + " unable to load");
            return false;
        }
        insert(key, std::move(sound));
        return true;
    }

    bool SoundLoader::loadFromFile(const std::string &key, const std::string &path)
    {
        if (exists(key))
            return false;

        auto sound = std::make_unique<sf::SoundBuffer>();
        if (!sound->loadFromFile(path)) {
            if (m_logger)
                m_logger->warning("loadFromFile: " + path + " unable to load");
            return false;
        }
        insert(key, std::move(sound));
        return true;
    }

    bool SoundLoader::remove(const std::string &key)
    {
        const auto found = m_sounds.find(key);

        if (found == m_sounds.end()) {
            if (m_logger)
                m_logger->warning("remove: " + key + " not found");
            return false;
        }
        m_sounds.erase(found);
        return true;
    }

    void SoundLoader::clear()
    {
        if (m_logger)
            m_logger->info("clear: " + std::to_string(m_sounds.size()) + " sound(s) cleared");
        m_sounds.clear();
    }

    std::unique_ptr<sf::Sound> SoundLoader::getSound(const std::string &key) const
    {
        const auto found = m_sounds.find(key);

        if (found == m_sounds.end()) {
            return nullptr;
        }
        auto sound = std::make_unique<sf::Sound>();
        sound->setBuffer(*found->second);
        return std::move(sound);
    }

    bool SoundLoader::exists(const std::string &key) const
    {
        if (m_sounds.find(key) != m_sounds.end()) {
            m_logger->warning(key + " already exists");
            return true;
        }
        return false;
    }

    void SoundLoader::insert(const std::string &key, std::unique_ptr<sf::SoundBuffer> sound)
    {
        m_sounds.insert({key, std::move(sound)});
        if (m_logger)
            m_logger->info(key + ": " + key + " loaded");
    }
}// namespace sfge::resources