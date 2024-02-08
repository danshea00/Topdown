#include <cmath>
#include "Game.h"
#include "Player.h"
#include "Bullet.h"
#include "EntityManager.h"

Game::Game() : m_window(sf::VideoMode(2000, 1000), "Top-Down Game"), entityManager(EntityManager.getInstance())
                                                                         m_isButtonHeld(false)
{
    m_player = std::make_shared<Player>(sf::Vector2f(200.0f, 300.0f), 1);
    spawn(m_player);
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
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                m_player->shoot(mousePos);
            }
            if (event.mouseButton.button == sf::Mouse::Right)
            {
                m_player->beginAiming();
            }
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Space)
            {
                m_player->beginAiming();
            }
            break;
        case sf::Event::KeyReleased:
            if (event.key.code == sf::Keyboard::Space)
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
    entityManager.updateEntities()
}

void Game::render()
{
    m_window.clear();
    entityManager.drawEntities(m_window);

    // Display the window contents
    m_window.display();
}

void Game::spawn(std::shared_ptr<Entity> entity)
{
    entityManager.addEntity(entity)
}