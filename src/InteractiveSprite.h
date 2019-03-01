
#pragma once
#include <SFML/Graphics.hpp>


class InteractiveSprite : public sf::Sprite
{
public:
	InteractiveSprite();
	~InteractiveSprite();
	virtual void onHover(sf::RenderWindow &window);
	virtual void onClick(sf::RenderWindow &window);


};
