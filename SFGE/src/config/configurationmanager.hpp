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

#pragma once

#include "iconfiguration.hpp"

#include "sfge/logger/logger.hpp"

#include <memory>
#include <vector>

namespace sfge::config
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

}// namespace sfge::config
