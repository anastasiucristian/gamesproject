#include "Scene.h"
Scene_CharacterSelect::Scene_CharacterSelect() : Scene()
{

}

Scene_CharacterSelect::~Scene_CharacterSelect()
{

}

void Scene_CharacterSelect::Render()
{
	//Render the background from the Base Scene class
	Scene::Render();
}

//Setup the Menu here:
void Scene_CharacterSelect::Load()
{
	Scene::Load();

	//Set Background Texture:
	sf::Texture * background_tex = new sf::Texture();
	background_tex->loadFromFile(SPRITE_DEFAULT);
	setBackground(*background_tex);

	
}

void Scene_CharacterSelect::Update()
{
	Scene::Update();
	

}