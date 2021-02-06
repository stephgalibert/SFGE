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
        // AGameObject can only be instantiated by an AScene
        AGameObject();
        virtual ~AGameObject();

        virtual void onCreated();
        virtual void onDestroyed();

        [[nodiscard]] uint32_t getId() const;

    public:
        template<typename T, typename... Args>
        T &addComponent(Args &&... args);

        template<typename T>
        const T &component() const;

        template<typename T>
        T &component();

    private:
        explicit AGameObject(AGameObjectPrivate *dd);
        PIMPL_DECLARE_PRIVATE(AGameObject);

    private:
        void setEntity(entt::entity entity);
        [[nodiscard]] entt::entity entity() const;

        void setComponentRegistry(entt::registry *reg);
        [[nodiscard]] entt::registry *componentRegistry();
        [[nodiscard]] const entt::registry *componentRegistry() const;

        friend class AScene;
    };
}// namespace ecge

#include "agameobject.inl"