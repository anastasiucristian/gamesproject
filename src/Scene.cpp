#include "Scene.h"
#include "Menu.h"

//==========================
//Scene: Parent Class. Defines a set of sprites currently on screen.

Scene::Scene() {}

void Scene::Load(sf::RenderWindow &window)
{
	window.clear();

}

void Scene::Render(sf::RenderWindow &window)
{
	window.draw(background);

	
}

void Scene::setBackground(sf::Texture &texture)
{
	this->background.setTexture(texture);
}


//==========================
//Scene_Menu : Scene

//Defines the 'Main Menu' scene

Scene_Menu::Scene_Menu() : Scene() {}

Scene_Menu::~Scene_Menu() {  }

void Scene_Menu::Render(sf::RenderWindow &window)
{
	//Render the background
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

	//Set Button Texture:
	sf::Texture * button_texture = new sf::Texture();
	button_texture->loadFromFile(SPRITE_BUTTON);

	//Set Button Text. Accesses Settings to get the default text font and style
	sf::Text text_Play = Settings::getInstance().getText("Play");
	sf::Text text_Settings = Settings::getInstance().getText("Settings");

	//Create Buttons
	MenuButton* playButton = new MenuButton(*button_texture, text_Play);
	MenuButton* settingsButton = new MenuButton(*button_texture, text_Settings);


	drawButton(playButton);
	drawButton(settingsButton);	
}

void Scene_Menu::Update(sf::RenderWindow &window)
{
	//handler->Update(window);
}

void Scene_Menu::drawButton(MenuButton *button)
{
	
	float x = MENU_POSITION.x;
	float y = MENU_POSITION.y;

	float buttonHeight = button->baseSprite.getGlobalBounds().height;
	float buttonWidth = button->baseSprite.getGlobalBounds().width;

	

	//Set position depending on which button is inserted
	for (unsigned int i = 0; i < buttons.size(); i++)
	{
		y += MENU_INTERVAL + buttonHeight;
		
	}
	sf::Vector2f buttonCentre = { x + (buttonWidth / 2) , y + (buttonHeight / 2) };

	button->baseSprite.setPosition({ x,y });

	button->text.setPosition({buttonCentre.x - (button->text.getGlobalBounds().width)/2 , buttonCentre.y-(button->text.getGlobalBounds().height) /2});
	buttons.push_back(button);

}







