#include "rendererconfiguration.h"

namespace ecge::config
{
    std::string Renderer::KeyToString(Key key)
    {
        static const std::unordered_map<Key, std::string> map = {
                {{Key::Width}, {"Width"}},
                {{Key::Height}, {"Height"}},
                {{Key::AntiAliasing}, {"AntiAliasing"}},
                {{Key::MaxFps}, {"MaxFps"}},
                {{Key::VSync}, {"VSync"}}};
        return map.at(key);
    }

    const auto &Renderer::GetDefault()
    {
        static const std::unordered_map<std::string, std::string> values = {
                {{KeyToString(Key::Width)}, {"1280"}},
                {{KeyToString(Key::Height)}, {"720"}},
                {{KeyToString(Key::AntiAliasing)}, {"8"}},
                {{KeyToString(Key::MaxFps)}, {"60"}},
                {{KeyToString(Key::VSync)}, {"1"}}};
        return values;
    }

    Renderer::Renderer()
    {
        reset();
    }

    std::string Renderer::getName() const
    {
        return "Renderer";
    }

    std::string Renderer::getValue(const std::string &key) const
    {
        return m_values.at(key);
    }

    std::vector<std::string> Renderer::getKeys() const
    {
        return {{KeyToString(Key::Width)},
                {KeyToString(Key::Height)},
                {KeyToString(Key::AntiAliasing)},
                {KeyToString(Key::MaxFps)},
                {KeyToString(Key::VSync)}};
    }

    void Renderer::set(const std::string &key, const std::string &value)
    {
        m_values[key] = value;
    }

    void Renderer::reset()
    {
        m_values = GetDefault();
    }

    std::string Renderer::getValue(Key key) const
    {
        return m_values.at(KeyToString(key));
    }

    void Renderer::setValue(Key key, int value)
    {
        set(KeyToString(key), std::to_string(value));
    }

    void Renderer::setValue(Key key, float value)
    {
        set(KeyToString(key), std::to_string(value));
    }

    void Renderer::setValue(Key key, const std::string &value)
    {
        set(KeyToString(key), value);
    }
}// namespace ecge::config
