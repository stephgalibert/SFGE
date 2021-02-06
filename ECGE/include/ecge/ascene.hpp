#pragma once

#include "ecge/components/transformable.hpp"
#include "ecge/pimpl.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <entt/entt.hpp>

#include <memory>

namespace ecge
{
    class AScenePrivate;
    class AGameObject;

    class AScene
    {
    public:
        AScene();
        virtual ~AScene();

        virtual void init();

        void setRenderTarget(sf::RenderTarget *target);

        void stop();
        void onKeyboardEvent(sf::Keyboard::Key key, bool pressed);
        void onMouseButtonEvent(sf::Mouse::Button btn, int x, int y, bool pressed);

        void update(float dt);
        void draw();

    public:
        template<typename T, typename... Args>
        std::shared_ptr<T> instantiate(Args &&... args);

    private:
        explicit AScene(AScenePrivate *dd);
        PIMPL_DECLARE_PRIVATE(AScene);
        void addGameObject(const std::shared_ptr<AGameObject> &obj);
    };
}// namespace ecge

#include "ascene.inl"