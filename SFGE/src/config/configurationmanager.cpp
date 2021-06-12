//
// This file is part of SFGE.
// Copyright (C) 2020-2021 sgalibert (stephane.galibert.perso@outlook.com)
//
// SFGE is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// SFGE is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with SFGE. If not, see <https://www.gnu.org/licenses/>.
//

#include "configurationmanager.hpp"

#include "sfge/services/iloggerservice.hpp"
#include "sfge/services/servicelocator.hpp"

#include "globalconfig.hpp"
#include "physicsconfig.hpp"
#include "rendererconfig.hpp"

#include "iniconfig.hpp"
#include "typeparser.hpp"

namespace sfge::config
{
    ConfigurationManager::ConfigurationManager()
        : m_path("config.ini")
    {
        m_globalConfig = std::make_shared<Global>();
        m_rendererConfig = std::make_shared<Renderer>();
        m_physicsConfig = std::make_shared<Physics>();

        m_configurations.push_back(m_globalConfig);
        m_configurations.push_back(m_rendererConfig);
        m_configurations.push_back(m_physicsConfig);

        auto loggerService = services::ServiceLocator::Get<services::ILoggerService>();
        m_logger = loggerService->getOrCreateLogger("ConfigurationManager");
        m_logger->addLoggingFile(m_globalConfig->getLoggingFilePath());
    }

    ConfigurationManager::~ConfigurationManager()
    {
        auto loggerService = services::ServiceLocator::Get<services::ILoggerService>();
        loggerService->removeLogger(m_logger);
    }

    void ConfigurationManager::load()
    {
        IniConfig iniFile;

        const bool success = iniFile.parse(m_path);
        if (success) {
            m_logger->info("Using saved configuration");
            for (const auto &config : m_configurations) {
                const auto &keysValues = config->retrieveNormalizedValues();
                for (const auto &keyValue : keysValues) {
                    try {
                        const std::string &key = keyValue.first;
                        const std::string path = config->getName() + "." + key;
                        const auto value = iniFile.get<std::string>(path);
                        config->initValue(key, value);
                        m_logger->info(path + ": " + value);
                    } catch (const std::exception &exception) {
                        m_logger->warning(exception.what());
                    }
                }
            }
        } else {
            // Not able to parse the configuration file,
            // Save default.
            save();
        }
    }

    void ConfigurationManager::save()
    {
        IniConfig iniConfig;
        m_logger->info("Saving configuration");
        for (const auto &config : m_configurations) {
            const auto &keysValues = config->retrieveNormalizedValues();
            for (const auto &keyValue : keysValues) {
                const std::string path = config->getName() + "." + keyValue.first;
                const std::string &value = keyValue.second;

                m_logger->info(path + ": " + value);
                iniConfig.put(path, value);
            }
        }
        if (!iniConfig.write(m_path))
            m_logger->warning("Failed to save to " + m_path);
    }

    std::shared_ptr<Global> ConfigurationManager::getGlobal() const
    {
        return m_globalConfig;
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
