#include "InteractiveSprite.h"
InteractiveSprite::InteractiveSprite() : sf::Sprite() {}

InteractiveSprite::~InteractiveSprite() {}

void InteractiveSprite::onClick() {}; //Override

void InteractiveSprite::onHover() {}; //Override

void InteractiveSprite::offHover() {}; //Override


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

