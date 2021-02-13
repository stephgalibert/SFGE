#pragma once

#include "isystem.hpp"

#include "sfge/event.h"

#include <SFML/Window/Keyboard.hpp>

#include <queue>

namespace sfge::ecs
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
}// namespace sfge::ecs
