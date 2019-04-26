#pragma once
#include <SFML/Graphics.hpp>

#define INPUT_BUFFER_TIME 100;

class InteractHandler 
{
public:
	InteractHandler();
	~InteractHandler();

	bool action_MouseHover(sf::Vector2i mousePos, sf::Sprite sprite);
	bool action_MouseClick(sf::Vector2i mousePos, sf::Sprite sprite);
	

	
protected:
	
	virtual void onHover();
	virtual void offHover();
	virtual void onClick();

private:
	sf::Clock inputClock;
	float inputBuffer = INPUT_BUFFER_TIME;
	virtual bool isMouseHovered(sf::Vector2i mousePos, sf::Sprite sprite);
	virtual bool isMouseClicked(sf::Vector2i mousePos, sf::Sprite sprite);

	
	void resetBuffer() { inputBuffer = INPUT_BUFFER_TIME };
};
