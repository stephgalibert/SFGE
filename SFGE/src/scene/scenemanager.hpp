#pragma once

#include "input/eventlistener.hpp"

#include <SFML/Graphics.hpp>

#include <memory>

namespace sfge
{
    class AScene;

    class SceneManager : public input::EventListener
    {
    public:
        void setRenderTarget(sf::RenderTarget &target);

        void onWindowClosing() override;
        void onKeyboardEvent(const input::KeyboardEvent &event) override;
        void onMouseButtonEvent(const input::MouseButtonEvent &event) override;

        void update(float dt);
        void draw();

        void setScene(std::unique_ptr<AScene> scene);
        [[nodiscard]] const std::unique_ptr<AScene> &scene() const;

    private:
        std::unique_ptr<AScene> m_currentScene;
        sf::RenderTarget *m_renderTarget = nullptr;
    };
}// namespace sfge