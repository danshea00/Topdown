#include "EntityManager.h"
#include "Entity.h"
#include "Bullet.h"
#include <iostream>
#include <algorithm>

void EntityManager::processBulletCollisions()
{
    std::for_each(
        m_bullets.begin(),
        m_bullets.end(),
        [&](std::shared_ptr<Bullet> bulletPtr) {
            std::for_each(
                m_players.begin(),
                m_players.end(),
                [&](std::shared_ptr<PlayingEntity> playingEntity) {
                    if (bulletPtr->isIntersecting(playingEntity)){
                        processBulletCollision(playingEntity, bulletPtr);
                    }
                }
            );
        }
    );
}

void EntityManager::processBulletCollision(
    std::shared_ptr<PlayingEntity> playingEnt, 
    std::shared_ptr<Bullet> bulletPtr) {
    if (playingEnt->id != bulletPtr->m_shotBy) {
        // TODO MAGIC NUMBER
        playingEnt->takeDamage(0.1);
        queueForDeletion(bulletPtr->id);
    }
}

void EntityManager::queueForDeletion(EntityId entityId) {
    m_to_delete.push_back(entityId);
}   

void EntityManager::deleteEntity(EntityId entityId) {
    // find entity corresponding to ID
    auto num_erased = std::erase_if(
        m_bullets,
        [=](std::shared_ptr<Entity> entityPtr){return entityId == entityPtr->id;}
    );

    if (num_erased > 0) return;
    std::erase_if(
        m_players,
        [=](std::shared_ptr<Entity> entityPtr){return entityId == entityPtr->id;}
    );
}

void EntityManager::deleteEntitiesInQueue() {
    std::for_each(
        m_to_delete.begin(),
        m_to_delete.end(),
        [&](EntityId entityId){deleteEntity(entityId);}
    );

    m_to_delete.clear();
}

void EntityManager::doForAllEntities(std::function<void(std::shared_ptr<Entity>)> f) {
    std::for_each(
        m_bullets.begin(),
        m_bullets.end(),
        f
    );

    std::for_each(
        m_players.begin(),
        m_players.end(),
        f
    );
}

void EntityManager::spawnEntitiesInQueue()
{
    std::for_each(
        m_spawning_bullets.cbegin(),
        m_spawning_bullets.cend(),
        [this](std::shared_ptr<Bullet> bulletPtr){m_bullets.push_back(bulletPtr);}
    );

    std::for_each(
        m_spawning_players.cbegin(),
        m_spawning_players.cend(),
        [this](std::shared_ptr<PlayingEntity> playerPtr){m_players.push_back(playerPtr);}
    );

    m_spawning_bullets.clear();
    m_spawning_players.clear();
}
 
void EntityManager::updateEntities(sf::Time deltaTime)
{
    spawnEntitiesInQueue();
    deleteEntitiesInQueue();
    processBulletCollisions();
    doForAllEntities(
        [=] (std::shared_ptr<Entity> entityPtr) { 
            entityPtr->update(deltaTime);
        });
}

// todo -- read into const, nonconst and references
void EntityManager::drawEntities(sf::RenderWindow &m_window)
{
    doForAllEntities(
        [&](std::shared_ptr<Entity> entityPtr) {
            entityPtr->draw(m_window);
        });
}

 void EntityManager::spawnPlayingEntity(std::shared_ptr<PlayingEntity> entity)
 {
    entity->id = nextEntityId; 
    nextEntityId++;
    m_spawning_players.push_back(entity);
 }

void EntityManager::spawnBullet(std::shared_ptr<Bullet> entity)
{
    entity->id = nextEntityId;
    nextEntityId++;
    m_spawning_bullets.push_back(entity);
}
