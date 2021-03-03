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
        m_logger = loggerService->createLogger("TextureLoader");

        const auto config = services::ServiceLocator::Get<services::IConfigurationManagerService>();
        const auto globalConfig = config->getGlobal();

        m_logger->addLoggingFile(globalConfig->getValue(config::Global::Key::LoggingFile));

        const auto renderConfig = config->getRenderer();
        m_smoothing = renderConfig->getValue<bool>(config::Renderer::Key::TextureSmooth);
        m_logger->info("init: Smoothing=" + std::to_string(m_smoothing));
        return true;
    }

    bool TextureLoader::loadFromFile(const std::string &key, const std::string &path)
    {
        if (m_textures.find(key) != m_textures.end()) {
            m_logger->warning("loadFromFile: " + key + " already exists");
            return false;
        }

        auto texture = std::make_unique<sf::Texture>();
        if (!texture->loadFromFile(path)) {
            m_logger->warning("loadFromFile: " + path + " unable to load");
            return false;
        }
        texture->setSmooth(m_smoothing);
        m_textures.insert({key, std::move(texture)});
        m_logger->info("loadFromFile: " + key + ": " + path + " loaded");
        return true;
    }

    bool TextureLoader::remove(const std::string &key)
    {
        const auto found = m_textures.find(key);

        if (found == m_textures.end()) {
            m_logger->warning("remove: " + key + " not found");
            return false;
        }
        m_textures.erase(found);
        return true;
    }

    void TextureLoader::clear()
    {
        m_logger->info("clear: " + std::to_string(m_textures.size()) + " textures cleared");
        m_textures.clear();
    }

    sf::Texture *TextureLoader::getTexture(const std::string &key) const
    {
        const auto found = m_textures.find(key);

        if (found != m_textures.end())
            return found->second.get();
        return nullptr;
    }
}// namespace sfge::resources