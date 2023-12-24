#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.h"

#define BULLET_SPEED 1000.0f
#define BULLET_RADIUS 3.0f

class Bullet : public Entity {
public:
    Bullet(sf::Vector2f position, sf::Vector2f direction, float theta);
    void update(sf::Time deltaTime);
    void draw(sf::RenderWindow& window);
    bool isOutOfBounds(sf::RenderWindow& window);
private:
    sf::CircleShape m_circle;
    sf::Vector2f m_position;
    sf::Vector2f m_direction;
};