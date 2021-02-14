#pragma once

#include "sfge/components/transformable.hpp"
#include "sfge/pimpl.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <entt/entt.hpp>

#include <box2d/b2_body.h>
#include <memory>
#include <sfge/components/rigidbody.hpp>

namespace sfge
{
    namespace input
    {
        struct KeyboardEvent;
        struct MouseButtonEvent;
    }// namespace input

    class AScenePrivate;
    class AGameObject;

    class AScene
    {
    public:
        AScene();
        virtual ~AScene();

        virtual void init();

        void setRenderTarget(sf::RenderTarget *target);

        void destroy();
        void onKeyboardEvent(const input::KeyboardEvent &event);
        void onMouseButtonEvent(const input::MouseButtonEvent &event);

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
}// namespace sfge

#include "ascene.inl"