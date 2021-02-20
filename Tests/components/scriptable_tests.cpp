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

#include <sfge/components/base/ascript.hpp>
#include <sfge/components/scriptable.hpp>

#include <gtest/gtest.h>

#include <iostream>
#include <vector>

class ScriptableTest : public testing::Test
{
public:
    enum class State : int
    {
        Awake = 0,
        Update,
        Destroy
    };

    sfge::ecs::Scriptable scriptable;
    int32_t allocated = 0;
    std::vector<State> states;
};

class Script1 : public sfge::ecs::AScript
{
public:
    explicit Script1(ScriptableTest &test)
        : m_test(test)
    {
        ++m_test.allocated;
    }
    virtual ~Script1()
    {
        --m_test.allocated;
    }
    void onAwake() override
    {
        m_test.states.push_back(ScriptableTest::State::Awake);
    }
    void onUpdate(float dt) override
    {
        m_test.states.push_back(ScriptableTest::State::Update);
    }
    void onDestroy() override
    {
        m_test.states.push_back(ScriptableTest::State::Destroy);
    }

private:
    ScriptableTest &m_test;
};

class Script2 : public sfge::ecs::AScript
{
public:
    explicit Script2(ScriptableTest &test)
        : m_test(test)
    {
        ++m_test.allocated;
    }
    virtual ~Script2()
    {
        --m_test.allocated;
    }
    void onAwake() override
    {
        m_test.states.push_back(ScriptableTest::State::Awake);
    }
    void onUpdate(float dt) override
    {
        m_test.states.push_back(ScriptableTest::State::Update);
    }
    void onDestroy() override
    {
        m_test.states.push_back(ScriptableTest::State::Destroy);
    }

private:
    ScriptableTest &m_test;
};

TEST_F(ScriptableTest, Insertion)
{
    EXPECT_EQ(0, scriptable.getSize());
    EXPECT_TRUE(scriptable.addScript<Script1>(*this));
    EXPECT_EQ(1, scriptable.getSize());
    EXPECT_TRUE(scriptable.addScript<Script2>(*this));
    EXPECT_EQ(2, scriptable.getSize());
    EXPECT_EQ(allocated, 2);
}

TEST_F(ScriptableTest, Remove)
{
    EXPECT_EQ(0, scriptable.getSize());
    EXPECT_TRUE(scriptable.addScript<Script1>(*this));
    EXPECT_EQ(1, scriptable.getSize());
    EXPECT_EQ(1, allocated);
    EXPECT_EQ(0, scriptable.removeScript<Script1>());
    EXPECT_EQ(0, scriptable.getSize());
    EXPECT_EQ(0, allocated);
    EXPECT_TRUE(scriptable.addScript<Script1>(*this));
    EXPECT_TRUE(scriptable.addScript<Script2>(*this));
    EXPECT_EQ(2, allocated);
    EXPECT_EQ(2, scriptable.getSize());
    EXPECT_EQ(1, scriptable.removeScript<Script2>());
    EXPECT_EQ(0, scriptable.removeScript<Script1>());
    EXPECT_EQ(0, scriptable.getSize());
    EXPECT_EQ(0, allocated);
}

TEST_F(ScriptableTest, Update)
{
    EXPECT_TRUE(scriptable.addScript<Script1>(*this));
    EXPECT_TRUE(scriptable.addScript<Script2>(*this));
    scriptable.update(56);

    EXPECT_EQ(2, states.size());
    for (const auto state : states) {
        EXPECT_EQ(State::Update, state);
    }
}

TEST_F(ScriptableTest, Destroy)
{
    EXPECT_TRUE(scriptable.addScript<Script1>(*this));
    EXPECT_TRUE(scriptable.addScript<Script2>(*this));
    scriptable.destroy();

    EXPECT_EQ(2, states.size());
    for (const auto state : states) {
        EXPECT_EQ(State::Destroy, state);
    }
}