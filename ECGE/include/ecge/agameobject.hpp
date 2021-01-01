#pragma once

#include "pimpl.hpp"

#include <entt/entt.hpp>

#include <memory>

namespace ecge
{
    class AGameObjectPrivate;

    class AGameObject
    {
    public:
        AGameObject();
        virtual ~AGameObject();

        virtual void onCreated();
        virtual void onDestroyed();

        void setEntity(entt::entity entity);
        [[nodiscard]] entt::entity entity() const;

        void setComponentRegistry(entt::registry *reg);
        [[nodiscard]] entt::registry *componentRegistry();
        [[nodiscard]] const entt::registry *componentRegistry() const;

        template <typename T, typename... Args>
        decltype(auto) addComponent(Args&&... args)
        {
            entt::registry *reg = componentRegistry();
            return reg->template emplace<T>( entity(), std::forward<Args>(args)... );
        }

        template <typename T>
        decltype(auto) component()
        {
            entt::registry *reg = componentRegistry();
            return reg->template get<T>( entity() );
        }

    private:
        explicit AGameObject(AGameObjectPrivate *dd);
        PIMPL_DECLARE_PRIVATE(AGameObject);

    };
}
