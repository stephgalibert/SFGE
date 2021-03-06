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

#include "sfge/components/transformable.hpp"
#include "sfge/pimpl.hpp"

#include <SFML/Graphics/RenderTarget.hpp>
#include <entt/entt.hpp>

#include <box2d/b2_body.h>
#include <memory>
#include <sfge/components/rigidbody.hpp>

namespace sfge
{
    namespace input
    {
        struct KeyboardEvent;
        struct MouseButtonEvent;
    }// namespace input

    class AScenePrivate;
    class AGameObject;

    class AScene
    {
    public:
        AScene();
        virtual ~AScene();

        virtual void init();

        void destroy();
        void onKeyboardEvent(const input::KeyboardEvent &event);
        void onMouseButtonEvent(const input::MouseButtonEvent &event);

        void update(float dt);
        void draw();

    public:
        template<typename T, typename... Args>
        std::shared_ptr<T> instantiate(Args &&... args);

    private:
        explicit AScene(AScenePrivate *dd);
        PIMPL_DECLARE_PRIVATE(AScene);
        void addGameObject(const std::shared_ptr<AGameObject> &obj);
    };


    template<typename T, typename... Args>
    std::shared_ptr<T> AScene::instantiate(Args &&... args)
    {
        auto obj = std::make_shared<T>(std::forward<Args>(args)...);
        addGameObject(obj);
        return obj;
    }
}// namespace sfge
