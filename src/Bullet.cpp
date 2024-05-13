#include "Bullet.h"
#include "PlayingEntity.h"
#include "EntityManager.h"

Bullet::Bullet(sf::Vector2f position, sf::Vector2f direction, EntityId shotBy) 
: Entity(position), m_direction(direction.normalized()), m_shotBy(shotBy)
{
    m_circle.setRadius(5);
    m_circle.setFillColor(sf::Color::Red);
    m_circle.setPosition(m_position);
}

void Bullet::update(sf::Time deltaTime)
{  
    m_position += m_direction * BULLET_SPEED * deltaTime.asSeconds();
    m_circle.setPosition(m_position);
}

void Bullet::draw(sf::RenderWindow &window)
{
    window.draw(m_circle);
}

sf::FloatRect Bullet::getGlobalBounds()
{
    return m_circle.getGlobalBounds();
}