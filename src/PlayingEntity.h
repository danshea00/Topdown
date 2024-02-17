#ifndef PLAYING_ENTITY_H
#define PLAYING_ENTITY_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Bullet.h"

/**
 * abstract away both the player and enemies in a super class
 */
class PlayingEntity : public Entity
{
public:
    PlayingEntity(sf::Vector2f position, sf::Color colour, std::string entityKey);
    virtual ~PlayingEntity();

    virtual void draw(sf::RenderWindow &window);
    virtual void move(sf::Vector2f movement) = 0;
    virtual void update(sf::Time deltaTime) = 0;
    virtual void shoot(sf::Vector2f aimLocation) = 0;
    // void beginAiming();
    // void endAiming();

    sf::Vector2f getPosition();
    float getRadius();

protected:
    sf::CircleShape m_circle;
};

#endif // PLAYER_H
