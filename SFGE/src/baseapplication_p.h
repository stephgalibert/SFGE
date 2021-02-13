#pragma once

#include "sfge/baseapplication.hpp"

#include <SFML/Graphics.hpp>

namespace sfge
{
    namespace input
    {
        class EventProcessor;
    }
    class SceneManager;

    class BaseApplicationPrivate
    {
    public:
    private:
        explicit BaseApplicationPrivate(BaseApplication *qq);
        PIMPL_DECLARE_PUBLIC(BaseApplication);

        std::unique_ptr<SceneManager> m_sceneManager;
        std::unique_ptr<input::EventProcessor> m_eventProcessor;
        sf::RenderWindow m_window;
    };
}// namespace sfge