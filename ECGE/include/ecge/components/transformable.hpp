#pragma once

#include "component.hpp"

#include <SFML/Graphics.hpp>

namespace ecge::ecs
{
    class Transformable : public Component
    {
    public:
        Transformable();
        Transformable(const Transformable &rhs);
        Transformable(Transformable &&rhs) noexcept;
        ~Transformable() = default;

        Transformable &operator=(const Transformable &rhs);
        Transformable &operator=(Transformable &&rhs) noexcept;

        void setPosition(const sf::Vector2f &pos);
        void setScale(const sf::Vector2f &scale);
        void setAngle(float angle);
        void setTransform(const sf::Vector2f &pos, float angle);

        [[nodiscard]] sf::Vector2f position() const;
        [[nodiscard]] sf::Vector2f scale() const;
        [[nodiscard]] float angle() const;

    private:
        //        meters = {0.02f * xPixels, 0.02f * yPixels};
        //        pixels = {50.0f * xMeters, 50.0f * yMeters};
        sf::Vector2f m_position;      // meters
        sf::Vector2f m_scale = {1, 1};// meters
        float m_angle = 0.f;          // radians
    };
}