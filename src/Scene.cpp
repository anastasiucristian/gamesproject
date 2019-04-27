#include "Scene.h"
#include "Game.h"
#include "Renderer.h"
#include "Handler.h"

/*
The Function Declarations of the Following Classes are here:

1. Scene

2. Scene Menu
	- Load() : Set the Main Menu setup (Drawing of Buttons and Text)

Author: Mark Pereira
*/


Scene::Scene() {  }

Scene::~Scene() {

}

void Scene::Update()
{ 
	
	scrollBackground();
}

void Scene::Load() { Renderer::instance()->clear(); }

//Render Background
void Scene::Render()
{
	Renderer::instance()->draw(background);
	if (scrollingEnabled) { Renderer::instance()->draw(backgroundScrollingBuffer); }

	

}

//Incomplete
char Scene::action_Keypress() { return '\0'; }

void Scene::setBackground(sf::Texture &texture)
{
	this->background.setTexture(texture);
	this->backgroundScrollingBuffer.setTexture(texture);
	this->backgroundScrollingBuffer.setPosition({(backgroundScrollingBuffer.getGlobalBounds().width),0});
}



//Background scroll logic
void Scene::scrollBackground()
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

//Set handler
Scene_Menu::Scene_Menu() : Scene() 
{
	this->name = Scenes::scene_mainMenu;

	MainMenuHandler * handler = new MainMenuHandler(*this);
	this->handler = handler;
}

Scene_Menu::~Scene_Menu() 
{
	for each (MenuButton* button in buttons){delete button;}
	delete handler;

}

void Scene_Menu::Render()
{
	//Render the background from the Base Scene class
	Scene::Render();

	//Render the buttons
	for each (MenuButton* button in buttons)
	{
		Renderer::instance()->draw(button->baseSprite);
		Renderer::instance()->draw(button->text);
		
	}

	//Render tooltip Windows (incomplete)
	for (auto &ent : windows) {
		
		Renderer::instance()->draw(ent.second->baseSprite);
	}

	
	
}


//Incomplete: Respond to Keypresses
char Scene_Menu::action_Keypress() 
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
	{
		
		return 'K';

	}

	return '\n';
}


//Setup the Menu here:
void Scene_Menu::Load()
{
	Scene::Load();

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

	sf::Text text_Quit = Settings::getInstance().getText("Quit");

	//Create Buttons
	MenuButton* playButton = new MenuButton(*button_texture, text_Play);
	playButton->setLabel(menuItems::play);

	MenuButton* settingsButton = new MenuButton(*button_texture, text_Settings);
	settingsButton->setLabel(menuItems::settings);

	MenuButton* exitButton = new MenuButton(*button_texture, text_Quit);
	exitButton->setLabel(menuItems::quit);
	

	
	//Make sure to draw the Buttons. Position is automatically set with autoDraw function.
	autoDrawButton(playButton);
	autoDrawButton(settingsButton);	
	autoDrawButton(exitButton);


}

void Scene_Menu::Update()
{
	Scene::Update();
	this->handler->Update();
}



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
		y += MENU_INTERVAL + buttonHeight/1.5;
		
	}
	//Calculate the Central Position of the Button to place Text
	sf::Vector2f buttonCentre = { x + (buttonWidth / 2) , y + (buttonHeight / 2) };

	button->baseSprite.setPosition({ x,y });

	//Set the Text Position (Incomplete - Try for a better Version)
	button->text.setPosition({buttonCentre.x - (button->text.getGlobalBounds().width)/2 , buttonCentre.y-(button->text.getGlobalBounds().height) /2});
	
	//Add the button to the Vector array
	buttons.push_back(button);

}

//Tooltip logic: Incomplete
void Scene_Menu::showToolTip(MenuButton button)
{
	if (button.getLabel()==menuItems::play)
	{
		//printf("Creating Tooltip");
		if (tooltip=nullptr )
		{
			
			//tooltip = new MenuWindow();
		

		}
		else
		{



		}
		
	}
}
