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

#include "aconfiguration.hpp"

#include "services/iconfigurationmanagerservice.h"
#include "sfge/logger/logger.hpp"

#include <memory>
#include <vector>

namespace sfge::config
{
    class IniConfig;

    class ConfigurationManager : public services::IConfigurationManagerService
    {
    public:
        ConfigurationManager();
        virtual ~ConfigurationManager();

        void load() override;
        void save() override;

        [[nodiscard]] std::shared_ptr<Global> getGlobal() const override;
        [[nodiscard]] std::shared_ptr<Renderer> getRenderer() const override;
        [[nodiscard]] std::shared_ptr<Physics> getPhysics() const override;

    private:
        std::string m_path;
        std::shared_ptr<ILogger> m_logger;
        std::vector<std::shared_ptr<AConfiguration>> m_configurations;
        std::shared_ptr<Global> m_globalConfig;
        std::shared_ptr<Renderer> m_rendererConfig;
        std::shared_ptr<Physics> m_physicsConfig;
    };

}// namespace sfge::config
