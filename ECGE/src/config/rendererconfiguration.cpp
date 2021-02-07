#include "rendererconfiguration.h"

namespace ecge::config
{
    std::string RendererConfiguration::KeyToString(Key key)
    {
        static const std::unordered_map<Key, std::string> map = {
                {{Key::Width}, {"Width"}},
                {{Key::Height}, {"Height"}},
                {{Key::AntiAliasing}, {"AntiAliasing"}}};
        return map.at(key);
    }

    std::unordered_map<std::string, std::string> RendererConfiguration::GetDefault()
    {
        return {{{KeyToString(Key::Width)}, {"1920"}},
                {{KeyToString(Key::Height)}, {"1080"}},
                {{KeyToString(Key::AntiAliasing)}, {"8"}}};
    }

    RendererConfiguration::RendererConfiguration()
    {
        reset();
    }

    std::string RendererConfiguration::getName() const
    {
        return "Renderer";
    }

    std::string RendererConfiguration::getValue(const std::string &key) const
    {
        return m_values.at(key);
    }

    std::vector<std::string> RendererConfiguration::getKeys() const
    {
        return {{KeyToString(Key::Width)},
                {KeyToString(Key::Height)},
                {KeyToString(Key::AntiAliasing)}};
    }

    void RendererConfiguration::set(const std::string &key, const std::string &value)
    {
        m_values[key] = value;
    }

    void RendererConfiguration::reset()
    {
        m_values = GetDefault();
    }

    std::string RendererConfiguration::getValue(Key key) const
    {
        return m_values.at(KeyToString(key));
    }

    void RendererConfiguration::setValue(RendererConfiguration::Key key, const std::string &value)
    {
        set(KeyToString(key), value);
    }
}// namespace ecge::config
