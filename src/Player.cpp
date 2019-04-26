#include "Player.h"
#include "Renderer.h"
#include "Settings.h"
#include <time.h>
#include <iostream>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

Player::Player() {
	jumpForce = -2;
	velocity = 1.1;
	gravity = 0.8;
	jumped = true;
	player = 1;
	rectmove = 4;
	score = 0;
	shoot = true;
	texture.loadFromFile(RES_DIRECTORY + "BlueDino.png");
	sprite.setTextureRect(sf::IntRect(0, 0, 24, 24));
	sprite.scale(3.0f, 3.0f);
	sprite.setTexture(texture);
}
Player::~Player() {}

void Player::faceOtherWay() {
	facingRight = !facingRight;
	//draw reverse
}

void Player::draw() {
	Renderer::instance()->draw(sprite);
}

void Player::player2() {
	sprite.setTextureRect(sf::IntRect(24*4, 0, -24, 24));
	facingRight = false;
	player = 2;
}


void Player::stopRunning() {
	rectmove = 4;
	if (facingRight) {
		sprite.setTextureRect(sf::IntRect(0, 0, 24, 24));
	}
	else {
		sprite.setTextureRect(sf::IntRect(24, 0, -24, 24));
	}
}

void Player::move(bool floorSolid) {
	if(stunned == false){ //if the player is not stunned
	if (player == 1) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !jumped) {
			//move with he jumping velocity
			sprite.move(0, jumpForce);
			//reduce the velocity
			jumpForce = jumpForce + 0.01;
			//jumped boolean can be only reset in the scene
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { //if pressing a(left)
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { //if not pressing d(right), so it won't cancel the move
				sprite.move(-velocity, 0);
				if (jumped || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { //if jumping or falling draw it strafing
					rectmove = 4;
					sprite.setTextureRect(sf::IntRect(24 * 12, 0, -24, 24));
				}
				else {	//else it's just runing
					sprite.setTextureRect(sf::IntRect(24 * rectmove, 0, -24, 24));
					rectmove++;
				}
				facingRight = false;
				if (rectmove == 12) {
					rectmove = 4;
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				sprite.move(velocity, 0);
				if (jumped || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
					rectmove = 4;
					sprite.setTextureRect(sf::IntRect(24 * 12, 0, 24, 24));
				}
				else {
					sprite.setTextureRect(sf::IntRect(24 * rectmove, 0, 24, 24));
					rectmove++;
				}

				facingRight = true;
				if (rectmove == 12) {
					rectmove = 4;
				}
			}
		}
	}
	else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !jumped) {
			//move with he jumping velocity
			sprite.move(0, jumpForce);
			//reduce the velocity
			jumpForce = jumpForce + 0.01;
			//jumped boolean can be only reset in the scene
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				sprite.move(-velocity, 0);
				if (jumped || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { //if jumping or falling draw it strafing
					rectmove = 4;
					sprite.setTextureRect(sf::IntRect(24 * 12, 0, -24, 24));
				}
				else {	//else it's just runing
					sprite.setTextureRect(sf::IntRect(24 * rectmove, 0, -24, 24));
					rectmove++;
				}
				facingRight = false;
				if (rectmove == 12) {
					rectmove = 4;
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				sprite.move(velocity, 0);
				if (jumped || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { //if jumping or falling draw it strafing
					rectmove = 4;
					sprite.setTextureRect(sf::IntRect(24 * 12, 0, 24, 24));
				}
				else {	//else it's just runing
					sprite.setTextureRect(sf::IntRect(24 * rectmove, 0, 24, 24));
					rectmove++;
				}
				facingRight = true;
				if (rectmove == 12) {
					rectmove = 4;
				}
			}
		}
	}
}
		//if player is not on gound it will fall
		if (!floorSolid) {
			sprite.move(0, gravity);
			onGround = false;
		}
		else {
			//if it's on the ground reset the jumping variables
			onGround = true;
			jumped = false; //hasn't jumped
			jumpForce = -3; //jumping velocity reset
		}
		//if it's stunned display crying sheet
		if (stunned) {
			if (facingRight) {
				sprite.setTextureRect(sf::IntRect(24 * 14, 0, 24, 24));
			}
			else {
				sprite.setTextureRect(sf::IntRect(24 * 15, 0, -24, 24));
			}
		}
	
}

void Player::setPosition(sf::Vector2f pos) {
	sprite.setPosition(pos);
}

sf::Vector2f Player::getPos() {
	return sprite.getPosition();
}
void Player::hasJumped() {
	jumped = true;
}

void Player::stun() {
	stunned = true;
}

void Player::unstun() {
	stunned = false;
	stopRunning();
}
void Player::canShoot() {
	shoot = true;
}
void Player::cantShoot() {
	shoot = false;
}
bool Player::getShoot() {
	return shoot;
}

bool Player::isFacingRight() {
	return facingRight;
}

void Player::greenDino() {
	texture.loadFromFile(RES_DIRECTORY + "GreenDino.png");
	sprite.setTexture(texture);
}

void Player::yellowDino() {
	texture.loadFromFile(RES_DIRECTORY + "YellowDino.png");
	sprite.setTexture(texture);
}

void Player::redDino() {
	texture.loadFromFile(RES_DIRECTORY + "RedDino.png");
	sprite.setTexture(texture);
}

bool Player::getStunned() {
	return stunned;
}

void Player::addScore() {
	score++;
}

int Player::getScore() {
	return score;
}