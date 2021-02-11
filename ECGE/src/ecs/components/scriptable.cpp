#include "ecge/components/scriptable.h"

namespace ecge::ecs
{
    Scriptable::Scriptable(const Scriptable &rhs)
        : Component(rhs)
    {
        *this = rhs;
    }

    Scriptable::Scriptable(Scriptable &&rhs) noexcept
        : Component(std::move(rhs))
    {
        *this = std::move(rhs);// pu du q
    }

    Scriptable::~Scriptable()
    {
        for (const auto &script : m_scripts) {
            script->onDestroy();
        }
    }

    Scriptable &Scriptable::operator=(const Scriptable &rhs)
    {
        return *this;
    }
    Scriptable &Scriptable::operator=(Scriptable &&rhs) noexcept
    {
        return *this;
    }

    void Scriptable::addScript(std::unique_ptr<AScript> script)
    {
        m_scripts.push_back(std::move(script));
    }

    void Scriptable::update(float dt)
    {
        for (const auto &script : m_scripts) {
            script->onUpdate(dt);
        }
    }

}// namespace ecge::ecs
