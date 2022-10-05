#pragma once

#include "BasePageClass.h"

class LevelPage : public BasePageClass
{

public:

	LevelPage(sf::RenderWindow* window, bool level) : BasePageClass(window)
	{
		this->_pageID = "LevelPage";
		this->NavTOPage = GamePages::None;
		this->level =level ;
		this->setUp();

	}

	 bool level; // if true bang level xuat hien
     void Display() override ;
	 void HandleEvents(sf::Event*) override ;
	 const sf::Color CaramelColor = sf::Color(235, 114, 84);

private:
	void setUp();
	void MouseMoveTigger();
	void OnFocusEvent();
	sf::Font _HeaderFont;
	sf::Texture _bgTexture;
	sf::Text _mainTitle;
	sf::Sprite _bgSprite;
	sf::RectangleShape _level;
	sf::RectangleShape _EasyButton;
	sf::RectangleShape _MediumButton;
	sf::RectangleShape _HardButton;
	sf::RectangleShape _BackButton;
	sf::Text _EasyText;
	sf::Text _MediumText;
	sf::Text _HardText;
	sf::Text _BackText;
	const sf::Color LineColor = sf::Color(235, 114, 84);
};


