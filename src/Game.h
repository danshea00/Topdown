#include <cmath>
#include "Player.h"
#include "Bullet.h"

class Game {
public:
    Game();
    void run();
private:
    void handleEvents();
    void update(sf::Time deltaTime);
    void render();
    std::vector<sf::Vertex> createLines(sf::Vector2f playerPos, sf::Vector2i mousePos, float theta);
    sf::RenderWindow m_window;
    Player m_player;
    sf::Clock m_clock;
    float m_theta;
    bool m_isButtonHeld;
    std::vector<Bullet> m_bullets;
};
