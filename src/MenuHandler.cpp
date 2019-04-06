#include "Game.h"
#include "Menu.h"
#include "InteractiveSprite.h"
#include "Handler.h"
#include "Scene.h"

using namespace sf;
//Class MenuButton

MenuButton::MenuButton() : InteractHandler() {}

MenuButton::~MenuButton() 
{
	/*
	delete &baseSprite;
	delete &baseTexture;
	delete &text;
	*/
}

MenuButton::MenuButton(sf::Texture texture, sf::Text text) : InteractHandler()
{
	this->text = text;
	this->baseTexture = texture;
	this->baseSprite.setTexture(this->baseTexture);

}

//Customizable: What happens when Hovering on buttons
void MenuButton::onHover()
{
	//this->baseSprite.setScale({(float)1.2,(float)1.2});
	this->text.setColor(sf::Color::Red);
}

//Customizable: What happens when Hovering off buttons
void MenuButton::offHover()
{
	
	//this->baseSprite.setScale({ 1,1 });
	this->text.setColor(sf::Color::Black);
}

//Customizable: What happens when Hovering off buttons
void MenuButton::onClick()
{
	printf("Clicked");
	
	Game::getManager().loadScene();
	
	
}

MainMenuHandler::MainMenuHandler(Scene_Menu &menu) {this->scene_menu = &menu;}

void MainMenuHandler::Update(sf::RenderWindow &window)
{
	Vector2f mousePos = { (float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y };

	//Add Update Commands Here
	handleButtonHover(mousePos, window);
	handleButtonClick(mousePos, window);

}

void MainMenuHandler::handleButtonClick(sf::Vector2f mousePos , sf::RenderWindow &window)
{
	
	for each (MenuButton* button in scene_menu->getButtons())
	{
		button->action_MouseClick(mousePos, button->baseSprite);
	}
}


//Hovering Code Mechanic [For Each Button, Perform Action]
void MainMenuHandler::handleButtonHover(sf::Vector2f mousePos, sf::RenderWindow &window)
{
	
	for each (MenuButton* button in scene_menu->getButtons())
	{
		if (button->action_MouseHover(mousePos, button->baseSprite)) { break; } else { continue; }
	}
}





