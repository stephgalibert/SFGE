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

#pragma once

#include <memory>

namespace sfge
{
    class AGameObject;

    namespace event
    {
        struct KeyboardEvent;
        struct MouseButtonEvent;
    }// namespace event
}// namespace sfge

namespace sfge::ecs
{
    class AScript
    {
    public:
        virtual ~AScript() = default;

        void attachGameObject(AGameObject *gameObject);
        [[nodiscard]] AGameObject *getGameObject() const;

        virtual void onCollisionEnter(AGameObject *collided);
        virtual void onCollisionExit(AGameObject *collided);

        virtual void onAwake() = 0;
        virtual void onUpdate(float dt) = 0;
        virtual void onDestroy() = 0;

        virtual void onKeyboardEvent(const event::KeyboardEvent &event);
        virtual void onMouseButtonEvent(const event::MouseButtonEvent &event);

    private:
        AGameObject *m_gameObject = nullptr;
    };
}// namespace sfge::ecs