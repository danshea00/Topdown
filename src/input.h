#ifndef INPUT_H
#define INPUT_H

#include <SFML/Window.hpp>

class Input
{
public:
    static bool IsKeyPressed(sf::Keyboard::Key key);
    static bool IsMouseButtonPressed(sf::Mouse::Button button);
    static sf::Vector2i GetMousePosition();
};

#endif // INPUT_H