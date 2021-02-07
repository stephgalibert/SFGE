#pragma once

#include "iconfiguration.h"

#include "ecge/logger/logger.h"

#include <memory>
#include <vector>

namespace ecge::config
{
    class IniConfig;
    class RendererConfiguration;
    class PhysicsConfiguration;

    class ConfigurationManager
    {
    public:
        ConfigurationManager();
        ~ConfigurationManager();

        void load();
        void save();

        [[nodiscard]] std::shared_ptr<RendererConfiguration> getRendererConfig() const;
        [[nodiscard]] std::shared_ptr<PhysicsConfiguration> getPhysicsConf() const;

    private:
        std::string m_path;
        std::shared_ptr<ILogger> m_logger;
        std::vector<std::shared_ptr<IConfiguration>> m_configurations;
        std::shared_ptr<RendererConfiguration> m_rendererConfig;
        std::shared_ptr<PhysicsConfiguration> m_physicsConfig;
    };
}// namespace ecge::config
