#include "ecge/components/renderable.hpp"

#include <iostream>

namespace ecge::ecs
{
    Renderable::Renderable(sf::Shape *shape)
        : m_shape(shape)
    {
        std::clog << "renderable ctor" << std::endl;
    }

    Renderable::Renderable(Renderable &&rhs) noexcept
            : Component(std::move(rhs))
    {
        std::clog << "renderable move ctor" << std::endl;
        m_shape = std::move(rhs.m_shape);
    }

    Renderable &Renderable::operator=(Renderable &&rhs) noexcept
    {
        std::clog << "renderable move assign" << std::endl;
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
}