#pragma once

#include "iconfiguration.h"

#include <memory>
#include <vector>

namespace ecge::config
{
    class IniFile;

    /**
     * Load engine configuration file.
     * If not exists, will create a default configuration and saves it in the filesystem.
     */
    class ConfigurationManager
    {
    public:
        ConfigurationManager();

        void load();
        void save();

    private:
        std::string m_path;
        std::vector<std::unique_ptr<IConfiguration>> m_configurations;
    };

    // IConfiguration: getName, getKeys, getDefault(), set, reset
    // RendererConfiguration : public IConfiguration
    // PhysicsConfiguration : public IConfiguration

}// namespace ecge::config
