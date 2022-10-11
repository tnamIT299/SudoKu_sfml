#pragma once
#pragma once

#include"BasePageClass.h"
#include"SFML/Audio.hpp"
#include"SFML/Graphics.hpp"

class LoginPage : public BasePageClass
{
public:

	LoginPage(sf::RenderWindow* window ) :BasePageClass(window) {
		this->setUp();
		this->_pageID = "LoginPage";
		this->NavTOPage = GamePages::None;
	}

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
	sf::RectangleShape _SignInButton;
	sf::RectangleShape _RegisterButton;
	sf::Text _SignInText;
	sf::Text _RegisterText;
};

