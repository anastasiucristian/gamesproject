#include "Menu.h"


using namespace sf;


MenuButton::MenuButton() {}

MenuButton::~MenuButton() {}

MenuButton::MenuButton(sf::Texture texture, sf::Text text)
{
	this->text = text;
	this->baseTexture = texture;
	this->baseSprite.setTexture(this->baseTexture);
}

/*
void MenuButton::onHover(sf::RenderWindow &window)
{
	this->text.setColor(sf::Color::Red);
}
*/
//==================================


MenuHandler::MenuHandler()
{
	//this->menu = &menu;
}

void MenuHandler::Update(sf::RenderWindow &window)
{
	handleButtonHover();

}

void MenuHandler::handleButtonHover()
{

	if (Keyboard::isKeyPressed(Keyboard::X)) {
		printf("X key pressed");
	}
}





