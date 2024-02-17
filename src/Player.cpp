#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

#include "Player.h"
#include "PlayingEntity.h"
#include "Bullet.h"
#include "EntityManager.h"

Player::Player(sf::Vector2f position) : PlayingEntity(position, sf::Color::Blue, "player"), m_theta(1.0f), m_speed(1.0f)
{
}

void Player::update(sf::Time deltaTime)
{
    auto movement = sf::Vector2f(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        movement.y -= 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        movement.x -= 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        movement.y += 1.f;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
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
    m_position += movement * ((2 - m_isAiming) * m_speed);
    m_circle.setPosition(m_position);
}

void Player::shoot(sf::Vector2f aimLocation)
{

    auto aimDirection = aimLocation - m_position;
    // Calculate the angle between the original direction and the x-axis
    float aimAngle = atan2(aimDirection.y, aimDirection.x);

    // Calculate the new direction vector using the modified angle
    float shootAngle = aimAngle + (float)(rand()) / (float)(RAND_MAX - 0.5f) * m_theta; // Randomize angle
    auto shootDirection = sf::Vector2f(cos(aimAngle), sin(aimAngle));

    auto bulletPtr = std::make_shared<Bullet>(m_position, shootDirection);
    auto &managerInstance = EntityManager::getInstance();
    managerInstance.spawnEntity(bulletPtr);
}

void Player::draw(sf::RenderWindow &window)
{
    window.draw(m_circle);
    // Get the mouse position relative to the window
    sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    std::vector<sf::Vertex> lines = createLines(mousePos);
    window.draw(&lines[0], lines.size(), sf::PrimitiveType::Lines);
}

void Player::beginAiming()
{
    m_isAiming = true;
}

void Player::endAiming()
{
    m_isAiming = false;
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
