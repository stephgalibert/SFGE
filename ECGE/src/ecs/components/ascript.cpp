#include "ecge/components/ascript.h"

namespace ecge::ecs
{
    void AScript::attachGameObject(AGameObject *gameObject)
    {
        m_gameObject = gameObject;
    }
}// namespace ecge::ecs