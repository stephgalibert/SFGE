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

#include "sfge/components/scriptable.hpp"
#include "sfge/scene/ascene.hpp"

namespace sfge
{
    template<typename T, typename... Args>
    std::shared_ptr<T> AGameObject::instantiate(Args &&... args) const
    {
        AScene *scene = getScene();
        assert(scene != nullptr);
        return scene->template instantiate<T>(std::forward<Args>(args)...);
    }

    template<typename T, typename... Args>
    T &AGameObject::addComponent(Args &&... args)
    {
        entt::registry *reg = componentRegistry();
        assert(reg != nullptr);
        entt::entity entt = entity();
        assert(entt != entt::null);

        T &component = reg->template emplace<T>(entt, std::forward<Args>(args)...);
        component.attachGameObject(this);
        component.setRegistry(reg);
        component.setEntity(entt);
        return component;
    }

    template<typename ScriptType>
    typename std::enable_if_t<std::is_base_of_v<ecs::AScript, ScriptType>>
    AGameObject::addComponent()
    {
        auto &scriptable = addComponent<ecs::Scriptable>();
        auto &script = scriptable.template addScript<ScriptType>();
        script->attachGameObject(this);
        script->onAwake();
    }

    template<typename T>
    const T &AGameObject::component() const
    {
        entt::registry *reg = componentRegistry();
        assert(reg != nullptr);
        entt::entity entt = entity();
        assert(entt != entt::null);
        return reg->template get<T>(entt);
    }

    template<typename T>
    T &AGameObject::component()
    {
        entt::registry *reg = componentRegistry();
        assert(reg != nullptr);
        return reg->template get<T>(entity());
    }

    template<typename T>
    typename std::enable_if_t<!std::is_base_of_v<ecs::AScript, T>>
    AGameObject::removeComponent()
    {
        entt::registry *reg = componentRegistry();
        assert(reg != nullptr);
        reg->template remove<T>();
    }

    template<typename ScriptType>
    typename std::enable_if_t<std::is_base_of_v<ecs::AScript, ScriptType>>
    AGameObject::removeComponent()
    {
        entt::registry *reg = componentRegistry();
        assert(reg != nullptr);
        entt::entity entt = entity();
        assert(entt != entt::null);

        auto &scriptable = reg->template get<ecs::Scriptable>(entt);
        scriptable.template removeScript<ScriptType>();
    }
}// namespace sfge