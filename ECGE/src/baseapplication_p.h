#pragma once

#include "ecge/baseapplication.hpp"

#include <SFML/Graphics.hpp>

namespace ecge
{
    class EventProcessor;
    class SceneManager;

    class BaseApplicationPrivate
    {
    public:
    private:
        explicit BaseApplicationPrivate(BaseApplication *qq);
        PIMPL_DECLARE_PUBLIC(BaseApplication);

        std::unique_ptr<SceneManager> m_sceneManager;
        std::unique_ptr<EventProcessor> m_eventProcessor;
        sf::RenderWindow m_window;
    };
}// namespace ecge