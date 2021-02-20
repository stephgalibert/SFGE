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

#include "mainrenderer.hpp"

#include "config/rendererconfig.hpp"
#include "services/iconfigurationmanagerservice.h"
#include "sfge/services/servicelocator.hpp"

#include <memory>

namespace sfge::renderer
{
    bool sfge::renderer::MainRenderer::init()
    {
        auto config = services::ServiceLocator::Get<services::IConfigurationManagerService>();

        std::shared_ptr<config::Renderer> rendererConfig = config->getRenderer();
        const int width = rendererConfig->getValue<int>(config::Renderer::Key::Width);
        const int height = rendererConfig->getValue<int>(config::Renderer::Key::Height);
        const int maxFps = rendererConfig->getValue<int>(config::Renderer::Key::MaxFps);
        const bool vsync = rendererConfig->getValue<bool>(config::Renderer::Key::VSync);

        m_window = std::make_unique<sf::RenderWindow>();
        m_window->create(sf::VideoMode(width, height), "SFML works!");
        m_window->setFramerateLimit(maxFps);
        m_window->setVerticalSyncEnabled(vsync);
        return true;
    }

    std::unique_ptr<sf::RenderWindow> &MainRenderer::renderer()
    {
        return m_window;
    }
}// namespace sfge::renderer
