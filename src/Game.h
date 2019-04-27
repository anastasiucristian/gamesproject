#pragma once
#include "Scene.h"

/*
Game.h

Contains controller functions of the overall game (Scene Management, Switching, Rendering etc.)

Contents:
1. MenuButton
2. MenuWindow

Author: Mark Pereira . Last Modified: 27/04/19 12:00
*/

enum Scenes
{
	scene_mainMenu,
	scene_settings,
	scene_Game,

};

class Scene;
class Game
{
public:
	static Game& getManager() { static Game instance; return instance; }
	void startGame(Scene * target) //Only use for first scene
	{
		//Renderer::instance()->clear();
		runningScene = target; 
		runningScene->Load(); 
		
	}

	void loadScene(Scene * scene)
	{

		
		runningScene = scene;
		runningScene->Load();
	}

	void UpdateScene() {

		runningScene->Update();
	};

	void RenderScene() { runningScene->Render(); };

	Scene* getRunningScene() { return runningScene; };


private:
	Scene * runningScene;
	

};

