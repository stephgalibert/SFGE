#pragma once

#include "iconfiguration.h"

#include "ecge/logger/logger.h"

#include <memory>
#include <vector>

namespace ecge::config
{
    class IniConfig;
    class Renderer;
    class Physics;

    // TODO: Type/Value validator
    class ConfigurationManager
    {
    public:
        ~ConfigurationManager();

        static ConfigurationManager &getInstance();

        void load();
        void save();

        [[nodiscard]] std::shared_ptr<Renderer> getRenderer() const;
        [[nodiscard]] std::shared_ptr<Physics> getPhysics() const;

    private:
        ConfigurationManager();

    private:
        std::string m_path;
        std::shared_ptr<ILogger> m_logger;
        std::vector<std::shared_ptr<IConfiguration>> m_configurations;
        std::shared_ptr<Renderer> m_rendererConfig;
        std::shared_ptr<Physics> m_physicsConfig;
    };

}// namespace ecge::config
