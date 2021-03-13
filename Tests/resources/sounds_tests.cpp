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

#include "core/resources/soundloader.hpp"

#include <gtest/gtest.h>

class SoundLoaderTest : public testing::Test
{
protected:
    SoundLoaderTest()
        : key("sound")
    {
    }

    void SetUp() override
    {
        const auto &sound = getSound();
        EXPECT_TRUE(soundLoader.loadFromSamples(key, sound, 1, 44100));
    }

    const std::string key;
    sfge::resources::SoundLoader soundLoader;
};

TEST_F(SoundLoaderTest, Insert)
{
    EXPECT_FALSE(soundLoader.loadFromFile("key", "fake.wav"));
}

TEST_F(SoundLoaderTest, Get)
{
    EXPECT_TRUE(soundLoader.getSound(key));
    EXPECT_FALSE(soundLoader.getSound("badKey"));
}

TEST_F(SoundLoaderTest, Remove)
{
    EXPECT_TRUE(soundLoader.remove(key));
    EXPECT_FALSE(soundLoader.getSound(key));
}

TEST_F(SoundLoaderTest, Clear)
{
    soundLoader.clear();
    EXPECT_FALSE(soundLoader.getSound(key));
}
