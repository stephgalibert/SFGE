#include "scenemanager.hpp"

#include "sfge/ascene.hpp"

#include <iostream>

namespace sfge
{
    void SceneManager::setRenderTarget(sf::RenderTarget &target)
    {
        m_renderTarget = &target;
        if (m_currentScene)
            m_currentScene->setRenderTarget(m_renderTarget);
    }

    void SceneManager::onWindowClosing()
    {
        m_currentScene->destroy();
    }

    void SceneManager::onKeyboardEvent(const input::KeyboardEvent &event)
    {
        m_currentScene->onKeyboardEvent(event);
    }

    void SceneManager::onMouseButtonEvent(const input::MouseButtonEvent &event)
    {
        m_currentScene->onMouseButtonEvent(event);
    }

    void SceneManager::update(float dt)
    {
        m_currentScene->update(dt);
    }

    void SceneManager::draw()
    {
        m_currentScene->draw();
    }

    void SceneManager::setScene(std::unique_ptr<AScene> scene)
    {
        // TODO: push into a build queue and only then, set m_currentScene
        m_currentScene = std::move(scene);
        m_currentScene->init();
        m_currentScene->setRenderTarget(m_renderTarget);
    }

    const std::unique_ptr<AScene> &SceneManager::scene() const
    {
        return m_currentScene;
    }
}// namespace sfge