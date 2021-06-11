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

#include "config/rendererconfig.hpp"

#include <sstream>

class ConfigRendererTest : public testing::Test
{
protected:
    sfge::config::Renderer rendererConfig;
};

TEST_F(ConfigRendererTest, WidthDefaultValue)
{
    const auto &def = rendererConfig.getKeyDefinitions();
    const auto it = sfge::config::findKeyDefinition(def, sfge::config::Renderer::GetWidthKeyName());
    EXPECT_TRUE(it != def.end());
    EXPECT_EQ(rendererConfig.getWidth(), std::any_cast<int>(it->defaultValue));
}

TEST_F(ConfigRendererTest, HeightDefaultValue)
{
    const auto &def = rendererConfig.getKeyDefinitions();
    const auto it = sfge::config::findKeyDefinition(def, sfge::config::Renderer::GetHeightKeyName());
    EXPECT_TRUE(it != def.end());
    EXPECT_EQ(rendererConfig.getHeight(), std::any_cast<int>(it->defaultValue));
}

TEST_F(ConfigRendererTest, AntiAliasingDefaultValue)
{
    const auto &def = rendererConfig.getKeyDefinitions();
    const auto it = sfge::config::findKeyDefinition(def, sfge::config::Renderer::GetAntiAliasingKeyName());
    EXPECT_TRUE(it != def.end());
    EXPECT_EQ(rendererConfig.getAntiAliasing(), std::any_cast<int>(it->defaultValue));
}

TEST_F(ConfigRendererTest, MaxFpsDefaultValue)
{
    const auto &def = rendererConfig.getKeyDefinitions();
    const auto it = sfge::config::findKeyDefinition(def, sfge::config::Renderer::GetMaxFpsKeyName());
    EXPECT_TRUE(it != def.end());
    EXPECT_EQ(rendererConfig.getMaxFps(), std::any_cast<int>(it->defaultValue));
}

TEST_F(ConfigRendererTest, VSyncDefaultValue)
{
    const auto &def = rendererConfig.getKeyDefinitions();
    const auto it = sfge::config::findKeyDefinition(def, sfge::config::Renderer::GetVSyncKeyName());
    EXPECT_TRUE(it != def.end());
    EXPECT_EQ(rendererConfig.getVSync(), std::any_cast<bool>(it->defaultValue));
}

TEST_F(ConfigRendererTest, TextureSmoothDefaultValue)
{
    const auto &def = rendererConfig.getKeyDefinitions();
    const auto it = sfge::config::findKeyDefinition(def, sfge::config::Renderer::GetTextureSmoothKeyName());
    EXPECT_TRUE(it != def.end());
    EXPECT_EQ(rendererConfig.getTextureSmooth(), std::any_cast<bool>(it->defaultValue));
}

TEST_F(ConfigRendererTest, NormalizedValues)
{
    const auto normalizedValues = rendererConfig.retrieveNormalizedValues();
    EXPECT_EQ(std::to_string(rendererConfig.getWidth()), normalizedValues.at(sfge::config::Renderer::GetWidthKeyName()));
    EXPECT_EQ(std::to_string(rendererConfig.getHeight()), normalizedValues.at(sfge::config::Renderer::GetHeightKeyName()));
    EXPECT_EQ(std::to_string(rendererConfig.getAntiAliasing()), normalizedValues.at(sfge::config::Renderer::GetAntiAliasingKeyName()));
    EXPECT_EQ(std::to_string(rendererConfig.getMaxFps()), normalizedValues.at(sfge::config::Renderer::GetMaxFpsKeyName()));

    std::ostringstream oss;
    oss << std::boolalpha << rendererConfig.getVSync();
    EXPECT_EQ(oss.str(), normalizedValues.at(sfge::config::Renderer::GetVSyncKeyName()));

    oss.str("");
    oss.clear();
    oss << std::boolalpha << rendererConfig.getTextureSmooth();
    EXPECT_EQ(oss.str(), normalizedValues.at(sfge::config::Renderer::GetTextureSmoothKeyName()));
}