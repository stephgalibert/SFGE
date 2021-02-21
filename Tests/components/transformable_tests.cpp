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

#include <sfge/components/transformable.hpp>

#include <box2d/b2_common.h>
#include <gtest/gtest.h>

class TransformableTest : public testing::Test
{
protected:
    void SetUp() override
    {
        entity = registry.create();
        transformable = registry.emplace<sfge::ecs::Transformable>(entity);
        transformable.setRegistry(&registry);
        transformable.setEntity(entity);
    }

    void TearDown() override
    {
        registry.remove_all(entity);
    }

    entt::registry registry;
    entt::entity entity = entt::null;
    sfge::ecs::Transformable transformable;
};

TEST_F(TransformableTest, Position)
{
    const sf::Vector2f pos = {42, 84};
    transformable.setPosition(pos);
    EXPECT_EQ(pos, transformable.getPosition());
}

TEST_F(TransformableTest, Rotation)
{
    const float degrees = 154;
    const float radians = degrees * b2_pi / 180.f;
    transformable.setAngle_RADIANS(radians);
    EXPECT_FLOAT_EQ(radians, transformable.getAngle_RADIANS());
    EXPECT_FLOAT_EQ(degrees, transformable.getAngle_DEGREES());
}

TEST_F(TransformableTest, Scale)
{
    const sf::Vector2f scale = {3, 1};
    transformable.setScale(scale);
    EXPECT_EQ(scale, transformable.getScale());
}

TEST_F(TransformableTest, Transform)
{
    const sf::Vector2f pos = {87, 24};
    const float radians = 0.5602f;
    const float degrees = radians * 180.f / b2_pi;
    transformable.setTransform(pos, radians);
    EXPECT_EQ(pos, transformable.getPosition());
    EXPECT_FLOAT_EQ(radians, transformable.getAngle_RADIANS());
    EXPECT_FLOAT_EQ(degrees, transformable.getAngle_DEGREES());
}