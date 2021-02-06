#include "configurationmanager.h"

#include "rendererconfiguration.h"

#include "iniconfig.h"

namespace ecge::config
{
    ConfigurationManager::ConfigurationManager()
        : m_path("config.ini")
    {
        m_rendererConfig = std::make_shared<RendererConfiguration>();

        m_configurations.push_back(m_rendererConfig);
    }

    void ConfigurationManager::load()
    {
        IniConfig iniFile;

        const bool success = iniFile.parse(m_path);
        if (success) {
            for (const auto &config : m_configurations) {
                for (const std::string &key : config->getKeys()) {
                    const auto value = iniFile.get<std::string>(config->getName() + "." + key);
                    config->set(key, value);
                }
            }
        } else {
            // No able to parse the configuration file,
            // Save default.
            save();
        }
    }

    void ConfigurationManager::save()
    {
        IniConfig iniConfig;

        for (const auto &config : m_configurations) {
            for (const auto &key : config->getKeys()) {
                const auto value = config->getValue(key);
                iniConfig.put(config->getName() + "." + key, value);
            }
        }
        iniConfig.write(m_path);
    }

    std::shared_ptr<RendererConfiguration> ConfigurationManager::getRendererConfig() const
    {
        return m_rendererConfig;
    }
}// namespace ecge::config