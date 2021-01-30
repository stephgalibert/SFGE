#pragma once

#include "isystem.hpp"

#include <SFML/Graphics.hpp>

namespace ecge
{
    class RenderSystem : public ISystem
    {
    public:
        RenderSystem();
        void setRenderTarget(sf::RenderTarget *target);
        void update(entt::registry &registry, float dt) override;

    private:
        sf::RenderTarget *m_renderTarget = nullptr;
        sf::View m_view;
    };
}// namespace ecge
