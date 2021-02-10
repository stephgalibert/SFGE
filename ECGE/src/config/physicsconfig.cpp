#include "physicsconfig.h"

namespace ecge::config
{
    std::string Physics::KeyToString(Key key)
    {
        static const std::unordered_map<Key, std::string> map = {
                {{Key::PixelsPerMeter}, {"PixelsPerMeter"}}};
        return map.at(key);
    }

    const auto &Physics::GetDefault()
    {
        static const std::unordered_map<std::string, std::string> values = {
                {{KeyToString(Key::PixelsPerMeter)}, {"50"}}};
        return values;
    }

    Physics::Physics()
    {
        reset();
    }

    std::string Physics::getName() const
    {
        return "Physics";
    }

    const std::unordered_map<std::string, std::string> &Physics::getKeysValues() const
    {
        return m_values;
    }

    void Physics::setValue(const std::string &key, const std::string &value)
    {
        m_values[key] = value;
    }

    void Physics::reset()
    {
        m_values = GetDefault();
    }

    std::string Physics::getValue(Key key) const
    {
        return m_values.at(KeyToString(key));
    }

    void Physics::setValue(Key key, int value)
    {
        setValue(KeyToString(key), std::to_string(value));
    }

    void Physics::setValue(Key key, float value)
    {
        setValue(KeyToString(key), std::to_string(value));
    }

    void Physics::setValue(Key key, const std::string &value)
    {
        setValue(KeyToString(key), value);
    }
}// namespace ecge::config
