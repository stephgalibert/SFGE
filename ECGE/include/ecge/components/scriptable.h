#pragma once

#include "component.hpp"

#include "ecge/components/ascript.h"

#include <memory>
#include <vector>

namespace ecge::ecs
{
    class Scriptable : public Component
    {
    public:
        Scriptable() = default;
        Scriptable(const Scriptable &rhs);
        Scriptable(Scriptable &&rhs) noexcept;
        ~Scriptable();

        Scriptable &operator=(const Scriptable &rhs);
        Scriptable &operator=(Scriptable &&rhs) noexcept;

        void addScript(std::unique_ptr<AScript> script);

        template<typename T>
        void removeScript()
        {
            m_scripts.erase(
                    std::remove_if(m_scripts.begin(), m_scripts.end(),
                                   [&](const auto &script) {
                                       if (typeid(T) == typeid(*script)) {
                                           script->onDestroy();
                                           return true;
                                       }
                                       return false;
                                   }),
                    m_scripts.end());
        }

        void update(float dt);

    private:
        std::vector<std::unique_ptr<AScript>> m_scripts;
    };
}// namespace ecge::ecs
