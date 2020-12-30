#include "sfge/baseapplication.hpp"
#include "baseapplication_p.h"

#include "input/eventprocessor.hpp"
#include "scene/scenemanager.hpp"
#include "sfge/ascene.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

namespace sfge
{
    BaseApplicationPrivate::BaseApplicationPrivate(BaseApplication *qq)
        : q_ptr(qq),
          m_sceneManager(new SceneManager),
          m_eventProcessor(new EventProcessor(m_sceneManager.get()))
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
        // TODO: user config
        PIMPL_D(BaseApplication);
        d->m_window.create(sf::VideoMode(200, 200), "SFML works!");
        d->m_window.setFramerateLimit(60);
        d->m_window.setVerticalSyncEnabled(true);

        d->m_sceneManager->setRenderTarget(d->m_window);
        return true;
    }

    int32_t BaseApplication::run()
	{
        if (!isRunnable())
            return -1;

        sf::Clock clock;
        PIMPL_D(BaseApplication);
        while (d->m_window.isOpen())
        {
            float dt = clock.restart().asSeconds();

            // 1. Retrieve and process input(s)
            sf::Event event{};
            while (d->m_window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    d->m_window.close();
                d->m_eventProcessor->process(event);
            }

            // 2. Update logics
            d->m_sceneManager->update(dt);

            // 3. Draw
            d->m_window.clear();
            d->m_sceneManager->draw();
            d->m_window.display();
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
}