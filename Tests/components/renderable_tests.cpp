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

#include <sfge/components/renderable.hpp>
#include <sfge/gameobject/agameobject.hpp>

#include <SFML/Graphics/Shape.hpp>
#include <box2d/b2_common.h>
#include <gtest/gtest.h>

class RenderableTest : public testing::Test
{
protected:
    void SetUp() override
    {
        gameObject.setComponentRegistry(&registry);
        EXPECT_NE(static_cast<uint32_t>(entt::null), gameObject.getId());

        registry.emplace<sfge::ecs::Renderable>(gameObject.getEntity());
        EXPECT_EQ(1, registry.size<sfge::ecs::Renderable>());

        auto &renderable = getRenderable();
        renderable.attachGameObject(&gameObject);
        renderable.setShape(new sf::RectangleShape());
    }

    void TearDown() override
    {
        registry.remove<sfge::ecs::Renderable>(getRenderable().getEntity());
        EXPECT_EQ(0, registry.size<sfge::ecs::Renderable>());
    }

    sfge::ecs::Renderable &getRenderable()
    {
        return registry.get<sfge::ecs::Renderable>(gameObject.getEntity());
    }

    entt::registry registry;
    sfge::AGameObject gameObject;
    // sfge::ecs::Renderable renderable;
};

TEST_F(RenderableTest, Origin)
{
    const sf::Vector2f origin = {2.2f, 3.9f};
    auto &renderable = getRenderable();

    renderable.setOrigin(origin.x, origin.y);
    EXPECT_EQ(origin, renderable.getOrigin());
}

TEST_F(RenderableTest, Position)
{
    const sf::Vector2f position = {2, 3};
    auto &renderable = getRenderable();

    renderable.setPosition(position.x, position.y);
    EXPECT_EQ(position, renderable.getPosition());
}

TEST_F(RenderableTest, Scale)
{
    const sf::Vector2f scale = {2, 1};
    auto &renderable = getRenderable();

    renderable.setScale(scale.x, scale.y);
    EXPECT_EQ(scale, renderable.getScale());
}

TEST_F(RenderableTest, Rotation)
{
    const float radians = 0.725;
    const float degrees = radians * 180.f / b2_pi;
    auto &renderable = getRenderable();

    renderable.setRotation_RADIANS(radians);
    EXPECT_FLOAT_EQ(radians, renderable.getAngle_RADIANS());
    EXPECT_FLOAT_EQ(degrees, renderable.getAngle_DEGREES());
}

TEST_F(RenderableTest, Color)
{
    const sf::Color color = sf::Color::Red;
    auto &renderable = getRenderable();

    renderable.setColor(color);
    EXPECT_EQ(color, renderable.getColor());
}