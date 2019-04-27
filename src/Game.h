#pragma once
#include "Scene.h"


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


	//Scene_CharacterSelect c;
	//Scene *x = &c;


	

};

