#include "Bullet.h"
#include "Settings.h"
#include <time.h>
#include <iostream>

using namespace std;
using namespace sf;

Bullet::Bullet(){
  velocity = 1.1;
  texture.loadFromFile(RES_DIRECTORY + "Fireball.jpg");
  sprite.setTexture(texture);
}

Bullet::~Bullet(){}

void Bullet::faceLeft(){
	sprite.setTextureRect(sf::IntRect(45, 0, -45, 29));
	movingRight = false;
}
void Bullet::faceRight() {
	movingRight = true;
	sprite.setTextureRect(sf::IntRect(0, 0, 45, 29));
}
void Bullet::draw(sf::RenderWindow &window){
  window.draw(sprite);
}

void Bullet::move(){
  if(movingRight){
    sprite.move(velocity,0);
  }else{
    sprite.move(-velocity,0);
  }
}

sf::Vector2f Bullet::getPosition(){
  return sprite.getPosition();
}

void Bullet::setPosition(sf::Vector2f pos){
  sprite.setPosition(pos);
}
