#pragma once
#include <SFML/Graphics.hpp>

class Settings{
  public:
    Settings(float width, float height);
    ~Settings();

    int selectedItemIndex;
    void draw (sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    void settingsSelect(sf::RenderWindow &window);

  private:
    sf::Texture menu[3];

};
