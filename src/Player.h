#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "PlayingEntity.h"
#include "Bullet.h"

class Player : public PlayingEntity
{
public:
    Player(sf::Vector2f position);

    // Bullet *shoot(sf::Vector2f mousePos);
    void beginAiming();
    void endAiming();

    // sf::Vector2f getPosition();
    // float getRadius();

    void shoot(sf::Vector2f aimLocation) override;
    void move(sf::Vector2f movement) override;
    void draw(sf::RenderWindow &window) override;
    void update(sf::Time deltaTime) override;

private:
    float m_speed;
    float m_theta;
    bool m_isAiming;

    std::vector<sf::Vertex> createLines(sf::Vector2f mousePos);
};

#endif // PLAYER_H
