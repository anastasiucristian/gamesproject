#pragma once
#include <SFML/Graphics.hpp>


class InteractiveSprite : public sf::Sprite
{
public:
	InteractiveSprite();
	~InteractiveSprite();

	virtual bool action_MouseHover(sf::Vector2f mousePos, sf::Sprite sprite);
	

protected:
	
	virtual void onHover();
	virtual void offHover();
	virtual void onClick();

private:
	virtual bool isMouseHovered(sf::Vector2f mousePos, sf::Sprite sprite);

};
