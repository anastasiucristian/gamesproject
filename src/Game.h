#pragma once
#include "Scene.h"




class Game
{
public:
	static Game& getManager() { static Game instance; return instance; }
	void startGame(sf::RenderWindow &window, Scene * target) //Only use for first scene
	{
		//window.clear();
		runningScene = target; 
		game_window = &window;
		runningScene->Load(*game_window); 
		
	}

	void loadScene()
	{

		
		//runningScene = x;
		//runningScene->Load(*game_window);
	}

	void UpdateScene() {

		runningScene->Update(*game_window);
	};

	void RenderScene() { runningScene->Render(*game_window); };

	Scene* getRunningScene() { return runningScene; };
	sf::RenderWindow &getWindow() { return *game_window; };

private:
	Scene * runningScene;
	sf::RenderWindow *game_window;

	//Scene_CharacterSelect c;
	//Scene *x = &c;


	

};

