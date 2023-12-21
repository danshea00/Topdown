#include <SFML/Graphics.hpp>
#include "Player.h"


Player::Player(sf::Vector2f position, float speed) :
    m_position(position), m_speed(speed)
{
    m_circle.setRadius(15);
    m_circle.setFillColor(sf::Color::Red);
    m_circle.setPosition(m_position);
}

void Player::move(sf::Vector2f movement)
{
    m_position += movement;
    m_circle.setPosition(m_position * m_speed);
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(m_circle);
}

sf::Vector2f Player::getPosition() {
    float radius = m_circle.getRadius();
    return m_position + sf::Vector2f(radius, radius);
}

float Player::getRadius() {
    return m_circle.getRadius();
}
