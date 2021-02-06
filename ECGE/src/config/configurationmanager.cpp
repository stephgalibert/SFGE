#include "configurationmanager.h"

#include "rendererconfiguration.h"

#include "inifile.h"

namespace ecge::config
{
    ConfigurationManager::ConfigurationManager()
        : m_path("config.ini")
    {
        m_configurations.push_back(std::make_unique<RendererConfiguration>());
    }

    void ConfigurationManager::load()
    {
        IniFile iniFile;

        const bool loadSuccess = iniFile.parse(m_path);
        if (loadSuccess) {
            for (const std::unique_ptr<IConfiguration> &config : m_configurations) {
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
        IniFile iniFile;

        for (const std::unique_ptr<IConfiguration> &config : m_configurations) {
            for (const auto &key : config->getKeys()) {
                const auto value = config->getValue(key);
                iniFile.put(config->getName() + "." + key, value);
            }
        }
        iniFile.write(m_path);
    }
}// namespace ecge::config