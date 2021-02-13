#include "sfge/components/ascript.h"

#include <iostream>

namespace sfge::ecs
{
    void AScript::attachGameObject(AGameObject *gameObject)
    {
        m_gameObject = gameObject;
    }

    void AScript::onKeyboardEvent(const input::KeyboardEvent &event)
    {
        std::clog << "on kbd event ascript" << std::endl;
    }

    void AScript::onMouseButtonEvent(const input::MouseButtonEvent &event)
    {
        std::clog << "on mouse event ascript" << std::endl;
    }
}// namespace sfge::ecs