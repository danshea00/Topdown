#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

class Player {
public:
    Player(sf::Vector2f position, float speed);
    void move(sf::Vector2f movement);
    void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition();
    float getRadius();

private:
    sf::CircleShape m_circle;
    sf::Vector2f m_position;
    float m_speed;
};

#endif // PLAYER_H
