#pragma once
#include <SFML/Graphics.hpp>

#define INPUT_BUFFER_TIME 100;

/*
InteractiveSprite.h

Contains methods to handle 'Interactions' (Hovering, Clicking, etc.)

Contents:
1. InteractHandler

Author: Mark Pereira . Last Modified: 27/04/19 12:00
*/

class InteractHandler 
{
public:
	InteractHandler();
	~InteractHandler();

	
	//Performs following actions based on occurence
	bool action_MouseHover(sf::Vector2i mousePos, sf::Sprite sprite);
	bool action_MouseClick(sf::Vector2i mousePos, sf::Sprite sprite);
	

	
protected:
	
	//What to do when the following occur
	virtual void onHover();
	virtual void offHover();
	virtual void onClick();

private:
	sf::Clock inputClock;
	float inputBuffer = INPUT_BUFFER_TIME;

	//Check if following action occured
	virtual bool isMouseHovered(sf::Vector2i mousePos, sf::Sprite sprite);
	virtual bool isMouseClicked(sf::Vector2i mousePos, sf::Sprite sprite);

	
	void resetBuffer() { inputBuffer = INPUT_BUFFER_TIME };
};
