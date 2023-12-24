#include <SFML/Graphics.hpp>
#include "Player.h"


Player::Player(sf::Vector2f position, float speed) :
    m_position(position), m_speed(speed)
{
    m_circle.setRadius(15);
    m_circle.setFillColor(sf::Color::Blue);
    m_circle.setPosition(m_position);
}

void Player::update(sf::Time deltaTime)
{
    sf::Vector2f movement(0.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        movement.y -= 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        movement.x -= 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        movement.y += 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        movement.x += 1.f;
    }

    move(movement * float(deltaTime.asMilliseconds()));
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
