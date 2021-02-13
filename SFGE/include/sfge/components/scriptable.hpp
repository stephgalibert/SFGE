#pragma once

#include "component.hpp"

#include "sfge/components/ascript.hpp"

#include <memory>
#include <vector>

namespace sfge::input
{
    struct KeyboardEvent;
    struct MouseButtonEvent;
}// namespace sfge::input

namespace sfge::ecs
{
    class Scriptable : public Component
    {
    public:
        Scriptable() = default;
        Scriptable(const Scriptable &rhs) = default;
        Scriptable(Scriptable &&rhs) noexcept = default;
        ~Scriptable();

        Scriptable &operator=(const Scriptable &rhs) = default;
        Scriptable &operator=(Scriptable &&rhs) noexcept = default;

        void update(float dt);
        void destroy();

        void onKeyboardEvent(const input::KeyboardEvent &event);
        void onMouseButtonEvent(const input::MouseButtonEvent &event);

    public:
        template<typename T>
        decltype(auto) addScript();

        template<typename T>
        void removeScript();

    private:
        std::vector<std::unique_ptr<AScript>> m_scripts;
    };
}// namespace sfge::ecs

#include "scriptable.inl"
