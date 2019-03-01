#pragma once
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <vector>


class Scene {
public:
	Scene();
	int id;
	int name;
	void Load(sf::RenderWindow &window);
	void Render(sf::RenderWindow &window);
	void setBackground(sf::Texture &texture);


protected:
	std::vector <sf::Sprite *> sprites;
	std::vector <sf::Texture *> textures;

private:
	sf::Sprite background;
};


class Scene_Menu : public Scene
{
public:
	Scene_Menu();
	~Scene_Menu();
	void Update(sf::RenderWindow &window);
	void Load(sf::RenderWindow &window);
	void Render(sf::RenderWindow &window);
private:
	
	void drawButton(MenuButton * button);
	std::vector<MenuButton*> buttons;


};


