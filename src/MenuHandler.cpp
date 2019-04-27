#include "Menu.h"
#include "Game.h"
#include "Handler.h"
#include "Renderer.h"

using namespace sf;
//Class MenuButton

Scene_CharacterSelect scene_CharSelect;

MenuButton::MenuButton() : InteractHandler() {}

MenuButton::~MenuButton() 
{
	/*
	delete &baseSprite;
	delete &baseTexture;
	delete &text;
	*/
}

MenuButton::MenuButton(sf::Texture texture, sf::Text text) : InteractHandler()
{
	this->text = text;
	this->baseTexture = texture;
	this->baseSprite.setTexture(this->baseTexture);

}


//Customizable: What happens when Hovering on buttons
void MenuButton::onHover()
{
	if (Game::getManager().getRunningScene()->name == Scenes::scene_mainMenu)
	{
		Scene_Menu::instance().showToolTip(*this);
	}
	

	//this->baseSprite.setScale({(float)1.2,(float)1.2});
	this->text.setColor(sf::Color::Red);
}


//Customizable: What happens when Hovering off buttons
void MenuButton::offHover()
{
	
	Game::getManager().getRunningScene()->windows.clear();
	
	//this->baseSprite.setScale({ 1,1 });
	this->text.setColor(sf::Color::Black);
}

//Customizable: What happens when Hovering off buttons
void MenuButton::onClick()
{
	
	if (label == menuItems::play)
	{
		printf("Play");
		Scene_Menu::instance().unload();
		Scene *scene = &Scene_Transition::instance(&Scene_Arena::instance());
		//Scene * scene = &Scene_Arena::instance();
		Game::getManager().loadScene(scene);

	}

	if (label == menuItems::settings)
	{
		printf("Settings");
		Scene * scene = &scene_CharSelect;
		Game::getManager().loadScene(scene);
	}
	
	
	
}



void MainMenuHandler::Update()
{
	
	//Add Update Commands Here
	sf::WindowBase *base = Renderer::instance();
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*base);
	
	handleButtonHover(mousePosition);
	handleButtonClick(mousePosition);
	
	scene_menu->action_Keypress();

	

}

void MainMenuHandler::handleButtonClick(sf::Vector2i mousePos)
{
	
	for each (MenuButton* button in scene_menu->getButtons())
	{
	
		button->action_MouseClick(mousePos, button->baseSprite);
		

	}

}


//Hovering Code Mechanic [For Each Button, Perform Action]
void MainMenuHandler::handleButtonHover(sf::Vector2i mousePos)
{
	
	for each (MenuButton* button in scene_menu->getButtons())
	{
		if (button->action_MouseHover(mousePos, button->baseSprite));
	}
}





