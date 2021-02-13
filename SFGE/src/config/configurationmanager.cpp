#include "configurationmanager.h"

#include "physicsconfig.h"
#include "rendererconfig.h"

#include "iniconfig.h"

namespace sfge::config
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
        Logger::RemoveLogger(m_logger);
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
                const auto &keysValues = config->getKeysValues();
                for (const auto &keyValue : keysValues) {
                    try {
                        const std::string &key = keyValue.first;
                        const std::string path = config->getName() + "." + key;
                        const auto value = iniFile.get<std::string>(path);
                        config->setValue(key, value);
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
            const auto &keysValues = config->getKeysValues();
            for (const auto &keyValue : keysValues) {
                const std::string &value = keyValue.second;
                const std::string path = config->getName() + "." + keyValue.first;
                m_logger->info(path + ": " + value);
                iniConfig.put(path, value);
            }
        }
        if (!iniConfig.write(m_path))
            m_logger->warning("Failed to save to " + m_path);
    }

    std::shared_ptr<Renderer> ConfigurationManager::getRenderer() const
    {
        return m_rendererConfig;
    }

    std::shared_ptr<Physics> ConfigurationManager::getPhysics() const
    {
        return m_physicsConfig;
    }
}// namespace sfge::config
