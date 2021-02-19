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
#include "textureloader_p.hpp"

#include "services/iconfigurationmanagerservice.h"
#include "sfge/services/iloggerservice.hpp"
#include "sfge/services/servicelocator.hpp"

#include <cassert>

namespace sfge::resources
{
    TextureLoaderPrivate::TextureLoaderPrivate(TextureLoader *qq)
        : q_ptr(qq)
    {
    }

    TextureLoader::TextureLoader()
        : TextureLoader(new TextureLoaderPrivate(this))
    {
    }

    TextureLoader::~TextureLoader()
    {
    }

    TextureLoader::TextureLoader(TextureLoaderPrivate *dd)
        : d_ptr(dd)
    {
    }

    bool TextureLoader::init()
    {
        PIMPL_D(TextureLoader);

        auto loggerService = services::ServiceLocator::Get<services::ILoggerService>();
        d->m_logger = loggerService->createLogger("TextureLoader");

        const auto config = services::ServiceLocator::Get<services::IConfigurationManagerService>();
        const auto globalConfig = config->getGlobal();

        d->m_logger->addLoggingFile(globalConfig->getValue(config::Global::Key::LoggingFile));

        const auto renderConfig = config->getRenderer();
        d->m_smoothing = renderConfig->getValue<bool>(config::Renderer::Key::TextureSmooth);
        d->m_logger->info("Smoothing=" + std::to_string(d->m_smoothing));
        return false;
    }

    bool TextureLoader::load(const std::string &key, const std::string &path)
    {
        PIMPL_D(TextureLoader);
        assert(d->m_logger != nullptr);

        if (d->m_textures.find(key) != d->m_textures.end()) {
            d->m_logger->warning(key + " already exists");
            return false;
        }

        auto texture = std::make_unique<sf::Texture>();
        if (!texture->loadFromFile(path)) {
            d->m_logger->warning(path + " unable to load");
            return false;
        }
        texture->setSmooth(d->m_smoothing);
        d->m_textures.insert({key, std::move(texture)});
        d->m_logger->info(key + ": " + path + " loaded");
        return true;
    }

    sf::Texture *TextureLoader::getTexture(const std::string &key) const
    {
        const PIMPL_D(TextureLoader);

        const auto found = d->m_textures.find(key);
        assert(found != d->m_textures.end());
        return found->second.get();
    }

    void TextureLoader::clear()
    {
        PIMPL_D(TextureLoader);

        d->m_logger->info(std::to_string(d->m_textures.size()) + " textures cleared");
        d->m_textures.clear();
    }
}// namespace sfge::resources