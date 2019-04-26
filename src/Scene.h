#pragma once
#include "Settings.h"
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <SFML/Audio.hpp>

const sf::Vector2f SCROLLING = {-0.1f,0.0f};

class Scene {
public:
	Scene();
	int id;
	int name;
	virtual void Update(sf::RenderWindow &window);
	virtual void Load(sf::RenderWindow &window);
	virtual void Render(sf::RenderWindow &window);


protected:
	std::vector <sf::Sprite *> sprites;
	std::vector <sf::Texture *> textures;
	sf::Sprite background;
	sf::Sprite backgroundScrollingBuffer;

	void setBackground(sf::Texture &texture);
	void setBackgroundScrolling(bool boolean) { scrollingEnabled = (!scrollingEnabled == boolean) ? boolean : scrollingEnabled; }
	void setScrollingVector(sf::Vector2f v) { scrollingVector = v; }

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

class Scene_CharacterSelect : public Scene
{
public:
	Scene_CharacterSelect();
	~Scene_CharacterSelect();
	void Update(sf::RenderWindow &window);
	void Load(sf::RenderWindow &window);
	void Render(sf::RenderWindow &window);


private:



};

class Scene_Arena : public Scene
{
public:
	Scene_Arena();
	~Scene_Arena();
	void Update(sf::RenderWindow &window);
	void Load(sf::RenderWindow &window);
	void Render(sf::RenderWindow &window);
private:

};
