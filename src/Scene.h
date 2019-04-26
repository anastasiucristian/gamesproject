#pragma once
#include "Menu.h"
#include "Level.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <vector>

const sf::Vector2f SCROLLING = {-0.1f,0.0f};

class Scene {
public:
	Scene();
	~Scene();
	int id;
	int name;
	virtual void Update();
	virtual void Load();
	virtual void Render();
	virtual char action_Keypress();

	void pushTexdSprite(sf::Sprite, sf::Texture*);
	void setBackground(sf::Texture &texture);

protected:
	std::vector <sf::Sprite *> sprites;
	std::vector <sf::Texture *> textures;
	sf::Sprite background;
	sf::Sprite backgroundScrollingBuffer;


	void setBackgroundScrolling(bool boolean) { scrollingEnabled = (!scrollingEnabled == boolean) ? boolean : scrollingEnabled; }
	void setScrollingVector(sf::Vector2f v) { scrollingVector = v; }

private:

	sf::Vector2f scrollingVector = SCROLLING;
	bool scrollingEnabled = false;
	void scrollBackground();
};


#ifndef Scene_Menu_H
#define Scene_Menu_H

class MainMenuHandler;
class Scene_Menu : public Scene
{
public:
	Scene_Menu();
	~Scene_Menu();
	void Update();
	void Load();
	void Render();
	std::vector<MenuButton*> getButtons();
	
	char action_Keypress() override;

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
	void Update();
	void Load();
	void Render();


private:

};

class Scene_Arena : public Scene
{
public:
	
	Scene_Arena();
	~Scene_Arena();
	void Update();
	void Load();
	void Render();
private:

};



