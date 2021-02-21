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

#include <SFML/Graphics/RenderTexture.hpp>
#include <gtest/gtest.h>

class CameraTest : public testing::Test
{
protected:
    void SetUp() override
    {
    }
    sfge::ecs::Camera camera;
};

TEST_F(CameraTest, Viewport)
{
    const sf::FloatRect rect = {0, 0, 0.1, 0.1};
    camera.setViewport(rect);
    EXPECT_EQ(rect, camera.getViewport());
}

TEST_F(CameraTest, Size)
{
    const sf::Vector2f size = {5, 5};
    camera.setSize(size.x, size.y);
    EXPECT_EQ(size, camera.getSize());
}

TEST_F(CameraTest, Center)
{
    const sf::Vector2f center = {10, 10};
    camera.setCenter(center.x, center.y);
    EXPECT_EQ(center, camera.getCenter());
}

TEST_F(CameraTest, Rotation)
{
    const float angle = 45.5f;
    camera.setRotation_DEGREES(angle);
    EXPECT_EQ(angle, camera.getRotation_DEGREES());
}

TEST_F(CameraTest, IsActive)
{
    const bool isActive = true;
    camera.setActive(isActive);
    EXPECT_EQ(isActive, camera.isActive());
}