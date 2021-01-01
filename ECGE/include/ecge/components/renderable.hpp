#pragma once

#include "ecge/components/component.hpp"

#include <SFML/Graphics.hpp>

#include <memory>

namespace ecge::ecs
{
    class Renderable : public Component
    {
    public:
        Renderable() = default;
        explicit Renderable(sf::Shape *shape);
        Renderable(const Renderable &rhs) = delete;
        Renderable(Renderable &&rhs) noexcept;
        ~Renderable() = default;

        Renderable &operator=(const Renderable &rhs) = delete;
        Renderable &operator=(Renderable &&rhs) noexcept;

        [[nodiscard]] const std::unique_ptr<sf::Shape> &shape() const;
        [[nodiscard]] std::unique_ptr<sf::Shape> &shape();

    private:
        std::unique_ptr<sf::Shape> m_shape;
    };
}