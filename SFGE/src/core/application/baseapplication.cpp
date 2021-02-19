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

#include "sfge/baseapplication.hpp"
#include "baseapplication_p.hpp"

#include "sfge/scene/ascene.hpp"
#include "sfge/services/iloggerservice.hpp"
#include "sfge/services/itextureloaderservice.h"
#include "sfge/services/servicelocator.hpp"

#include "config/configurationmanager.hpp"
#include "config/rendererconfig.hpp"
#include "core/input/eventprocessor.hpp"
#include "core/renderer/mainrenderer.hpp"
#include "core/resources/textureloader.hpp"
#include "core/scene/scenemanager.hpp"

#include "services/iconfigurationmanagerservice.h"

#include <SFML/Graphics.hpp>
#include <iostream>

namespace sfge
{
    BaseApplicationPrivate::BaseApplicationPrivate(BaseApplication *qq)
        : q_ptr(qq),
          m_sceneManager(new SceneManager),
          m_eventProcessor(new input::EventProcessor(m_sceneManager.get()))
    {
    }

    BaseApplication::BaseApplication()
        : BaseApplication(new BaseApplicationPrivate(this))
    {
    }

    BaseApplication::BaseApplication(BaseApplicationPrivate *dd)
        : d_ptr(dd)
    {
    }

    BaseApplication::~BaseApplication()
    {
    }

    bool BaseApplication::init()
    {
        loadServices();
        return true;
    }

    int32_t BaseApplication::run()
    {
        if (!isRunnable())
            return -1;

        auto mainRenderer = services::ServiceLocator::Get<services::IMainRendererService>();
        std::unique_ptr<sf::RenderWindow> &window = mainRenderer->mainRenderer();

        sf::Clock clock;
        PIMPL_D(BaseApplication);
        while (window->isOpen()) {
            float dt = clock.restart().asSeconds();

            // 1. Retrieve and process input(s)
            sf::Event event{};
            while (window->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window->close();
                d->m_eventProcessor->process(event);
            }

            // 2. Update logics
            d->m_sceneManager->update(dt);

            // 3. Draw
            window->clear();
            d->m_sceneManager->draw();
            window->display();
        }
        return 0;
    }

    void BaseApplication::loadScene(std::unique_ptr<AScene> scene)
    {
        PIMPL_D(BaseApplication);
        d->m_sceneManager->setScene(std::move(scene));
    }

    bool BaseApplication::isRunnable() const
    {
        const PIMPL_D(BaseApplication);
        if (!d->m_sceneManager->scene()) {
            std::cerr << "There is no active scene. Terminating application." << std::endl;
            return false;
        }
        return true;
    }

    void BaseApplication::loadServices()
    {
        services::ServiceLocator::Provide<services::ILoggerService, Logger>();
        auto configManager = services::ServiceLocator::Provide<services::IConfigurationManagerService, config::ConfigurationManager>();
        auto mainRenderer = services::ServiceLocator::Provide<services::IMainRendererService, renderer::MainRenderer>();
        auto textureLoader = services::ServiceLocator::Provide<services::ITextureLoaderService, resources::TextureLoader>();

        configManager->load();
        mainRenderer->init();
        textureLoader->init();
    }
}// namespace sfge