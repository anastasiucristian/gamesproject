#pragma once
#include <SFML/Graphics.hpp>

#define INPUT_BUFFER_TIME 100;

class InteractiveSprite : public sf::Sprite
{
public:
	InteractiveSprite();
	~InteractiveSprite();

	bool action_MouseHover(sf::Vector2f mousePos, sf::Sprite sprite);
	bool action_MouseClick(sf::Vector2f mousePos, sf::Sprite sprite);

protected:
	
	virtual void onHover();
	virtual void offHover();
	virtual void onClick();

private:
	sf::Clock inputClock;
	float inputBuffer = INPUT_BUFFER_TIME;
	virtual bool isMouseHovered(sf::Vector2f mousePos, sf::Sprite sprite);
	virtual bool isMouseClicked(sf::Vector2f mousePos, sf::Sprite sprite);
	void resetBuffer() { inputBuffer = INPUT_BUFFER_TIME };
};
