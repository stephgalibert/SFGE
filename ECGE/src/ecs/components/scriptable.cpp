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

}// namespace ecge::ecs
