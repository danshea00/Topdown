#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Enemy.h"
#include "PlayingEntity.h"
#include "Bullet.h"
#include <iostream>
#include "EntityManager.h"

Enemy::Enemy(sf::Vector2f position) : PlayingEntity(position, sf::Color::Red)
{
}

void Enemy::update(sf::Time deltaTime)
{
    timeTillShoot--;
    if (timeTillShoot <= 0)
    {
        this->shoot(sf::Vector2f(400.0f, 600.0f));
        timeTillShoot = 10000;
    }
}

void Enemy::move(sf::Vector2f movement)
{
}

void Enemy::shoot(sf::Vector2f aimLocation)
{
    auto newBullet = std::make_shared<Bullet>(m_position, aimLocation - m_position, this->id);
    auto &managerInstance = EntityManager::getInstance();
    managerInstance.spawnBullet(newBullet);
}
