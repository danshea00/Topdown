#include "Entity.h"

Entity::Entity(sf::Vector2f position, std::string entityKey) : m_position(position), m_entity_key(entityKey) {}

Entity::~Entity() {}

void Entity::setId(int newId)
{
    id = newId;
}

int Entity::getId()
{
    return id;
}

std::string Entity::getEntityKey()
{
    return m_entity_key;
}

bool Entity::isIntersecting(sf::FloatRect occupiedRegion)
{
    return getGlobalBounds().findIntersection(occupiedRegion).has_value;
}