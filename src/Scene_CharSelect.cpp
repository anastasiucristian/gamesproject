#include "Scene.h"
#include "Renderer.h"


enum settingsItems
{
	bt_prev,
	bt_next,
	txt_char_name,

};


Scene_CharacterSelect::Scene_CharacterSelect() : Scene()
{

}

Scene_CharacterSelect::~Scene_CharacterSelect()
{

}

void Scene_CharacterSelect::Render()
{
	//Render the background from the Base Scene class
	Scene::Render();
}

//Setup the Menu here:
void Scene_CharacterSelect::Load()
{
	Scene::Load();

	//Set Background Texture:
	sf::Texture * background_tex = new sf::Texture();
	background_tex->loadFromFile(SPRITE_DEFAULT);
	setBackground(*background_tex);


	
}

void Scene_CharacterSelect::Update()
{
	Scene::Update();

	//Add Update Commands Here
	sf::WindowBase *base = Renderer::instance();
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*base);

	handleButtonHover(mousePosition);
	handleButtonClick(mousePosition);

	//Set Button Texture:
	sf::Texture * button_texture = new sf::Texture();
	button_texture->loadFromFile(SPRITE_BUTTON);



	//Set Button Text. Accesses Settings to get the default text font and style
	sf::Text prev = Settings::getInstance().getText("<");
	sf::Text next = Settings::getInstance().getText(">");
	sf::Text play = Settings::getInstance().getText("Start Game");

	MenuText *charName = new MenuText();
	sf::Text txt_charname = Settings::getInstance().getText("Charname");
	
	charName->text = txt_charname;
	charName->label = settingsItems::txt_char_name;


	//Create Buttons
	MenuButton* prevButton = new MenuButton(*button_texture, prev);
	prevButton->setLabel(settingsItems::bt_prev);

	MenuButton* nextButton = new MenuButton(*button_texture, next);
	nextButton->setLabel(settingsItems::bt_next);


	MenuButton* playButton = new MenuButton(*button_texture, play);
	nextButton->setLabel(settingsItems::bt_next);

	
	sf::Vector2f cursor = { MENU_POSITION.x  ,  MENU_POSITION.y };
	
	prevButton->baseSprite.setPosition({ cursor.x,cursor.y });
	cursor.x += 30.0f;
	charName->text.setPosition({ cursor.x,cursor.y });
	cursor.x += 30.0f;
	nextButton->baseSprite.setPosition({ cursor.x,cursor.y });

	cursor.x = MENU_POSITION.x;
	cursor.y += 60.0f;
	playButton->baseSprite.setPosition({ cursor.x,cursor.y });


	buttons.push_back(prevButton);
	buttons.push_back(nextButton);
	buttons.push_back(playButton);
	texts.push_back(charName);

}


void Scene_CharacterSelect::handleButtonClick(sf::Vector2i mousePos)
{

	for each (MenuButton* button in Scene_CharacterSelect::instance().buttons)
	{

		button->action_MouseClick(mousePos, button->baseSprite);


	}

}


//Hovering Code Mechanic [For Each Button, Perform Action]
void Scene_CharacterSelect::handleButtonHover(sf::Vector2i mousePos)
{

	for each (MenuButton* button in Scene_CharacterSelect::instance().buttons)
	{
		if (button->action_MouseHover(mousePos, button->baseSprite));
	}
}
