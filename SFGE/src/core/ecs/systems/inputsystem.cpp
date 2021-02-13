#include "inputsystem.hpp"

#include "sfge/components/input.hpp"
#include "sfge/components/scriptable.hpp"

namespace sfge::ecs
{
    void InputSystem::update(entt::registry &registry, float dt)
    {
        auto view = registry.view<Input, Scriptable>();
        for (const auto entity : view) {
            const auto [input, scriptable] = view.get<Input, Scriptable>(entity);

            if (input.getMouseMove()) {
            }
            if (input.getMouseButton()) {
            }

            while (input.getKeyboardButton() && !m_keyboardEvents.empty()) {
                const input::KeyboardEvent &event = m_keyboardEvents.front();
                scriptable.onKeyboardEvent(event);
                m_keyboardEvents.pop();
            }
        }
    }

    void InputSystem::push(const input::KeyboardEvent &event)
    {
        m_keyboardEvents.push(event);
    }

    void InputSystem::push(const input::MouseButtonEvent &event)
    {
    }
}// namespace sfge::ecs