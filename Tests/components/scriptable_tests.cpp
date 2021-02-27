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

#include "mock/objectregister.hpp"
#include "mock/script.hpp"
#include "mock/scriptablestates.hpp"

#include <sfge/components/scriptable.hpp>

#include <gtest/gtest.h>

#include <vector>

class ScriptableTest : public testing::Test
{
public:
    sfge::ecs::Scriptable scriptable;
    ObjectRegister objRegister;
    ScriptableStates states;
};

TEST_F(ScriptableTest, Insertion)
{
    EXPECT_EQ(0, scriptable.getSize());
    EXPECT_TRUE(scriptable.addScript<ScriptMockAlpha>(&objRegister));// memoryVerifier,
    EXPECT_EQ(1, scriptable.getSize());
    EXPECT_TRUE(scriptable.addScript<ScriptMockBeta>(&objRegister));
    EXPECT_EQ(2, scriptable.getSize());
    EXPECT_EQ(2, objRegister.getCounter());
}

TEST_F(ScriptableTest, Remove)
{
    EXPECT_EQ(0, scriptable.getSize());
    EXPECT_TRUE(scriptable.addScript<ScriptMockAlpha>(&objRegister));
    EXPECT_EQ(1, scriptable.getSize());
    EXPECT_EQ(1, objRegister.getCounter());
    EXPECT_EQ(0, scriptable.removeScript<ScriptMockAlpha>());
    EXPECT_EQ(0, scriptable.getSize());
    EXPECT_EQ(0, objRegister.getCounter());
    EXPECT_TRUE(scriptable.addScript<ScriptMockAlpha>(&objRegister));
    EXPECT_TRUE(scriptable.addScript<ScriptMockBeta>(&objRegister));
    EXPECT_EQ(2, objRegister.getCounter());
    EXPECT_EQ(2, scriptable.getSize());
    EXPECT_EQ(1, scriptable.removeScript<ScriptMockBeta>());
    EXPECT_EQ(0, scriptable.removeScript<ScriptMockAlpha>());
    EXPECT_EQ(0, scriptable.getSize());
    EXPECT_EQ(0, objRegister.getCounter());
}

TEST_F(ScriptableTest, Update)
{
    auto scriptAlpha = scriptable.addScript<ScriptMockAlpha>(&objRegister);
    EXPECT_TRUE(scriptAlpha);
    scriptAlpha->setStateManager(&states);
    auto scriptBeta = scriptable.addScript<ScriptMockBeta>(&objRegister);
    EXPECT_TRUE(scriptBeta);
    scriptBeta->setStateManager(&states);

    scriptable.update(56);

    EXPECT_EQ(2, states.size());
    EXPECT_TRUE(states == ScriptableState::Update);
}

TEST_F(ScriptableTest, Destroy)
{
    auto scriptAlpha = scriptable.addScript<ScriptMockAlpha>(&objRegister);
    EXPECT_TRUE(scriptAlpha);
    scriptAlpha->setStateManager(&states);

    auto scriptBeta = scriptable.addScript<ScriptMockBeta>(&objRegister);
    EXPECT_TRUE(scriptBeta);
    scriptBeta->setStateManager(&states);

    scriptable.destroy();

    EXPECT_EQ(2, states.size());
    EXPECT_TRUE(states == ScriptableState::Destroy);
}