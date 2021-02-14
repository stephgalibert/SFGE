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

#include "sfge/logger/logger.hpp"

#include <boost/property_tree/ptree.hpp>

namespace sfge::config
{
    class IniConfig
    {
    public:
        IniConfig();
        ~IniConfig();

        [[nodiscard]] bool parse(const std::string &filename);
        [[nodiscard]] bool write(const std::string &filename) const;

    public:
        template<typename T>
        [[nodiscard]] T get(const std::string &key);

        template<typename T>
        void put(const std::string &key, const T &value);

    private:
        std::shared_ptr<ILogger> m_logger;
        boost::property_tree::ptree m_ptree;
    };
}// namespace sfge::config

#include "iniconfig.inl"
