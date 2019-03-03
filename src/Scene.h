#pragma once
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <vector>

const sf::Vector2f SCROLLING = {-0.1f,0.0f};
class Scene {
public:
	Scene();
	int id;
	int name;
	void Update(sf::RenderWindow &window);
	void Load(sf::RenderWindow &window);
	void Render(sf::RenderWindow &window);

	void setBackground(sf::Texture &texture);
	void setBackgroundScrolling(bool boolean) { scrollingEnabled = (!scrollingEnabled == boolean) ? boolean : scrollingEnabled; }
	void setScrollingVector(sf::Vector2f v) { scrollingVector = v; }

protected:
	std::vector <sf::Sprite *> sprites;
	std::vector <sf::Texture *> textures;
	sf::Sprite background;
	sf::Sprite backgroundScrollingBuffer;

private:

	sf::Vector2f scrollingVector = SCROLLING;
	bool scrollingEnabled = false;
	void scrollBackground(sf::RenderWindow &window);
};
#ifndef Scene_Menu_H
#define Scene_Menu_H

class MainMenuHandler;
class Scene_Menu : public Scene
{
public:
	Scene_Menu();
	~Scene_Menu();
	void Update(sf::RenderWindow &window);
	void Load(sf::RenderWindow &window);
	void Render(sf::RenderWindow &window);
	std::vector<MenuButton*> getButtons();

private:
	MainMenuHandler * handler;
	std::vector<MenuButton*> buttons;

	void autoDrawButton(MenuButton * button);


};

#endif




