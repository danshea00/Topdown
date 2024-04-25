#include <SFML/Graphics.hpp>
#include "PlayingEntity.h"
#include "Bullet.h"
#include "EntityManager.h"

PlayingEntity::PlayingEntity(sf::Vector2f position, sf::Color colour, std::function<void(void)> onDeath) 
: Entity(position), m_health(1.0f)
{
    m_circle.setRadius(RADIUS);
    m_circle.setFillColor(colour);
    m_circle.setOrigin(sf::Vector2f(RADIUS, RADIUS));
    m_health_bar.setFillColor(sf::Color::Green);
    m_health_bar.setSize(sf::Vector2f(40.0f, 10.0f));
    onDeath = onDeath;
}

PlayingEntity::~PlayingEntity() {}

void PlayingEntity::draw(sf::RenderWindow &window)
{
    
    m_circle.setPosition(m_position);
    m_health_bar.setPosition(m_position - sf::Vector2f(RADIUS + 5.0f, RADIUS + 10.0f));
    m_health_bar.setSize(sf::Vector2f(40.0f*m_health, 10.0f));
    window.draw(m_circle);
    window.draw(m_health_bar);
}

void PlayingEntity::handleDeath() {
    auto &entManager = EntityManager::getInstance();
    entManager.queueForDeletion(this->id);
}

void PlayingEntity::takeDamage(float damage){
    if (m_health > 0) m_health -= damage;
    else {
        handleDeath();
    }
}

sf::Vector2f PlayingEntity::getPosition()
{
    float radius = m_circle.getRadius();
    return m_position + sf::Vector2f(radius, radius);
}

sf::FloatRect PlayingEntity::getGlobalBounds()
{
    return m_circle.getGlobalBounds();
}

int PlayingEntity::getHealth()
{
    return m_health;
}
