#include "Entity.h"

Entity::Entity(sf::Vector2f position) : m_position(position) {}

Entity::~Entity() {}

bool Entity::isIntersecting(std::shared_ptr<Entity> other)
{
    auto occupiedRegion = other->getGlobalBounds();
    return getGlobalBounds().findIntersection(occupiedRegion).has_value();
}

bool Entity::isOutOfBounds(sf::RenderWindow &window)
{
    // Check if the bullet is out of the window bounds
    return (m_position.x < 0 || m_position.x > window.getSize().x ||
            m_position.y < 0 || m_position.y > window.getSize().y);
}