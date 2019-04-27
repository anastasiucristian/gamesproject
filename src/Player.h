#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <memory>
#include <time.h>

#include <SFML/Audio.hpp>
#pragma once

struct deltaRecorder
{
	sf::Vector2f prev;
	sf::Vector2f current;
};



class Player {
public:
	Player();
	~Player();
	void faceOtherWay();
	void draw();
	void move(bool floorSolid);
	void setPosition(sf::Vector2f pos);
	void hasJumped();
	void player2(); //sets player to 2
	void stopRunning();
	void stun();
	void unstun();
	bool getStunned();
	bool getShoot();
	void canShoot();
	void cantShoot();
	bool isFacingRight();
	sf::Vector2f getPos();
	void greenDino();
	void redDino();
	void yellowDino();
	void addScore();
	int getScore();

	bool deltaAlternator = false; //Alternates with every call to check motion direction by recording the previous position
	deltaRecorder rec;

	sf::Sprite getSprite() { return sprite; }

private:
	bool facingRight = true;
	float jumpForce;
	float velocity;
	float gravity;
	bool shoot;
	bool jumped;
	bool onGround;
	int rectmove;
	int score;
	bool stunned = false;
	int player; //for control presets
	sf::Texture texture;
	sf::Sprite sprite;
};