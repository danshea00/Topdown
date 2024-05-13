#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

using EntityId = int;

class Entity
{
public:
    Entity(sf::Vector2f position);
    virtual ~Entity();

    EntityId id;

    bool operator==(Entity const &rhs) const
    {
        return id == rhs.id;
    }

    virtual void update(sf::Time deltaTime) = 0;
    virtual void draw(sf::RenderWindow &window) = 0;
    virtual sf::FloatRect getGlobalBounds() = 0;

    bool isIntersecting(std::shared_ptr<Entity> other);
    bool isOutOfBounds(sf::RenderWindow &window);

protected:
    sf::Vector2f m_position;


private:
};

#endif