#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity
{
public:
    Entity(sf::Vector2f position, std::string entityKey);
    virtual ~Entity();

    void setId(int id);
    // use typedef?
    int getId();
    std::string getEntityKey();

    bool operator==(Entity const &rhs) const
    {
        return id == rhs.id;
    }

    virtual void update(sf::Time deltaTime) = 0;
    virtual void draw(sf::RenderWindow &window) = 0;

protected:
    sf::Vector2f m_position;

private:
    int id;
    std::string m_entity_key;
};

#endif