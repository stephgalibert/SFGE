#pragma once

#include "input/eventlistener.hpp"

#include <SFML/Graphics.hpp>

#include <memory>

namespace ecge
{
    class AScene;

    class SceneManager : public EventListener
    {
    public:
        void setRenderTarget(sf::RenderTarget &target);

        void onWindowClosing() override;
        void onKeyboardEvent(sf::Keyboard::Key key, bool pressed) override;
        void onMouseButtonEvent(sf::Mouse::Button btn, int x, int y, bool pressed) override;

        void update(float dt);
        void draw();

        void setScene(std::unique_ptr<AScene> scene);
        [[nodiscard]] const std::unique_ptr<AScene> &scene() const;

    private:
        std::unique_ptr<AScene> m_currentScene;
        sf::RenderTarget *m_renderTarget = nullptr;
    };
}// namespace ecge