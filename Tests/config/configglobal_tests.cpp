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

#include <gtest/gtest.h>

#include "config/globalconfig.hpp"

class ConfigGlobalTest : public testing::Test
{
protected:
    sfge::config::Global globalConfig;
};

TEST_F(ConfigGlobalTest, LoggingFilePathDefaultValue)
{
    const auto &def = globalConfig.getKeyDefinitions();
    const auto it = sfge::config::findKeyDefinition(def, sfge::config::Global::GetLoggingFilePathKeyName());
    EXPECT_TRUE(it != def.end());
    EXPECT_EQ(globalConfig.getLoggingFilePath(), std::any_cast<std::string>(it->defaultValue));
}

TEST_F(ConfigGlobalTest, SetLoggingFilePath)
{
    const std::string loggingPath = "/path/to/file";
    globalConfig.setLoggingFilePath(loggingPath);
    EXPECT_EQ(loggingPath, globalConfig.getLoggingFilePath());
}