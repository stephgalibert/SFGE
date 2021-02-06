#pragma once

#include "pimpl.hpp"

#include <entt/entt.hpp>

#include <memory>

namespace ecge
{
    class AGameObjectPrivate;
    class AScene;

    class AGameObject
    {
    public:
        virtual ~AGameObject();

        virtual void onCreated();
        virtual void onDestroyed();

        [[nodiscard]] uint32_t getId() const;

    public:
        template<typename T, typename... Args>
        std::shared_ptr<T> instantiate(Args &&... args) const;

        template<typename T, typename... Args>
        T &addComponent(Args &&... args);

        template<typename T>
        const T &component() const;

        template<typename T>
        T &component();

    protected:
        AGameObject();

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
}// namespace ecge

#include "agameobject.inl"