#include <SFML/Graphics.hpp>
#include "PlayingEntity.h"
#include "Bullet.h"

PlayingEntity::PlayingEntity(sf::Vector2f position, sf::Color colour) : m_position(position)
{
    auto RADIUS = 15;
    m_circle.setRadius(RADIUS);
    m_circle.setFillColor(colour);
    m_circle.setPosition(m_position);
    m_circle.setOrigin(sf::Vector2f(RADIUS, RADIUS));
}

PlayingEntity::~PlayingEntity() {}

void PlayingEntity::draw(sf::RenderWindow &window)
{
    window.draw(m_circle);
}

sf::Vector2f PlayingEntity::getPosition()
{
    float radius = m_circle.getRadius();
    return m_position + sf::Vector2f(radius, radius);
}

float PlayingEntity::getRadius()
{
    return m_circle.getRadius();
}
