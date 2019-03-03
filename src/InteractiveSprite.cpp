#pragma once
#include "Settings.h"
#include <SFML/Graphics.hpp>
#include "InteractiveSprite.h"


InteractiveSprite::InteractiveSprite() : sf::Sprite() {}

InteractiveSprite::~InteractiveSprite() {}

void InteractiveSprite::onClick() {}; //Override

void InteractiveSprite::onHover() {}; //Override

void InteractiveSprite::offHover() {}; //Override

bool InteractiveSprite::action_MouseClick(sf::Vector2f mousePos, sf::Sprite sprite)
{
	if (isMouseClicked(mousePos, sprite))
	{
		onClick();	
		return true;
	}
	else {return false; }
}

//Perform the appropriate Hover Actions. onHover and offHover should be Overridden
bool InteractiveSprite::action_MouseHover(sf::Vector2f mousePos , sf::Sprite sprite)
{
	if (isMouseHovered(mousePos , sprite))
	{
		onHover(); 
		return true;
	}
	else
	{
		offHover();
		return false;
	}
};

//Checks if the Mouse if Hovering the designated sprite
bool InteractiveSprite::isMouseHovered(sf::Vector2f mousePos , sf::Sprite sprite) {
	
	return (sprite.getGlobalBounds().contains(mousePos)) ? true : false;

}

bool InteractiveSprite::isMouseClicked(sf::Vector2f mousePos, sf::Sprite sprite)
{
	float deltaTime = inputClock.restart().asMilliseconds();

	inputBuffer -= deltaTime;
	if (inputBuffer >= 0.0f) { return false;  }
	if ((isMouseHovered(mousePos, sprite)) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
	{
		resetBuffer();
		return true;
	}
	return false;
	
}



