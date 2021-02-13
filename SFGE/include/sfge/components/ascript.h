#pragma once

namespace sfge
{
    class AGameObject;

    namespace input
    {
        struct KeyboardEvent;
        struct MouseButtonEvent;
    }// namespace input
}// namespace sfge

namespace sfge::ecs
{
    class AScript
    {
    public:
        virtual ~AScript() = default;

        // onCollision[...]()
        // onMouse[...]()
        void attachGameObject(AGameObject *gameObject);

        virtual void onAwake() = 0;
        virtual void onUpdate(float dt) = 0;
        virtual void onDestroy() = 0;

        virtual void onKeyboardEvent(const input::KeyboardEvent &event);
        virtual void onMouseButtonEvent(const input::MouseButtonEvent &event);

    protected:
        AGameObject *m_gameObject = nullptr;
    };
}// namespace sfge::ecs