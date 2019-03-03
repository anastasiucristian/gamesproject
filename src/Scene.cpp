#include "Scene.h"
#include "Menu.h"
#include "Handler.h"

/*
The Function Declarations of the Following Classes are here:

1. Scene

2. Scene Menu
	- Load() : Set the Main Menu setup (Drawing of Buttons and Text)

*/

//Scene: Defines a set of sprites currently on screen.

Scene::Scene() {}

void Scene::Update(sf::RenderWindow &window)
{ 
	scrollBackground(window);
}

void Scene::Load(sf::RenderWindow &window) { window.clear(); }

void Scene::Render(sf::RenderWindow &window)
{
	window.draw(background);
	if (scrollingEnabled) { window.draw(backgroundScrollingBuffer); }

}

void Scene::setBackground(sf::Texture &texture)
{
	this->background.setTexture(texture);
	this->backgroundScrollingBuffer.setTexture(texture);
	this->backgroundScrollingBuffer.setPosition({(backgroundScrollingBuffer.getGlobalBounds().width),0});
}


void Scene::scrollBackground(sf::RenderWindow &window)
{
	if (!scrollingEnabled) { return; }
	
	//Scroll the Background
	background.move(scrollingVector);
	
	//Horizontal Negative_x Processing Only
	float x = background.getPosition().x;
	float width = background.getGlobalBounds().width;

	//Bind the Scrolling Buffer's Position to the Right of the Background
	backgroundScrollingBuffer.setPosition({ (x + width), 0 });

	//Reset the Background position when it is off-screen
	if (x <= (0-width)) { background.setPosition({ 0,0 });}
	
}
//==========================
//Scene_Menu : Scene

//Defines the 'Main Menu' scene (Buttons, Windows (Incomplete), etc.)

Scene_Menu::Scene_Menu() : Scene() 
{
	MainMenuHandler * handler = new MainMenuHandler(*this);
	this->handler = handler;
}

Scene_Menu::~Scene_Menu() 
{
	for each (MenuButton* button in buttons){delete button;}
	delete handler;
}

void Scene_Menu::Render(sf::RenderWindow &window)
{
	//Render the background from the Base Scene class
	Scene::Render(window);

	for each (MenuButton* button in buttons)
	{
		window.draw(button->baseSprite);
		window.draw(button->text);
		
	}
	
}

//Setup the Menu here:
void Scene_Menu::Load(sf::RenderWindow &window)
{
	Scene::Load(window);

	//Set Background Texture:
	sf::Texture * background_tex = new sf::Texture();
	background_tex->loadFromFile(SPRITE_CLOUDS);
	setBackground(*background_tex);
	setBackgroundScrolling(true);

	//Set Button Texture:
	sf::Texture * button_texture = new sf::Texture();
	button_texture->loadFromFile(SPRITE_BUTTON);

	//Set Button Text. Accesses Settings to get the default text font and style
	sf::Text text_Play = Settings::getInstance().getText("Play");
	sf::Text text_Settings = Settings::getInstance().getText("Settings");

	//Create Buttons
	MenuButton* playButton = new MenuButton(*button_texture, text_Play);
	MenuButton* settingsButton = new MenuButton(*button_texture, text_Settings);

	//Make sure to draw the Buttons. Position is automatically set with autoDraw function.
	autoDrawButton(playButton);
	autoDrawButton(settingsButton);	
}

void Scene_Menu::Update(sf::RenderWindow &window)
{
	Scene::Update(window);
	this->handler->Update(window);
}

std::vector<MenuButton*> Scene_Menu::getButtons() {return buttons; }

//Automatically set the position of Menu Buttons and Text
void Scene_Menu::autoDrawButton(MenuButton *button)
{
	
	float x = MENU_POSITION.x;
	float y = MENU_POSITION.y;

	float buttonHeight = button->baseSprite.getGlobalBounds().height;
	float buttonWidth = button->baseSprite.getGlobalBounds().width;

	//Add an interval depending on which button is inserted
	for (unsigned int i = 0; i < buttons.size(); i++)
	{
		y += MENU_INTERVAL + buttonHeight;
		
	}
	//Calculate the Central Position of the Button to place Text
	sf::Vector2f buttonCentre = { x + (buttonWidth / 2) , y + (buttonHeight / 2) };

	button->baseSprite.setPosition({ x,y });

	//Set the Text Position (Incomplete - Try for a better Version)
	button->text.setPosition({buttonCentre.x - (button->text.getGlobalBounds().width)/2 , buttonCentre.y-(button->text.getGlobalBounds().height) /2});
	
	//Add the button to the Vector array
	buttons.push_back(button);

}











