#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include "PlayingEntity.h"
#include "Bullet.h"

class Enemy : public PlayingEntity
{
public:
    Enemy(sf::Vector2f position);

    void shoot(sf::Vector2f aimLocation) override;
    void move(sf::Vector2f movement) override;
    void draw(sf::RenderWindow &window) override;
    void update(sf::Time deltaTime) override;

private:
    int timeTillShoot = 1000;
};

#endif // ENEMY_H
