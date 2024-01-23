#include <cmath>
#include "Entity.h"
#include "Player.h"
#include "Bullet.h"

class Game {
public:
    Game();
    void run();
    void spawn(Entity* entity);
private:
    void handleEvents();
    void update(sf::Time deltaTime);
    void render();
    sf::RenderWindow m_window;
    Player m_player;
    sf::Clock m_clock;
    bool m_isButtonHeld;
    std::vector<Bullet> m_bullets;
    // entities
    std::vector<Entity*> m_entities;

};
