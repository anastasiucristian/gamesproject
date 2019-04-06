#include "Scene.h"
Scene_CharacterSelect::Scene_CharacterSelect() : Scene()
{

}

Scene_CharacterSelect::~Scene_CharacterSelect()
{

}

void Scene_CharacterSelect::Render(sf::RenderWindow &window)
{
	//Render the background from the Base Scene class
	Scene::Render(window);
}

//Setup the Menu here:
void Scene_CharacterSelect::Load(sf::RenderWindow &window)
{
	Scene::Load(window);

	//Set Background Texture:
	sf::Texture * background_tex = new sf::Texture();
	background_tex->loadFromFile(SPRITE_DEFAULT);
	setBackground(*background_tex);

	
}

void Scene_CharacterSelect::Update(sf::RenderWindow &window)
{
	Scene::Update(window);
	

}