#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
// #include "Bullet.h

/**
 * Singleton entity manager class
 */
class EntityManager
{
protected:
    std::vector<std::shared_ptr<Entity>> m_entities;
    std::vector<std::shared_ptr<Entity>> m_spawn_queue;
    int nextEntityId = 0;

    // Private Constructor
    EntityManager(){};
    // Stop the compiler generating methods of copy the object
    EntityManager(EntityManager const &copy) = delete;            // Not Implemented
    EntityManager &operator=(EntityManager const &copy) = delete; // Not Implemented
public:
    static EntityManager &getInstance()
    {
        {
            // The only instance
            // Guaranteed to be lazy initialized
            // Guaranteed that it will be destroyed correctly
            static EntityManager instance;
            return instance;
        }
    }

    // return pointer to entity
    void spawnEntity(std::shared_ptr<Entity> entity);
    void deleteEntity(int entityId); // how to do this??
    void updateEntities(sf::Time deltaTime);
    void drawEntities(sf::RenderWindow &m_window);
};

#endif