#include "physicsconfiguration.h"

namespace ecge::config
{
    std::string PhysicsConfiguration::KeyToString(Key key)
    {
        static const std::unordered_map<Key, std::string> map = {
                {{Key::PixelsPerMeter}, {"PixelsPerMeter"}}};
        return map.at(key);
    }

    std::unordered_map<std::string, std::string> PhysicsConfiguration::GetDefault()
    {
        return {{{KeyToString(Key::PixelsPerMeter)}, {"50"}}};
    }

    PhysicsConfiguration::PhysicsConfiguration()
    {
        reset();
    }

    std::string PhysicsConfiguration::getName() const
    {
        return "Physics";
    }

    std::vector<std::string> PhysicsConfiguration::getKeys() const
    {
        return {{KeyToString(Key::PixelsPerMeter)}};
    }

    std::string PhysicsConfiguration::getValue(const std::string &key) const
    {
        return m_values.at(key);
    }

    void PhysicsConfiguration::set(const std::string &key, const std::string &value)
    {
        m_values[key] = value;
    }

    void PhysicsConfiguration::reset()
    {
        m_values = GetDefault();
    }

    std::string PhysicsConfiguration::getValue(Key key) const
    {
        return m_values.at(KeyToString(key));
    }

    void PhysicsConfiguration::setValue(Key key, const std::string &value)
    {
        set(KeyToString(key), value);
    }
}// namespace ecge::config
