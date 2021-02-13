#pragma once

#include "sfge/components/ascript.h"
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

        template<typename RigidbodyType>
        typename std::enable_if_t<std::is_same_v<ecs::RigidBody, RigidbodyType>, RigidbodyType &>
        addComponent();

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