#include "EntityManager.h"
#include <iostream>
#include <algorithm>

std::shared_ptr<Entity> EntityManager::getEntityCollidingWith(sf::FloatRect occupiedRegion)
{
    auto entity_iterator = std::find_if(
        m_entities.begin(),
        m_entities.end(),
        [entity_id](std::shared_ptr<Entity> entity)
        { return entity->isIntersecting(occupiedRegion) });

    if (entity_iterator != std::end(m_entities))
    {
        return (*entity_iterator)
    }

    return std::nullopt
}

void EntityManager::updateEntities(sf::Time deltaTime)
{

    // don't use for loop!
    for (auto entityIt = m_spawn_queue.begin(); entityIt != m_spawn_queue.end(); entityIt++)
    {
        m_entities.push_back(*entityIt);
    }

    m_spawn_queue.clear();

    for (auto entityIt = m_entities.begin(); entityIt != m_entities.end(); entityIt++)
    {
        (*entityIt)->update(deltaTime);
    }
}

// todo -- read into const, nonconst and references
void EntityManager::drawEntities(sf::RenderWindow &m_window)
{
    for (auto &entity : m_entities)
    {
        entity->draw(m_window);
    }
}

void EntityManager::deleteEntity(int entity_id)
{
    auto entity_iterator = std::find_if(
        m_entities.begin(),
        m_entities.end(),
        [entity_id](std::shared_ptr<Entity> entity)
        { return entity->getId() == entity_id; });

    if (entity_iterator != std::end(m_entities))
    {
        m_entities.erase(entity_iterator);
    }
} // how to do this??

void EntityManager::deleteEntity(int entity_id)
{
    auto entity_iterator = std::find_if(
        m_entities.begin(),
        m_entities.end(),
        [entity_id](std::shared_ptr<Entity> entity)
        { return entity->getId() == entity_id; });

    if (entity_iterator != std::end(m_entities))
    {
        m_entities.erase(entity_iterator);
    }
} // how to do this??

void EntityManager::spawnEntity(std::shared_ptr<Entity> entity)
{
    entity->setId(nextEntityId); // should the entity set this itself on construction?
    nextEntityId++;
    m_spawn_queue.push_back(entity);
}