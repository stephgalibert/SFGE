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

#include "resources.hpp"

#include "core/resources/textureloader.hpp"

#include <gtest/gtest.h>

class TextureLoaderTest : public testing::Test
{
protected:
    TextureLoaderTest()
        : key("tex")
    {
    }

    void SetUp() override
    {
        EXPECT_TRUE(textureLoader.loadFromMemory(key, getImage()));
    }

    const std::string key;
    sfge::resources::TextureLoader textureLoader;
};

TEST_F(TextureLoaderTest, Insert)
{
    EXPECT_FALSE(textureLoader.loadFromFile("key", "fake.jpg"));
}

TEST_F(TextureLoaderTest, Get)
{
    EXPECT_TRUE(textureLoader.getTexture(key));
    EXPECT_FALSE(textureLoader.getTexture("bad"));
}

TEST_F(TextureLoaderTest, Remove)
{
    EXPECT_TRUE(textureLoader.remove(key));
    EXPECT_FALSE(textureLoader.getTexture(key));
}

TEST_F(TextureLoaderTest, Clear)
{
    textureLoader.clear();
    EXPECT_FALSE(textureLoader.getTexture(key));
}