#include <cmath>
#include "Game.h"
#include "Player.h"
#include "Bullet.h"

Game::Game() :
    m_window(sf::VideoMode(2000, 1000), "Top-Down Game"),
    m_player(sf::Vector2f(200.0f, 300.0f), 15),
    m_theta(1.0f),
    m_isButtonHeld(false)
{
    spawn(&m_player);
}

void Game::run() {
    while (m_window.isOpen()) {
        handleEvents();
        update(m_clock.restart());
        render();
    }
}

void Game::handleEvents() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            m_window.close();
            break;
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left) {
                spawn(new Bullet(m_player.getPosition(),
                    static_cast<sf::Vector2f>(sf::Mouse::getPosition(m_window))
                        - m_player.getPosition(),
                    m_theta)
                );
            }
            if (event.mouseButton.button == sf::Mouse::Right) {
                m_isButtonHeld = true;
            }
            break;
        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Right) {
                m_isButtonHeld = false;
            }
            break;
        default:
            break;
        }
    }
}

void Game::update(sf::Time deltaTime) {
    if (m_isButtonHeld) {
        if (m_theta > 0.1) {
            m_theta -= 0.005f;
        }
    }
    else {
        if (m_theta < 1.0f) {
            m_theta += 0.005f;
        }
    }
    for (auto& entity : m_entities) {
        entity->update(deltaTime);
    }
}

void Game::render() {
    m_window.clear();

    // Get the mouse position relative to the window
    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

    sf::Vector2f playerCenter = m_player.getPosition();
    // Create the lines vector using the createLines function
    std::vector<sf::Vertex> lines = createLines(playerCenter, mousePos, m_theta);

    // Draw the lines vector
    m_window.draw(&lines[0], lines.size(), sf::Lines);

    for (auto& entity : m_entities) {
        entity->draw(m_window);
    }
    m_player.draw(m_window);

    // Display the window contents
    m_window.display();

}

std::vector<sf::Vertex> Game::createLines(sf::Vector2f playerPos, sf::Vector2i mousePos, float theta) {
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

void Game::spawn(Entity* entity) {
    m_entities.push_back(entity);
}