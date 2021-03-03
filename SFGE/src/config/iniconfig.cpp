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

#include "iniconfig.hpp"
#include "sfge/services/iloggerservice.hpp"
#include "sfge/services/servicelocator.hpp"

#include <boost/property_tree/ini_parser.hpp>

#include <iostream>

namespace sfge::config
{
    IniConfig::IniConfig()
    {
        auto loggerService = services::ServiceLocator::Get<services::ILoggerService>();
        m_logger = loggerService->getOrCreateLogger("IniConfig");
        m_logger->addLoggingFile("logs/log.txt");
    }

    IniConfig::~IniConfig()
    {
        auto loggerService = services::ServiceLocator::Get<services::ILoggerService>();
        loggerService->removeLogger(m_logger);
    }

    bool IniConfig::parse(const std::string &filename)
    {
        try {
            boost::property_tree::ini_parser::read_ini(filename, m_ptree);
        } catch (const boost::property_tree::ini_parser_error &exception) {
            m_logger->info(exception.what());
            return false;
        }
        return true;
    }

    bool IniConfig::write(const std::string &filename) const
    {
        try {
            boost::property_tree::ini_parser::write_ini(filename, m_ptree);
        } catch (const boost::property_tree::ini_parser_error &exception) {
            m_logger->info(exception.what());
            return false;
        }
        return true;
    }
}// namespace sfge::config