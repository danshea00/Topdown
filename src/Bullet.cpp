#include "Bullet.h"
#include <cmath>

Bullet::Bullet(sf::Vector2f position, sf::Vector2f direction, float theta) :
    m_position(position)
{

    // Calculate the angle between the original direction and the x-axis
    float originalAngle = atan2(direction.y, direction.x);

    // Calculate the new direction vector using the modified angle
    float newAngle = originalAngle + ((float)rand() / RAND_MAX - 0.5f) * theta; // Randomize angle
    sf::Vector2f newDirection(cos(newAngle), sin(newAngle));

    m_direction = newDirection;

    m_circle.setRadius(5);
    m_circle.setFillColor(sf::Color::Red);
    m_circle.setPosition(m_position);
}

void Bullet::update(sf::Time deltaTime) {
    // Update the bullet position based on its direction and speed
    m_position += m_direction * BULLET_SPEED * deltaTime.asSeconds();
    m_circle.setPosition(m_position);
}

void Bullet::draw(sf::RenderWindow& window) {
    window.draw(m_circle);
}

bool Bullet::isOutOfBounds(sf::RenderWindow& window) {
    // Check if the bullet is out of the window bounds
    return (m_position.x < 0 || m_position.x > window.getSize().x ||
        m_position.y < 0 || m_position.y > window.getSize().y);
}