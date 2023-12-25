#include <cmath>
#include "Game.h"
#include "Player.h"
#include "Bullet.h"

Game::Game() : m_window(sf::VideoMode(2000, 1000), "Top-Down Game"),
               m_player(sf::Vector2f(200.0f, 300.0f), 2),
               m_isButtonHeld(false)
{
    spawn(&m_player);
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
    while (m_window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            m_window.close();
            break;
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                spawn(m_player.shoot(static_cast<sf::Vector2f>(sf::Mouse::getPosition(m_window))));
            }
            if (event.mouseButton.button == sf::Mouse::Right)
            {
                m_player.beginAiming();
            }
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Space)
            {
                m_player.beginAiming();
            }
            break;
        case sf::Event::KeyReleased:
            if (event.key.code == sf::Keyboard::Space)
            {
                m_player.endAiming();
            }
            break;
        default:
            break;
        }
    }
}

void Game::update(sf::Time deltaTime)
{

    for (auto &entity : m_entities)
    {
        entity->update(deltaTime);
    }
}

void Game::render()
{
    m_window.clear();

    for (auto &entity : m_entities)
    {
        entity->draw(m_window);
    }

    // Display the window contents
    m_window.display();
}

void Game::spawn(Entity *entity)
{
    m_entities.push_back(entity);
}