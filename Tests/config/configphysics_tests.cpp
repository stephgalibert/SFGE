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

#include "config/physicsconfig.hpp"

class ConfigPhysicsTest : public testing::Test
{
protected:
    sfge::config::Physics physicsConfig;
};

TEST_F(ConfigPhysicsTest, PixelsPerMetterDefaultValue)
{
    const auto &def = physicsConfig.getKeyDefinitions();
    const auto it = sfge::config::findKeyDefinition(def, sfge::config::Physics::GetPixelsPerMeterKeyName());
    EXPECT_TRUE(it != def.end());
    EXPECT_EQ(physicsConfig.getPixelsPerMeter(), std::any_cast<float>(it->defaultValue));
}

TEST_F(ConfigPhysicsTest, SetPixelsPerMeter)
{
    const float value = 68.5f;
    physicsConfig.setPixelsPerMeter(value);
    EXPECT_EQ(value, physicsConfig.getPixelsPerMeter());
}

TEST_F(ConfigPhysicsTest, NormalizedValues)
{
    const auto normalizedValues = physicsConfig.retrieveNormalizedValues();
    EXPECT_EQ(std::to_string(physicsConfig.getPixelsPerMeter()), normalizedValues.at(sfge::config::Physics::GetPixelsPerMeterKeyName()));
}