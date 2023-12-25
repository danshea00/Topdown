#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Bullet.h"

auto RADIUS = 15;

Player::Player(sf::Vector2f position, float speed) : m_position(position),
                                                     m_speed(speed), m_theta(1.0f)
{

    m_circle.setRadius(RADIUS);
    m_circle.setFillColor(sf::Color::Blue);
    m_circle.setPosition(m_position);
    m_circle.setOrigin(RADIUS, RADIUS);
}

void Player::update(sf::Time deltaTime)
{
    sf::Vector2f movement(0.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        movement.y -= 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        movement.x -= 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        movement.y += 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        movement.x += 1.f;
    }

    if (m_isAiming)
    {
        if (m_theta > 0.1)
        {
            m_theta -= 0.001f;
        }
    }
    else
    {
        if (m_theta < 1.0f)
        {
            m_theta += 0.005f;
        }
    }

    move(movement * float(deltaTime.asMilliseconds()));
}

void Player::move(sf::Vector2f movement)
{
    m_position += movement * m_speed;
    m_circle.setPosition(m_position);
}

void Player::draw(sf::RenderWindow &window)
{
    window.draw(m_circle);
    // Get the mouse position relative to the window
    sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    std::vector<sf::Vertex> lines = createLines(mousePos);
    window.draw(&lines[0], lines.size(), sf::Lines);
}

Bullet *Player::shoot(sf::Vector2f mousePos)
{
    return new Bullet(m_position, mousePos - m_position, m_theta);
}

void Player::beginAiming()
{
    m_isAiming = true;
}

void Player::endAiming()
{
    m_isAiming = false;
}

sf::Vector2f Player::getPosition()
{
    float radius = m_circle.getRadius();
    return m_position + sf::Vector2f(radius, radius);
}

float Player::getRadius()
{
    return m_circle.getRadius();
}

std::vector<sf::Vertex> Player::createLines(sf::Vector2f mousePos)
{
    auto playerPos = m_position;
    auto theta = m_theta;

    // Calculate the angle between the player and mouse positions
    float angle = atan2(mousePos.y - playerPos.y, mousePos.x - playerPos.x);

    // Calculate the endpoint positions of the two lines
    sf::Vector2f lineEnd1(playerPos.x + cos(angle + theta) * 300, playerPos.y + sin(angle + theta) * 300);
    sf::Vector2f lineEnd2(playerPos.x + cos(angle - theta) * 300, playerPos.y + sin(angle - theta) * 300);

    // Create an array of sf::Vertex objects representing the lines
    std::vector<sf::Vertex> lines = {
        sf::Vertex(playerPos, sf::Color::Green),
        sf::Vertex(lineEnd1, sf::Color::Yellow),
        sf::Vertex(playerPos, sf::Color::Green),
        sf::Vertex(lineEnd2, sf::Color::Yellow),
    };

    return lines;
}
