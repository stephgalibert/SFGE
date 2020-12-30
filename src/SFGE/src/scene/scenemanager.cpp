#include "scenemanager.hpp"

#include "sfge/ascene.hpp"

#include <iostream>

namespace sfge
{
    void SceneManager::setRenderTarget(sf::RenderTarget& target)
    {
        m_renderTarget = &target;
        if (m_currentScene)
            m_currentScene->setRenderTarget(m_renderTarget);
    }

    void SceneManager::onWindowClosing()
    {
        m_currentScene->stop();
    }

    void SceneManager::onKeyboardEvent(sf::Keyboard::Key key, bool pressed)
    {
        m_currentScene->onKeyboardEvent(key, pressed);
    }

    void SceneManager::onMouseButtonEvent(sf::Mouse::Button btn, int x, int y, bool pressed)
    {
        m_currentScene->onMouseButtonEvent(btn, x, y, pressed);
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
}