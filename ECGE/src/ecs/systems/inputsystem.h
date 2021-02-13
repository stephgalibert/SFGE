#pragma once

#include "isystem.hpp"

#include "ecge/event.h"

#include <SFML/Window/Keyboard.hpp>

#include <queue>

namespace ecge::ecs
{
    class InputSystem : public ISystem
    {
    public:
        void update(entt::registry &registry, float dt) override;

        void push(const input::KeyboardEvent &event);
        void push(const input::MouseButtonEvent &event);

    private:
        std::queue<input::KeyboardEvent> m_keyboardEvents;
    };
}// namespace ecge::ecs
