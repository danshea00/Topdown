#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "PlayingEntity.h"
#include "Bullet.h"

/**
 * Singleton entity manager class
 */
class EntityManager
{
protected:
    // maybe use map of id to entity ptr?? that could actually be quite good?
    
    // separate entities vector into players and bullets
    std::vector<std::shared_ptr<Bullet>> m_bullets;
    std::vector<std::shared_ptr<PlayingEntity>> m_players;

    std::vector<std::shared_ptr<Bullet>> m_spawning_bullets;
    std::vector<std::shared_ptr<PlayingEntity>> m_spawning_players;

    std::vector<EntityId> m_to_delete;

    int nextEntityId = 0;

    // Private Constructor
    EntityManager(){};
    // Stop the compiler generating methods of copy the object
    EntityManager(EntityManager const &copy) = delete;            // Not Implemented
    EntityManager &operator=(EntityManager const &copy) = delete; // Not Implemented

    void doForAllEntities(std::function<void(std::shared_ptr<Entity>)> f);
    void spawnEntitiesInQueue();
    void deleteEntitiesInQueue();
    void deleteEntity(EntityId entityId); 
    void processBulletCollisions();

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
    void spawnPlayingEntity(std::shared_ptr<PlayingEntity> entity);
    void spawnBullet(std::shared_ptr<Bullet> entity);

    void updateEntities(sf::Time deltaTime);
    void drawEntities(sf::RenderWindow &m_window);
    void processBulletCollision(
        std::shared_ptr<PlayingEntity> playingEnt,
        std::shared_ptr<Bullet> bulletPtr);
    void queueForDeletion(EntityId entityId);
};

#endif