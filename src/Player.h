#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Bullet.h"

class Player : public Entity
{
public:
    Player(sf::Vector2f position, float speed);
    void move(sf::Vector2f movement);
    void draw(sf::RenderWindow &window);
    Bullet *shoot(sf::Vector2f mousePos);
    void beginAiming();
    void endAiming();

    sf::Vector2f getPosition();
    float getRadius();
    void update(sf::Time deltaTime);

private:
    sf::CircleShape m_circle;
    sf::Vector2f m_position;
    float m_speed;
    float m_theta;
    bool m_isAiming;

    std::vector<sf::Vertex> createLines(sf::Vector2f mousePos);
};

#endif // PLAYER_H
