#pragma once
#include <SFML/Graphics.hpp>

class Entity {
public:
    Entity();
    virtual ~Entity();
    virtual void update(sf::Time deltaTime) = 0;
    virtual void draw(sf::RenderWindow& window) = 0;

private:
    // list of entities
};