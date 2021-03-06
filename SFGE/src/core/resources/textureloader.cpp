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

#include "textureloader.hpp"

#include "config/globalconfig.hpp"
#include "config/rendererconfig.hpp"
#include "services/iconfigurationmanagerservice.h"
#include "sfge/logger/logger.hpp"
#include "sfge/services/iloggerservice.hpp"
#include "sfge/services/servicelocator.hpp"

namespace sfge::resources
{
    bool TextureLoader::init()
    {
        auto loggerService = services::ServiceLocator::Get<services::ILoggerService>();
        m_logger = loggerService->getOrCreateLogger("TextureLoader");

        const auto config = services::ServiceLocator::Get<services::IConfigurationManagerService>();
        const auto globalConfig = config->getGlobal();
        m_logger->addLoggingFile(globalConfig->getLoggingFilePath());
        const auto renderConfig = config->getRenderer();
        m_smoothing = renderConfig->getTextureSmooth();

        m_logger->info("init: Smoothing=" + std::to_string(m_smoothing));
        return true;
    }

    bool TextureLoader::loadFromFile(const std::string &key, const std::string &path)
    {
        if (exists(key))
            return false;

        auto texture = std::make_unique<sf::Texture>();
        if (!texture->loadFromFile(path)) {
            if (m_logger)
                m_logger->warning("loadFromFile: " + path + " unable to load");
            return false;
        }
        insert(key, std::move(texture));
        return true;
    }

    bool TextureLoader::loadFromMemory(const std::string &key, const std::vector<unsigned char> &data)
    {
        if (exists(key))
            return false;

        const void *vdata = static_cast<const void *>(data.data());
        auto texture = std::make_unique<sf::Texture>();
        if (!texture->loadFromMemory(vdata, data.size())) {
            if (m_logger)
                m_logger->warning("loadFromMemory: " + key + " unable to load");
            return false;
        }
        insert(key, std::move(texture));
        return true;
    }

    bool TextureLoader::remove(const std::string &key)
    {
        const auto found = m_textures.find(key);

        if (found == m_textures.end()) {
            if (m_logger)
                m_logger->warning("remove: " + key + " not found");
            return false;
        }
        m_textures.erase(found);
        return true;
    }

    void TextureLoader::clear()
    {
        if (m_logger)
            m_logger->info("clear: " + std::to_string(m_textures.size()) + " textures cleared");
        m_textures.clear();
    }

    sf::Texture *TextureLoader::getTexture(const std::string &key) const
    {
        const auto found = m_textures.find(key);

        if (found == m_textures.end())
            return nullptr;
        return found->second.get();
    }

    bool TextureLoader::exists(const std::string &key) const
    {
        if (m_textures.find(key) != m_textures.end()) {
            if (m_logger)
                m_logger->warning(key + " already exists");
            return true;
        }
        return false;
    }

    void TextureLoader::insert(const std::string &key, std::unique_ptr<sf::Texture> texture)
    {
        texture->setSmooth(m_smoothing);
        m_textures.insert({key, std::move(texture)});
        if (m_logger)
            m_logger->info(key + " loaded");
    }
}// namespace sfge::resources