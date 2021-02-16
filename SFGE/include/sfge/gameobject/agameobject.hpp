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

#include "sfge/components/interfaces/ascript.hpp"
#include "sfge/components/rigidbody.hpp"
#include "sfge/pimpl.hpp"

#include <entt/entt.hpp>

#include <memory>

namespace sfge
{
    class AGameObjectPrivate;
    class AScene;

    class AGameObject
    {
    public:
        AGameObject();
        virtual ~AGameObject();

        virtual void onCreated();
        virtual void onDestroyed();

        [[nodiscard]] uint32_t getId() const;

    public:
        template<typename T, typename... Args>
        std::shared_ptr<T> instantiate(Args &&... args) const;

        template<typename T, typename... Args>
        T &addComponent(Args &&... args);

        template<typename ScriptType>
        typename std::enable_if_t<std::is_base_of_v<ecs::AScript, ScriptType>>
        addComponent();

        template<typename T>
        const T &component() const;

        template<typename T>
        T &component();

        template<typename T>
        typename std::enable_if_t<!std::is_base_of_v<ecs::AScript, T>>
        removeComponent();

        template<typename ScriptType>
        typename std::enable_if_t<std::is_base_of_v<ecs::AScript, ScriptType>>
        removeComponent();

    private:
        explicit AGameObject(AGameObjectPrivate *dd);
        PIMPL_DECLARE_PRIVATE(AGameObject);

        void setEntity(entt::entity entity);
        [[nodiscard]] entt::entity entity() const;
        void setComponentRegistry(entt::registry *reg);
        [[nodiscard]] entt::registry *componentRegistry() const;
        void setScene(AScene *scene);
        [[nodiscard]] AScene *getScene() const;

        friend AScene;
    };
}// namespace sfge

#include "agameobject.inl"