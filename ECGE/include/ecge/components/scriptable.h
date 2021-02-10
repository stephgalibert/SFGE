#pragma once

#include "component.hpp"

#include <memory>
#include <vector>

namespace ecge::ecs
{
    class AScript;

    class Scriptable : public Component
    {
    public:
        void addScript(std::unique_ptr<AScript> script);
        void removeScript();

    private:
        std::vector<std::unique_ptr<AScript>> m_scripts;
    };
}// namespace ecge::ecs
