#include "ascene.hpp"

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
        entt::entity entt = entity();

        assert(entt != entt::null);
        T &component = reg->template emplace<T>(entt, std::forward<Args>(args)...);
        component.setRegistry(reg);
        component.setEntity(entt);
        return component;
    }

    template<typename T>
    const T &AGameObject::component() const
    {
        entt::registry *reg = componentRegistry();
        return reg->template get<T>(entity());
    }

    template<typename T>
    T &AGameObject::component()
    {
        entt::registry *reg = componentRegistry();
        return reg->template get<T>(entity());
    }
}// namespace ecge