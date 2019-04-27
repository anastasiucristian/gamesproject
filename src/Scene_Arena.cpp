#include "Scene.h"
#include "Level.h"
#include "Player.h"
#include "Bullet.h"
#include "Renderer.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <time.h>
#include <SFML/Audio.hpp>
#include <math.h>
//scene for the actual game but also lever builder

Level builder;//level builder
Player player1, player2; //the two players
sf::Text score;//score
Bullet b1, b2; //the two fireballs
sf::Sprite drawableLevel;//final background and level that will be drawn each iteration
sf::Vector2f p1pos, p2pos; //starting player positions
std::string scoreString;//string used for the scores
sf::Font font;//font for the scoreboard
sf::Vector2f cornerChecker1, cornerCheckerOld1, cornerChecker2, cornerCheckerOld2;//variables used for the corners of the players
sf::Vector2f tempPos; //variable used for collision and other rendering

Scene_Arena::Scene_Arena() : Scene()
{
	name = Scenes::scene_Game;
}

//=========Section Author: Mark Pereira==========

enum y_direction
{
	up,
	down,
	stationary
};


int get_y_direction(Player player)
{
	

	player.rec.prev = player.rec.current;
	player.rec.current = player.getSprite().getPosition();


	float p_y = (player.rec.prev.y);
	float c_y = (player.rec.current.y);
	
	
	if (p_y != c_y && abs(p_y-c_y > 0.1))
	{
		
		
		if (c_y - p_y < 0) { printf("Up");  return y_direction::up; }
		if (c_y - p_y > 0) { printf("Down"); return y_direction::down; }
	}
	else
	{
		return y_direction::stationary;
	}

	
	return y_direction::stationary;
}

bool isAbove(sf::Vector2f p1, sf::Vector2f p2, float height)
{
	return (p1.y-height/2 > p2.y+height/2) ? true : false;
}

bool jumpedOn(Player &player1, Player &player2)
{
	sf::FloatRect bounds1 = player1.getSprite().getGlobalBounds();
	sf::FloatRect bounds2 = player2.getSprite().getGlobalBounds();
	
	float height = player1.getSprite().getLocalBounds().height;

	bool down = false;
	if (get_y_direction(player1) != y_direction::up)
	{
		down = true;
	}

	if (bounds1.intersects(bounds2))
	{
		if (isAbove(player1.getPos(), player2.getPos(),height) && down==true)
		{
			printf("Player 1");
			return true;
		}

		if (isAbove(player2.getPos(), player1.getPos(), height) )
		{
			printf("Player 2");
			return false;
		}
		
	}
	return false;
}
//=========================
sf::Text *newText = new sf::Text();

void Scene_Arena::Render()
{


	//rendering level only, so it only has to be built once and redisplay a picture of it on each iteration
	//draw background and level
	builder.render();
	//score board
	sf::Texture *scoreBoard = new sf::Texture();
	scoreBoard->loadFromFile(RES_DIRECTORY + "ScorePlate.png");
	sf::Sprite drawBoard(*scoreBoard);
	drawBoard.setPosition(1400 / 2, 0);
	Renderer::instance()->draw(drawBoard);
	//capturing the final image
	sf::Image imgSnapshot = Renderer::instance()->capture();//capturing the final image
	sf::Texture textureSnapshot;//defying the texture
	textureSnapshot.loadFromImage(imgSnapshot);//loading the snapshot in the texture variable
	drawableLevel.setTexture(textureSnapshot);//setting the drawable as the loaded texture	

	while (Renderer::instance()->isOpen())
	{
		Renderer::instance()->clear();//clear the window
		Renderer::instance()->draw(drawableLevel);//draw level

		sf::Event event;//event mostly used for key releasing
		while (Renderer::instance()->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				Renderer::instance()->close();
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
				if (event.key.code == sf::Keyboard::Space) {//player1 shooting button
					tempPos = player1.getPos();//setting the y to the dino's mouth
					tempPos.y += 10;
					if (player1.getShoot()) {//if player can shoot
						player1.cantShoot();//cant shoot anymore(until bullet hits the other player or the level walls)
						if (player1.isFacingRight()) {
							tempPos.x += 40;//set the x coordinate for the collison
							b1.faceRight();//make the bullet face right
						}
						else {
							tempPos.x -= 40;//set the x coordinate for the collison
							b1.faceLeft();//make the bullet face left
						}
						b1.setPosition(tempPos);//set the position of the fireball(dragon's mouth + right oritentation)
					}
				}
				if (event.key.code == sf::Keyboard::Enter) {//player2 shooting button
					tempPos = player2.getPos();//setting the y to dino's mouth
					tempPos.y += 10;
					if (player2.getShoot()) {//if can shoot
						player2.cantShoot();//cant shoot anymore(until bullet hits the other player or the level walls)
						if (player2.isFacingRight()) {
							tempPos.x += 40;//set the x coordinate for the collison
							b2.faceRight();//make the bullet face right
						}
						else {
							tempPos.x -= 40;//set the x coordinate for the collison
							b2.faceLeft();//make the bullet face left
						}
						b2.setPosition(tempPos);//set the position of the fireball(dragon's mouth + right oritentation)
					}
				}
			}
		}

		player1.move(builder.tileSolid(player1.getPos()));//move player1
		player2.move(builder.tileSolid(player2.getPos()));//move player2
														  //if one of the players falls down, the level will be reset(players will be repositioned to their initial position, remaining player gets a point, bullets are reset for a new level)
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

		if (jumpedOn(player1, player2))
		{
			player1.stun();
		}

		if (jumpedOn(player2, player1))
		{
			player2.stun();
		}



		//if one of the player gets mariod while stunned reset levels(same as when falling)
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
			b1.hide();
		}
		if (b2.getPosition().x < 0 || b2.getPosition().x > 1920) {
			player2.canShoot();
			b2.hide();
		}

		//if p2 is on the right of p1 check if middle right side of bullet hits p2 and stuns him
		if (player1.getPos().x < player2.getPos().x) {
			if (b1.getPosition().x < player2.getPos().x && b1.getPosition().x > player2.getPos().x - 64 && b1.getPosition().y + 15 > player2.getPos().y && b1.getPosition().y + 15 < player2.getPos().y + 64) {
				player2.stun();
				b1.hide();
			}
		}
		else {//if it's on the left, if middle left part of the bullet hits p2 stuns him
			if (b1.getPosition().x - 45 < player2.getPos().x && b1.getPosition().x - 45 > player2.getPos().x - 64 && b1.getPosition().y + 15 > player2.getPos().y && b1.getPosition().y + 15 < player2.getPos().y + 64) {
				player2.stun();
				b1.hide();
			}
		}
		if (player2.getPos().x < player1.getPos().x) {
			if (b2.getPosition().x < player1.getPos().x && b2.getPosition().x > player1.getPos().x - 64 && b2.getPosition().y + 15 > player1.getPos().y && b2.getPosition().y + 15 < player1.getPos().y + 64) {
				player1.stun();
				b2.hide();
			}
		}
		else {//if it's on the left, if middle left part of the bullet hits p2 stuns him
			if (b2.getPosition().x - 45 < player1.getPos().x && b2.getPosition().x - 45 > player1.getPos().x - 64 && b2.getPosition().y + 15 > player1.getPos().y && b2.getPosition().y + 15 < player1.getPos().y + 64) {
				player1.stun();
				b2.hide();
			}
		}
		cornerChecker2 = player2.getPos();
		if (!player1.getShoot()) {
			b1.move();
		}
		if (!player2.getShoot()) {
			b2.move();
		}


		//if both players are hit, reset the level
		if (player1.getStunned() && player2.getStunned()) {
			player1.setPosition(p1pos);
			player2.setPosition(p2pos);
			player2.unstun();
			player1.unstun();
		}

		scoreString = std::to_string(player1.getScore());
		score.setString(scoreString);
		tempPos.x = 720;
		tempPos.y = -30;
		score.setPosition(tempPos);
		Renderer::instance()->draw(score);//draw player 1 score

						   //making it so the score won't be drawn outside the scorebox
		if (player2.getScore() < 10) {
			scoreString = "  " + std::to_string(player2.getScore());
		}
		else {
			scoreString = std::to_string(player2.getScore());
		}

		score.setString(scoreString);
		tempPos.x = 1030;
		score.setPosition(tempPos);


		player2.draw();//draw newly moved player
		player1.draw();//draw newly moved player
		b1.draw();
		b2.draw();
		Renderer::instance()->draw(score);

		Renderer::instance()->display();//display window
	}
	
}






//Setup the Menu here:
void Scene_Arena::Load()
{
	Scene::Load();

	//player preset: get player initial positionds, set the said positions and delete them from the map matrix
	p1pos = builder.getPlayer1();//get the positions
	p2pos = builder.getPlayer2();
	player1.setPosition(p1pos);//set the positions
	player2.setPosition(p2pos);
	builder.removePlayers();//delete from matrix
	player2.player2();//set player 2 with his commands
					  //hide the bullets(fireballs)

	player1.rec.current = p1pos;
	player2.rec.current = p2pos;


	b1.hide();
	b2.hide();
	//score preset
	font.loadFromFile(RES_DIRECTORY + "Fonts\\ARIALI.ttf");
	score.setFont(font);
	score.setCharacterSize(150);
	score.setColor(sf::Color::Red);
	//setting the first corner for collisions
	cornerChecker1 = player1.getPos();
	cornerChecker2 = player2.getPos();
	cornerChecker1.y += 64;
	//setting the dinosaur colour
	player1.greenDino();
}

void Scene_Arena::Update()
{
	Scene::Update();
}
