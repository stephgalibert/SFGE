#include "ecge/components/scriptable.h"

#include "ecge/components/ascript.h"

namespace ecge::ecs
{
    void Scriptable::addScript(std::unique_ptr<AScript> script)
    {
        m_scripts.push_back(std::move(script));
    }

    void Scriptable::removeScript()
    {
        // TODO: ...
    }
}// namespace ecge::ecs
