#include "sfge/components/renderable.hpp"

#include <iostream>

namespace sfge::ecs
{
    Renderable::Renderable(sf::Shape *shape)
        : m_shape(shape)
    {
    }

    Renderable::Renderable(Renderable &&rhs) noexcept
        : Component(std::move(rhs))
    {
        m_shape = std::move(rhs.m_shape);
    }

    Renderable &Renderable::operator=(Renderable &&rhs) noexcept
    {
        m_shape = std::move(rhs.m_shape);
        Component::operator=(std::move(rhs));
        return *this;
    }

    const std::unique_ptr<sf::Shape> &Renderable::shape() const
    {
        return m_shape;
    }

    std::unique_ptr<sf::Shape> &Renderable::shape()
    {
        return m_shape;
    }
}// namespace sfge::ecs