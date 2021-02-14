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

#include "sfge/resources/textureloader.hpp"
#include "textureloader_p.hpp"

namespace sfge::resource
{
    TextureLoaderPrivate::TextureLoaderPrivate(TextureLoader *qq)
        : q_ptr(qq)
    {
        m_logger = Logger::CreateLogger("TextureLoader");

        std::shared_ptr<config::Global> globalConfig = config::ConfigurationManager::getInstance().getGlobal();
        m_logger->addLoggingFile(globalConfig->getValue(config::Global::Key::LoggingFile));

        std::shared_ptr<config::Renderer> renderConfig = config::ConfigurationManager::getInstance().getRenderer();
        m_smoothing = renderConfig->getValue<bool>(config::Renderer::Key::TextureSmooth);
        m_logger->info("Smoothing=" + std::to_string(m_smoothing));
    }

    TextureLoader::TextureLoader()
        : TextureLoader(new TextureLoaderPrivate(this))
    {
    }

    TextureLoader::TextureLoader(TextureLoaderPrivate *dd)
        : d_ptr(dd)
    {
    }

    TextureLoader &TextureLoader::GetInstance()
    {
        static TextureLoader instance;
        return instance;
    }

    bool TextureLoader::load(const std::string &key, const std::string &path)
    {
        PIMPL_D(TextureLoader);

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
        return found->second.get();
    }

    void TextureLoader::clear()
    {
        PIMPL_D(TextureLoader);

        d->m_logger->info(std::to_string(d->m_textures.size()) + " textures cleared");
        d->m_textures.clear();
    }
}// namespace sfge::resource