#ifndef PLAYING_ENTITY_H
#define PLAYING_ENTITY_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Bullet.h"

/** 
 *abstract away both the player and enemies in a super class
 */
class PlayingEntity : public Entity
{
public:
    PlayingEntity(sf::Vector2f position, sf::Color colour, std::function<void(void)> onDeath = [] () {});
    virtual ~PlayingEntity();

    double RADIUS = 15.0;

    virtual void draw(sf::RenderWindow &window) override;
    virtual void move(sf::Vector2f movement) = 0;
    virtual void shoot(sf::Vector2f aimLocation) = 0;
    // void beginAiming();
    // void endAiming();

    sf::FloatRect getGlobalBounds() override;

    sf::Vector2f getPosition();
    void takeDamage(float damage);
    int getHealth();

protected:
    std::function<void(void)> onDeath;
    virtual void handleDeath(); 
    sf::CircleShape m_circle;
    sf::RectangleShape m_health_bar;
    float m_health = 1;
};

#endif // PLAYER_H
