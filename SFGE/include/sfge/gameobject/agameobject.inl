#include "sfge/components/scriptable.h"
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
        component.setRegistry(reg);
        component.setEntity(entt);
        return component;
    }

    template<typename RigidbodyType>
    typename std::enable_if_t<std::is_same_v<ecs::RigidBody, RigidbodyType>, RigidbodyType &>
    AGameObject::addComponent()
    {
        return addComponent<RigidbodyType>(this);
    }

    // std::unique_ptr<ScriptType> &
    template<typename ScriptType>
    typename std::enable_if_t<std::is_base_of_v<ecs::AScript, ScriptType>>
    AGameObject::addComponent()
    {
        entt::registry *reg = componentRegistry();
        assert(reg != nullptr);
        entt::entity entt = entity();
        assert(entt != entt::null);

        auto &scriptable = reg->template get_or_emplace<ecs::Scriptable>(entt);
        scriptable.setRegistry(reg);
        scriptable.setEntity(entt);

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