#include "ecge/components/scriptable.h"

namespace ecge::ecs
{
    Scriptable::~Scriptable()
    {
        destroy();
    }

    void Scriptable::update(float dt)
    {
        for (const auto &script : m_scripts) {
            script->onUpdate(dt);
        }
    }

    void Scriptable::destroy()
    {
        for (const auto &script : m_scripts) {
            script->onDestroy();
        }
    }

    void Scriptable::onKeyboardEvent(const input::KeyboardEvent &event)
    {
        for (auto &script : m_scripts) {
            script->onKeyboardEvent(event);
        }
    }

    void Scriptable::onMouseButtonEvent(const input::MouseButtonEvent &event)
    {
        for (auto &script : m_scripts) {
            script->onMouseButtonEvent(event);
        }
    }
}// namespace ecge::ecs
