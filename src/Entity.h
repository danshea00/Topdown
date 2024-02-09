#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity
{
public:
    Entity();
    virtual ~Entity();

    void setId(int id);
    // use typedef?
    int getId();

    bool operator==(Entity const &rhs) const
    {
        return id == rhs.id;
    }

    virtual void update(sf::Time deltaTime) = 0;
    virtual void draw(sf::RenderWindow &window) = 0;

private:
    int id;
};

#endif