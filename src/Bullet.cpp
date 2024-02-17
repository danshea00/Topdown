#include "Bullet.h"
#include "EntityManager.h"

Bullet::Bullet(sf::Vector2f position, sf::Vector2f direction) : Entity(position, "bullet"), m_direction(direction.normalized())
{
    m_circle.setRadius(5);
    m_circle.setFillColor(sf::Color::Red);
    m_circle.setPosition(m_position);
}

void Bullet::update(sf::Time deltaTime)
{
    auto &managerInstance = EntityManager::getInstance();
    // 1. check for collision with enemy or player
    managerInstance.g
        .isColliding(this.id)

        // Update the bullet position based on its direction and speed
        m_position += m_direction * BULLET_SPEED * deltaTime.asSeconds();
    m_circle.setPosition(m_position);
}

void Bullet::draw(sf::RenderWindow &window)
{
    window.draw(m_circle);
}

bool Bullet::isOutOfBounds(sf::RenderWindow &window)
{
    // Check if the bullet is out of the window bounds
    return (m_position.x < 0 || m_position.x > window.getSize().x ||
            m_position.y < 0 || m_position.y > window.getSize().y);
}

sf::FloatRect Bullet::getGlobalBounds()
{
    return m_circle.getGlobalBounds();
}