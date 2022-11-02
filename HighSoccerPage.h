#pragma once

#include "BasePageClass.h"
#include "SFML/Audio.hpp"

class HighSoccerPage : public BasePageClass
{

public:

	HighSoccerPage(sf::RenderWindow* window, bool hsoccer) : BasePageClass(window)
	{
		this->_pageID = "HighSoccerPage";
		this->NavTOPage = GamePages::None;
		this->hsoccer = hsoccer;
		this->setUp();

	}

	bool hsoccer; // if true bang level xuat hien
	void Display() override;
	void HandleEvents(sf::Event*) override;
	const sf::Color CaramelColor = sf::Color(235, 114, 84);

private:
	void setUp();
	void MouseMoveTigger();
	void OnFocusEvent();
	sf::Font _HeaderFont;
	sf::Texture _bgTexture;
	sf::Text _mainTitle;
	sf::Text _highScore;
	sf::Text _highUser;
	sf::Sprite _bgSprite;
	sf::RectangleShape _soccer;
	/*sf::RectangleShape _EasyButton;
	sf::RectangleShape _MediumButton;
	sf::RectangleShape _HardButton;
	sf::RectangleShape _Ice_BreakerButton;*/
	sf::RectangleShape _BackButton;
	//sf::Text _HighSoccerText;
	/*sf::Text _EasyText;
	sf::Text _MediumText;
	sf::Text _HardText;
	sf::Text _Ice_BreakerText;*/
	sf::Text _BackText;
	sf::SoundBuffer buffer;
	sf::Sound sound;
	const sf::Color LineColor = sf::Color(235, 114, 84);
};


