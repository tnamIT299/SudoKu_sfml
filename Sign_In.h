#pragma once
#pragma once

#include"BasePageClass.h"
#include"SFML/Audio.hpp"
#include"SFML/Graphics.hpp"

class Sign_In : public BasePageClass
{
public:

	Sign_In(sf::RenderWindow* window , bool sign_in) :BasePageClass(window) {
		this->setUp();
		this->_pageID = "Sign_In";
		this->sign_in = sign_in;
		this->NavTOPage = GamePages::None;
	}
	bool sign_in;
	void Display() override;
	void HandleEvents(sf::Event*) override;

	const sf::Color CaramelColor = sf::Color(235, 114, 84);

private:
	void setUp();
	void MouseMoveTigger();
	void OnFocusEvent();
	sf::Texture _bgTexture;
	sf::Sprite _bgSprite;
	sf::Text _mainTitle;
	sf::Font _HeaderFont;
	sf::RectangleShape _UserButton;
	sf::RectangleShape _PassWordButton;
	sf::RectangleShape _Sign_InButton;
	sf::Text _UserText;
	sf::Text _PassWordText;
	sf::Text _Sign_InText;
};

