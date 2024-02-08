#include <SFML/Graphics.hpp>
#include "PlayingEntity.h"
#include "Bullet.h"

auto RADIUS = 15;

PlayingEntity::PlayingEntity(sf::Vector2f position, float speed, sf::Color colour) : m_position(position),
                                                                                     m_speed(speed),

{

    m_circle.setRadius(RADIUS);
    m_circle.setFillColor(colour);
    m_circle.setPosition(m_position);
    m_circle.setOrigin(RADIUS, RADIUS);
}

void PlayingEntity::draw(sf::RenderWindow &window)
{
    window.draw(m_circle);
    // // Get the mouse position relative to the window
    // sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    // std::vector<sf::Vertex> lines = createLines(mousePos);
    // window.draw(&lines[0], lines.size(), sf::Lines);
}

sf::Vector2f PlayingEntity::getPosition()
{
    float radius = m_circle.getRadius();
    return m_position + sf::Vector2f(radius, radius);
}

float PlayingEntity::getRadius()
{
    return m_circle.getRadius();
}
