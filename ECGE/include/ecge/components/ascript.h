#pragma once

namespace ecge
{
    class AGameObject;
}

namespace ecge::ecs
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

    protected:
        AGameObject *m_gameObject = nullptr;
        // agameobject?
    };
}// namespace ecge::ecs