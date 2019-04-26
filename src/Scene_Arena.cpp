#include "Scene.h"
#include "Level.h"
#include "Player.h"
#include "Bullet.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <time.h>
#include <SFML/Audio.hpp>
//scene for the actual game but also lever builder

Level builder = Level();
Player player1, player2;
const int gameWidth = 1920;
const int gameHeight = 1080;

Scene_Arena::Scene_Arena() : Scene()
{

}

Scene_Arena::~Scene_Arena()
{
	
}

void Scene_Arena::Render(sf::RenderWindow &window)
{
	//setting the two players position with the one loaded from the map
	sf::Vector2f p1pos = builder.getPlayer1();
	sf::Vector2f p2pos = builder.getPlayer2();
	sf::Vector2f cornerChecker1, cornerCheckerOld1, cornerChecker2, cornerCheckerOld2;
	player1.setPosition(p1pos);
	player2.setPosition(p2pos);
	builder.removePlayers();
	//building the level onto the window
	builder.render(window);
	//capturing an image and redesplaying it on each frame as a "background" so it won't be built tile by tile each time
	sf::Image imgSnapshot = window.capture();
	sf::Texture textureSnapshot;
	textureSnapshot.loadFromImage(imgSnapshot);
	sf::Sprite drawableLevel(textureSnapshot);
	sf::Texture *scoreBoard = new sf::Texture();
	scoreBoard->loadFromFile(RES_DIRECTORY + "ScorePlate.png");
	sf::Sprite drawBoard(*scoreBoard);
	drawBoard.setPosition(1400/2,0);
	player2.player2();
	player1.greenDino();
	cornerChecker1 = player1.getPos();
	cornerChecker2 = player2.getPos();
	cornerChecker1.y += 64;
	sf::Time p1shot, p2shot;
	Bullet b1, b2;
	sf::Vector2f tempPos;
	tempPos.x = 2000;
	tempPos.y = 2000;
	b1.setPosition(tempPos);
	b2.setPosition(tempPos);
	player2.canShoot();
	while (window.isOpen())
	  {
		  sf::Event event;
		  while (window.pollEvent(event))
		  {
			  if (event.type == sf::Event::Closed)
				  window.close();
			  if (event.type == sf::Event::KeyReleased)
			  {
				  //when w is released the player can't jump anymore
				  //he will be able to when he hits the ground (player.cpp)
				  if (event.key.code == sf::Keyboard::W)
				  {
					  player1.hasJumped();
				  }
				  if (event.key.code == sf::Keyboard::Up)
				  {
					  player2.hasJumped();
				  }
				  if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::D)
				  {
					  player1.stopRunning();
				  }
				  if (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::Right)
				  {
					  player2.stopRunning();
				  }
			  }
			  if (event.type == sf::Event::KeyPressed) {
				  if (event.key.code == sf::Keyboard::Space) {
					  tempPos = player1.getPos();
					  tempPos.y += 10;					  
					  if (player1.getShoot()) {
						  player1.cantShoot();
						  if (player1.isFacingRight()) {
							  tempPos.x += 40;
							  b1.faceRight();
						  }
						  else {
							  tempPos.x -= 40;
							  b1.faceLeft();
						  }
						  b1.setPosition(tempPos);
					  }					  
				  }
				  if (event.key.code == sf::Keyboard::Enter) {
					  tempPos = player2.getPos();
					  tempPos.y += 10;
					  if (player2.getShoot()) {
						  player2.cantShoot();
						  if (player2.isFacingRight()) {
							  tempPos.x += 40;
							  b2.faceRight();
						  }
						  else {
							  tempPos.x -= 40;
							  b2.faceLeft();
						  }
						  b2.setPosition(tempPos);
					  }
				  }
			  }
		  }
		  window.clear();//clear
		  window.draw(drawableLevel);//draw level
		  window.draw(drawBoard);//draw score board
		  player1.move(builder.tileSolid(player1.getPos()));//move player
		  player2.move(builder.tileSolid(player2.getPos()));
		  //if one of the players falls down, the level will be reset(players will be repositioned to their initial position)
		  if (player1.getPos().y + 64 > 1080) {
			  player2.addScore();
			  player1.unstun();
			  player2.unstun();
			  player1.setPosition(p1pos);
			  player2.setPosition(p2pos);
		  }
		  if (player2.getPos().y + 64 > 1080) {
			  player1.addScore();
			  player1.unstun();
			  player2.unstun();
			  player1.setPosition(p1pos);
			  player2.setPosition(p2pos);
		  }
		  //if one of the player gets mariod while stunned reset levels
		  cornerCheckerOld1 = cornerChecker1;
		  cornerChecker1 = player1.getPos();
		  cornerChecker1.y += 64;
		  if (player2.getStunned()) {
			  //checking if p1 bottom left corner hits p2 top
			  if (cornerChecker1.x < player2.getPos().x + 64 && cornerChecker1.x > player2.getPos().x && cornerChecker1.y > player2.getPos().y && cornerCheckerOld1.y < player2.getPos().y) {
				  player1.setPosition(p1pos);
				  player2.setPosition(p2pos);
				  player2.unstun();
				  player1.addScore();
			  }
			  //checking if p1 bottom right corner hits p2 top
			  cornerChecker1.x += 64;
			  if (cornerChecker1.x < player2.getPos().x + 64 && cornerChecker1.x > player2.getPos().x && cornerChecker1.y > player2.getPos().y && cornerCheckerOld1.y < player2.getPos().y) {
				  player1.setPosition(p1pos);
				  player2.setPosition(p2pos);
				  player2.unstun();
				  player1.addScore();
			  }
		  }
		  cornerChecker1 = player1.getPos();

		  cornerCheckerOld2 = cornerChecker2;
		  cornerChecker2 = player2.getPos();
		  cornerChecker2.y += 64;
		  if (player1.getStunned()) {
			  //checking if p2 bottom left corner hits p1 top
			  if (cornerChecker2.x < player1.getPos().x + 64 && cornerChecker2.x > player1.getPos().x && cornerChecker2.y > player1.getPos().y && cornerCheckerOld2.y < player1.getPos().y) {
				  player1.setPosition(p1pos);
				  player2.setPosition(p2pos);
				  player2.addScore();
				  player1.unstun();
			  }
			  //checking if p2 bottom right corner hits p1 top
			  cornerChecker2.x += 64;
			  if (cornerChecker2.x < player1.getPos().x + 64 && cornerChecker2.x > player1.getPos().x && cornerChecker2.y > player1.getPos().y && cornerCheckerOld2.y < player1.getPos().y) {
				  player1.setPosition(p1pos);
				  player2.setPosition(p2pos);
				  player1.unstun();
				  player2.addScore();
			  }
		  }
		  //if bullets(fireballs) hit the edges, dispaly them under the screen(don't show them)
		  if (b1.getPosition().x < 0 || b1.getPosition().x > 1920) {
			  player1.canShoot();
			  tempPos.x = 2;
			  tempPos.y = 2000;
			  b1.setPosition(tempPos);
		  }
		  if (b2.getPosition().x < 0 || b2.getPosition().x > 1920) {
			  player2.canShoot();
			  tempPos.x = 2;
			  tempPos.y = 2000;
			  b2.setPosition(tempPos);
		  }
		  //if p2 is on the right of p1 check if middle right side of bullet hits p2 and stuns him
		  if (player1.getPos().x < player2.getPos().x) {
			  if (b1.getPosition().x < player2.getPos().x && b1.getPosition().x > player2.getPos().x - 64 && b1.getPosition().y + 15 > player2.getPos().y && b1.getPosition().y + 15 < player2.getPos().y + 64) {
				  player2.stun();
			  }
		  }
		  else {//if it's on the left, if middle left part of the bullet hits p2 stuns him
			  if (b1.getPosition().x - 45 < player2.getPos().x && b1.getPosition().x - 45 > player2.getPos().x - 64 && b1.getPosition().y + 15 > player2.getPos().y && b1.getPosition().y + 15 < player2.getPos().y + 64) {
				  player2.stun();
			  }
		  }
		  if (player2.getPos().x < player1.getPos().x) {
			  if (b2.getPosition().x < player1.getPos().x && b2.getPosition().x > player1.getPos().x - 64 && b2.getPosition().y + 15 > player1.getPos().y && b2.getPosition().y + 15 < player1.getPos().y + 64) {
				  player1.stun();
			  }
		  }
		  else {//if it's on the left, if middle left part of the bullet hits p2 stuns him
			  if (b2.getPosition().x - 45 < player1.getPos().x && b2.getPosition().x - 45 > player1.getPos().x - 64 && b2.getPosition().y + 15 > player1.getPos().y && b2.getPosition().y + 15 < player1.getPos().y + 64) {
				  player1.stun();
			  }
		  }
		  cornerChecker2 = player2.getPos();
		  b1.draw(window);
		  if (!player1.getShoot()) {
				b1.move();
		  }		
		  if (!player2.getShoot()) {
			  b2.move();
		  }
		  player2.draw(window);//draw newly moved player
		  player1.draw(window);//draw newly moved player
		  b1.draw(window);
		  b2.draw(window);
		  window.display();//display window
	  }
  }
  

//Setup the Menu here:
void Scene_Arena::Load(sf::RenderWindow &window)
{
  Scene::Load(window);
}

void Scene_Arena::Update(sf::RenderWindow &window)
{
	Scene::Update(window);
}
