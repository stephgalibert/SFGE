#include "rendererconfiguration.h"

namespace ecge::config
{
    std::unordered_map<std::string, std::string> RendererConfiguration::GetDefault()
    {
        return {{{"Width"}, {"1920"}},
                {{"Height"}, {"1080"}},
                {{"Antialiasing"}, {"8"}}};
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
        return {{"Width"},
                {"Height"},
                {"Antialiasing"}};
    }

    void RendererConfiguration::set(const std::string &key, const std::string &value)
    {
        m_values[key] = value;
    }

    void RendererConfiguration::reset()
    {
        m_values = GetDefault();
    }

}// namespace ecge::config
