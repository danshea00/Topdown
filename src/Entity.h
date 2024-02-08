#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <uuids>

class Entity
{
public:
    Entity();
    virtual ~Entity();

    bool operator==(Entity const &rhs) const
    {
        return entity_id == rhs.entity_id;
    }

    virtual void update(sf::Time deltaTime) = 0;
    virtual void draw(sf::RenderWindow &window) = 0;

    uuid const entity_id;

private:
};