#include "Menu.h"
#include "Scene.h"
#include "Handler.h"
#include "InteractiveSprite.h"

using namespace sf;
//Class MenuButton

MenuButton::MenuButton() : InteractiveSprite() {}

MenuButton::~MenuButton() {}

MenuButton::MenuButton(sf::Texture texture, sf::Text text) : InteractiveSprite()
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


MainMenuHandler::MainMenuHandler(Scene_Menu &menu) {this->scene_menu = &menu;}

void MainMenuHandler::Update(sf::RenderWindow &window)
{
	//Add Update Commands Here
	handleButtonHover(window);

}

//Hovering Code Mechanic [For Each Button, Perform Action]
void MainMenuHandler::handleButtonHover(sf::RenderWindow &window)
{
	Vector2f mousePos = { (float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y };
	
	for each (MenuButton* button in scene_menu->getButtons())
	{
		if (button->action_MouseHover(mousePos, button->baseSprite)) { break; } else { continue; }

	}
}





