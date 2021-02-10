#include "ascene.hpp"
#include "ecge/components/scriptable.h"

namespace ecge
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

        auto script = std::make_unique<ScriptType>();
        script->attachGameObject(this);
        script->onAwake();
        scriptable.addScript(std::move(script));
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
        return reg->template get<T>(entity());
    }
}// namespace ecge