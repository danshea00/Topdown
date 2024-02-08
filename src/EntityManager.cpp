#include "EntityManager.h"
#include <stduuid/uuid.h>

void EntityManager::updateEntities(sf::Time deltaTime)
{
    for (auto &entity : m_entities)
    {
        entity->update(deltaTime);
    }
}

void EntityManager::drawEntities(sf::RenderWindow m_window)
{
    for (auto &entity : m_entities)
    {
        entity->draw(m_window);
    }
}

void EntityManager::deleteEntity(uuid entity_id)
{
    auto is_even = [](int i)
    { return i % 2 == 0; };
    auto entity_iterator = std::find_if(
        m_entities.begin(),
        m_entities.end(),
        [](std::shared_ptr<Entity> *entity)
        { return entity->entity_id == entity_id; });

    if (entity_iterator != std::end(n_entities))
        m_entities.erase(entity_iterator)
} // how to do this??

void EntityManager::addEntity(std::shared_ptr<Entity> entity)
{
    m_entities.push_back(entity);
}