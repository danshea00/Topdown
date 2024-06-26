#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Game.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "EntityManager.h"

Game::Game() : m_window(sf::VideoMode(sf::Vector2u(2000, 1000)), "Top-Down Game"), m_isButtonHeld(false)
{
    auto &managerInstance = EntityManager::getInstance();

    m_player = std::make_shared<Player>(sf::Vector2f(400.0f, 600.0f));
    managerInstance.spawnPlayingEntity(m_player);

    auto enemy1 = std::make_shared<Enemy>(sf::Vector2f(600.0f, 600.0f));
    managerInstance.spawnPlayingEntity(enemy1);
}

void Game::run()
{
    while (m_window.isOpen())
    {
        handleEvents();
        update(m_clock.restart());
        render();
    }
}

void Game::handleEvents()
{
    sf::Event event;
    auto mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(m_window));
    while (m_window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            m_window.close();
            break;
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Button::Left)
            {
                m_player->shoot(mousePos);
            }
            if (event.mouseButton.button == sf::Mouse::Button::Right)
            {
                m_player->beginAiming();
            }
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Key::Space)
            {
                m_player->beginAiming();
            }
            break;
        case sf::Event::KeyReleased:
            if (event.key.code == sf::Keyboard::Key::Space)
            {
                m_player->endAiming();
            }
            break;
        default:
            break;
        }
    }
}

void Game::update(sf::Time deltaTime)
{
    auto &managerInstance = EntityManager::getInstance();
    managerInstance.updateEntities(deltaTime);
}

void Game::render()
{
    auto &managerInstance = EntityManager::getInstance();
    m_window.clear();
    managerInstance.drawEntities(m_window);

    // Display the window contents
    m_window.display();
}
