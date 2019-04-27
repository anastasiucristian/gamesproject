#pragma once
#include "Menu.h"
#include "Level.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>

/*
Scene.h

Scene: Defines a set of sprites to be rendered (Buttons, Windows, etc.)

Contents:
1. Scene
2. Scene_Menu
3. Scene_CharacterSelect (Incomplete)
4. Scene_Arena
5. Scene_Transition

Author: Mark Pereira . Last Modified: 27/04/19 13:23
*/

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

	void setBackground(sf::Texture &texture);

	std::map<std::string,MenuWindow*> windows;
	


protected:

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
	static Scene_Menu& instance() { static Scene_Menu instance; return instance; }
	Scene_Menu();
	~Scene_Menu();
	void Update();
	void Load();
	void unload() { buttons.clear(); };
	void Render();
	std::vector<MenuButton*> getButtons() { return buttons; }
	
	char action_Keypress() override;
	void showToolTip(MenuButton);

private:
	MainMenuHandler * handler;
	std::vector<MenuButton*> buttons;

	MenuWindow * tooltip;

	void autoDrawButton(MenuButton * button);


};

#endif

struct MenuText
{
	int label;
	sf::Text text;
};


class Scene_CharacterSelect : public Scene
{
public:
	static Scene_CharacterSelect& instance() { static Scene_CharacterSelect instance; return instance; }
	Scene_CharacterSelect();
	~Scene_CharacterSelect();
	void Update();
	void Load();
	void Render();

	std::vector<MenuText*> texts;
	std::vector<MenuButton*> buttons;

private:
	void handleButtonHover(sf::Vector2i mousePos);
	void handleButtonClick(sf::Vector2i mousePos);

};


class Scene_Arena : public Scene
{
public:
	static Scene_Arena& instance() { static Scene_Arena instance; return instance; }
	Scene_Arena();
	~Scene_Arena(){}
	void Update();
	void Load();
	void Render();

	sf::Clock timeClock;
	float buffer = 30.0f;
	void resetBuffer() { buffer = 30.0f; };
private:
	//score board
	sf::Texture *scoreBoard = new sf::Texture();

	

};


#define LOADING_TIME 3000;
class Scene_Transition : public Scene
{
public:
	
	static Scene_Transition& instance(Scene *s)
	{	
		static Scene_Transition instance(s); 
 
		return instance; }
	Scene_Transition(Scene *s) { target = s; }
	~Scene_Transition() {}
	void Update();
	void Load();
	void Render();

private:
	Scene *target;

	sf::Sprite loadingSprite;
	sf::Texture loadingTexture;
	void floatAnimation();

	sf::Clock inputClock;
	float inputBuffer = LOADING_TIME;

	void resetBuffer() { inputBuffer = LOADING_TIME};


};



