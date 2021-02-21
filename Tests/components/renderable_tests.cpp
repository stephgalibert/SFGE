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

#include <SFML/Graphics/Shape.hpp>
#include <box2d/b2_common.h>
#include <gtest/gtest.h>

class RenderableTest : public testing::Test
{
protected:
    void SetUp() override
    {
        renderable.setShape(new sf::RectangleShape());
    }
    sfge::ecs::Renderable renderable;
};

TEST_F(RenderableTest, Origin)
{
    const sf::Vector2f origin = {2.2f, 3.9f};
    renderable.setOrigin(origin.x, origin.y);
    EXPECT_EQ(origin, renderable.getOrigin());
}

TEST_F(RenderableTest, Position)
{
    const sf::Vector2f position = {2, 3};
    renderable.setPosition(position.x, position.y);
    EXPECT_EQ(position, renderable.getPosition());
}

TEST_F(RenderableTest, Scale)
{
    const sf::Vector2f scale = {2, 1};
    renderable.setScale(scale.x, scale.y);
    EXPECT_EQ(scale, renderable.getScale());
}

TEST_F(RenderableTest, Rotation)
{
    const float radians = 0.725;
    const float degrees = radians * 180.f / b2_pi;
    renderable.setRotation_RADIANS(radians);
    EXPECT_EQ(radians, renderable.getAngle_RADIANS());
    EXPECT_EQ(degrees, renderable.getAngle_DEGREES());
}

TEST_F(RenderableTest, Color)
{
    const sf::Color color = sf::Color::Red;
    renderable.setColor(color);
    EXPECT_EQ(color, renderable.getColor());
}