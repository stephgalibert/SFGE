#include "configurationmanager.h"

#include "rendererconfiguration.h"

#include "iniconfig.h"

namespace ecge::config
{
    ConfigurationManager::ConfigurationManager()
        : m_path("config.ini")
    {
        m_logger = Logger::CreateLogger("ConfigurationManager");
        m_logger->addLoggingFile("logs/log.txt");

        m_rendererConfig = std::make_shared<RendererConfiguration>();

        m_configurations.push_back(m_rendererConfig);
    }

    ConfigurationManager::~ConfigurationManager()
    {
        Logger::RemoveLogger("ConfigurationManager");
    }

    void ConfigurationManager::load()
    {
        IniConfig iniFile;

        const bool success = iniFile.parse(m_path);
        if (success) {
            m_logger->info("Using configuration");
            for (const auto &config : m_configurations) {
                for (const std::string &key : config->getKeys()) {
                    const std::string path = config->getName() + "." + key;
                    const auto value = iniFile.get<std::string>(path);
                    m_logger->info(path + ": " + value);
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
        m_logger->info("Saving configuration");
        for (const auto &config : m_configurations) {
            for (const auto &key : config->getKeys()) {
                const std::string path = config->getName() + "." + key;
                const auto value = config->getValue(key);
                m_logger->info(path + ": " + value);
                iniConfig.put(path, value);
            }
        }
        iniConfig.write(m_path);
    }

    std::shared_ptr<RendererConfiguration> ConfigurationManager::getRendererConfig() const
    {
        return m_rendererConfig;
    }
}// namespace ecge::config