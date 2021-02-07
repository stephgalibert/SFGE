#include "configurationmanager.h"

#include "physicsconfiguration.h"
#include "rendererconfiguration.h"

#include "iniconfig.h"

namespace ecge::config
{
    ConfigurationManager::ConfigurationManager()
        : m_path("config.ini")
    {
        m_logger = Logger::CreateLogger("ConfigurationManager");
        m_logger->addLoggingFile("logs/log.txt");

        m_rendererConfig = std::make_shared<Renderer>();
        m_physicsConfig = std::make_shared<Physics>();

        m_configurations.push_back(m_rendererConfig);
        m_configurations.push_back(m_physicsConfig);
    }

    ConfigurationManager::~ConfigurationManager()
    {
        Logger::RemoveLogger("ConfigurationManager");
    }

    ConfigurationManager &ConfigurationManager::getInstance()
    {
        static ConfigurationManager instance;
        return instance;
    }

    void ConfigurationManager::load()
    {
        IniConfig iniFile;

        const bool success = iniFile.parse(m_path);
        if (success) {
            m_logger->info("Using saved configuration");
            for (const auto &config : m_configurations) {
                for (const std::string &key : config->getKeys()) {
                    try {
                        const std::string path = config->getName() + "." + key;
                        const auto value = iniFile.get<std::string>(path);
                        config->set(key, value);
                        m_logger->info(path + ": " + value);
                    } catch (const std::exception &exception) {
                        m_logger->warning(exception.what());
                    }
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

    std::shared_ptr<Renderer> ConfigurationManager::getRenderer() const
    {
        return m_rendererConfig;
    }

    std::shared_ptr<Physics> ConfigurationManager::getPhysics() const
    {
        return m_physicsConfig;
    }
}// namespace ecge::config
