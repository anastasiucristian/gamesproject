
#include "Scene.h"
#include "Game.h"
#include "Renderer.h"


void  Scene_Transition::Load()
{
	Scene::Load();

	//Set Background Texture:
	sf::Texture * background_tex = new sf::Texture();
	background_tex->loadFromFile(SPRITE_LOADING);
	setBackground(*background_tex);
	
}

void Scene_Transition::Update() 
{
	Scene::Update();

	float deltaTime = inputClock.restart().asMilliseconds();

	inputBuffer -= deltaTime;
	if (inputBuffer <= 0.0f) { Game::getManager().loadScene(target); }
}

void  Scene_Transition::Render() 
{
	Scene::Render();
}


void  Scene_Transition::floatAnimation() {}
