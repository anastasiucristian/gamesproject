#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include <time.h>

#pragma once
class Bullet {
public:
	Bullet();
	~Bullet();
	void faceLeft(); //change bullet direction
	void faceRight();
	void draw(); //draw the bullet
	void move();
	sf::Vector2f getPosition(); //get bullet position (for when collided with a player)
	void setPosition(sf::Vector2f pos); //set origin from when the bullet is movingRight

private:
	bool movingRight = true;
	float velocity;
	sf::Texture texture;
	sf::Sprite sprite;
};
