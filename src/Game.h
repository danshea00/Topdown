#include <cmath>
#include "Entity.h"
#include "Player.h"
#include "Bullet.h"
#include "EntityManager.h"

class Game
{
public:
    Game();
    void run();
    void spawn(Entity *entity);

private:
    void handleEvents();
    void update(sf::Time deltaTime);
    void render();
    sf::RenderWindow m_window;
    std::shared_ptr<Player> m_player;
    sf::Clock m_clock;
    bool m_isButtonHeld;
    EntityManager entityManager;
};
