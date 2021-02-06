#include "rendersystem.hpp"

#include "ecge/components/renderable.hpp"
#include "ecge/components/transformable.hpp"

namespace ecge::ecs
{
    RenderSystem::RenderSystem()
    {
        m_view.setSize(1280, 720);
        m_view.setCenter(0, 0);
    }

    void RenderSystem::setRenderTarget(sf::RenderTarget *target)
    {
        m_renderTarget = target;
        m_renderTarget->setView(m_view);
    }

    void RenderSystem::update(entt::registry &registry, float dt)
    {
        auto view = registry.view<const ecs::Renderable>();
        for (const auto entity : view) {
            const auto &r = view.get<const ecs::Renderable>(entity);
            m_renderTarget->draw(*r.shape());
        }
    }
}// namespace ecge::ecs
