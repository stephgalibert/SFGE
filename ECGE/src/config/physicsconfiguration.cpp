#include "physicsconfiguration.h"

namespace ecge::config
{
    std::string PhysicsConfiguration::getName() const
    {
        return std::string();
    }

    std::vector<std::string> PhysicsConfiguration::getKeys() const
    {
        return std::vector<std::string>();
    }

    std::string PhysicsConfiguration::getValue(const std::string &key) const
    {
        return std::string();
    }

    void PhysicsConfiguration::set(const std::string &key, const std::string &value)
    {
    }

    void PhysicsConfiguration::reset()
    {
    }
}// namespace ecge::config
