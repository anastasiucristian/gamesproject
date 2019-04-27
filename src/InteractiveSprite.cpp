#pragma once
#include <SFML/Audio.hpp>
#include "Settings.h"
#include <SFML/Graphics.hpp>
#include "InteractiveSprite.h"


InteractHandler::InteractHandler(){}

InteractHandler::~InteractHandler() {}

void InteractHandler::onClick() {}; //Override

void InteractHandler::onHover() {}; //Override

void InteractHandler::offHover() {}; //Override

bool InteractHandler::action_MouseClick(sf::Vector2i mousePos, sf::Sprite sprite)
{
	if (isMouseClicked(mousePos, sprite))
	{
		onClick();	
		return true;
	}
	else {return false; }
}

//Perform the appropriate Hover Actions. onHover and offHover should be Overridden
bool InteractHandler::action_MouseHover(sf::Vector2i mousePos , sf::Sprite sprite)
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
bool InteractHandler::isMouseHovered(sf::Vector2i mousePos , sf::Sprite sprite) {
	sf::Vector2f mousePos_f = { (float)mousePos.x, (float)mousePos.y };
	sf::FloatRect bounds = sprite.getGlobalBounds();
	
	return (bounds.contains(mousePos_f)) ? true : false;

}

bool InteractHandler::isMouseClicked(sf::Vector2i mousePos, sf::Sprite sprite)
{
	float deltaTime = inputClock.restart().asMilliseconds();

	inputBuffer -= deltaTime;
	if (inputBuffer >= 0.0f) { return false;  }

	//sf::Sound sound;
	//sound.setBuffer(Settings::getInstance().buffer);
	//sound.play();

	if ((isMouseHovered(mousePos, sprite)) && (sf::Mouse::isButtonPressed(sf::Mouse::Left)))
	{
		resetBuffer();
		return true;
	}
	return false;
	
}



