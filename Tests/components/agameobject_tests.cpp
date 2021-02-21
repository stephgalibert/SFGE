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

#include <sfge/components/camera.hpp>
#include <sfge/components/input.hpp>
#include <sfge/components/renderable.hpp>
#include <sfge/components/rigidbody.hpp>
#include <sfge/components/scriptable.hpp>
#include <sfge/components/transformable.hpp>
#include <sfge/gameobject/agameobject.hpp>

#include <gtest/gtest.h>

class ScriptA : public sfge::ecs::AScript
{
public:
    void onAwake() override {}
    void onUpdate(float dt) override {}
    void onDestroy() override {}
};

class ScriptB : public sfge::ecs::AScript
{
public:
    void onAwake() override {}
    void onUpdate(float dt) override {}
    void onDestroy() override {}
};

class AGameObjectTest : public testing::Test
{
protected:
    void SetUp() override
    {
        gameObject.setComponentRegistry(&registry);
        EXPECT_NE(static_cast<uint32_t>(entt::null), gameObject.getId());
    }

    void add()
    {
        const auto &transformable = gameObject.addComponent<sfge::ecs::Transformable>();
        EXPECT_EQ(sf::Vector2f(0, 0), transformable.getPosition());
        EXPECT_TRUE(transformable.getGameObject());
        const auto &renderable = gameObject.addComponent<sfge::ecs::Renderable>();
        EXPECT_FALSE(renderable.shape());
        const auto &scriptable = gameObject.addComponent<sfge::ecs::Scriptable>();
        EXPECT_EQ(0, scriptable.getSize());
        const auto &rigidbody = gameObject.addComponent<sfge::ecs::RigidBody>();
        EXPECT_FALSE(rigidbody.body());
        const auto &camera = gameObject.addComponent<sfge::ecs::Camera>();
        EXPECT_FALSE(camera.isActive());
        const auto &input = gameObject.addComponent<sfge::ecs::Input>();
        EXPECT_FALSE(input.getKeyboardButton());
        const auto script1 = gameObject.addComponent<ScriptA>();
        EXPECT_TRUE(script1);
        const auto script2 = gameObject.addComponent<ScriptB>();
        EXPECT_TRUE(script2);
    }
    entt::registry registry;
    sfge::AGameObject gameObject;
};

TEST_F(AGameObjectTest, AddComponents)
{
    add();
}

TEST_F(AGameObjectTest, GetComponents)
{
    add();
    const auto &transformable = gameObject.component<sfge::ecs::Transformable>();
    EXPECT_EQ(sf::Vector2f(0, 0), transformable.getPosition());
    EXPECT_TRUE(transformable.getGameObject());
    const auto &renderable = gameObject.component<sfge::ecs::Renderable>();
    EXPECT_FALSE(renderable.shape());
    const auto &scriptable = gameObject.component<sfge::ecs::Scriptable>();
    EXPECT_EQ(2, scriptable.getSize());
    const auto &rigidbody = gameObject.component<sfge::ecs::RigidBody>();
    EXPECT_FALSE(rigidbody.body());
    const auto &camera = gameObject.component<sfge::ecs::Camera>();
    EXPECT_FALSE(camera.isActive());
    const auto &input = gameObject.component<sfge::ecs::Input>();
    EXPECT_FALSE(input.getKeyboardButton());
//    std::shared_ptr<ScriptA> script1 = gameObject.component<ScriptA>();
//    (void)script1;
//    const auto &script2 = gameObject.component<ScriptB>();
//    (void)script2;
}

TEST_F(AGameObjectTest, RemoveComponents)
{
    add();
    gameObject.removeComponent<sfge::ecs::Transformable>();
    gameObject.removeComponent<sfge::ecs::Renderable>();
    gameObject.removeComponent<sfge::ecs::RigidBody>();
    gameObject.removeComponent<sfge::ecs::Camera>();
    gameObject.removeComponent<sfge::ecs::Input>();
    gameObject.removeComponent<ScriptA>();
    gameObject.removeComponent<ScriptB>();

    const auto &scriptable = gameObject.component<sfge::ecs::Scriptable>();
    EXPECT_EQ(0, scriptable.getSize());
    gameObject.removeComponent<sfge::ecs::Scriptable>();
}