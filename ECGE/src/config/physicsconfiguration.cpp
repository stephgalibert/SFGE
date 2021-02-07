#include "physicsconfiguration.h"

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

    std::vector<std::string> Physics::getKeys() const
    {
        return {{KeyToString(Key::PixelsPerMeter)}};
    }

    std::string Physics::getValue(const std::string &key) const
    {
        return m_values.at(key);
    }

    void Physics::set(const std::string &key, const std::string &value)
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
        set(KeyToString(key), std::to_string(value));
    }

    void Physics::setValue(Key key, float value)
    {
        set(KeyToString(key), std::to_string(value));
    }

    void Physics::setValue(Key key, const std::string &value)
    {
        set(KeyToString(key), value);
    }
}// namespace ecge::config
