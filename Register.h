#pragma once
#include "BasePageClass.h"

class Register : public BasePageClass
{

public:

	Register(sf::RenderWindow* window, bool regis) : BasePageClass(window)
	{
		this->_pageID = "Register";
		this->NavTOPage = GamePages::None;
		this->regis = regis;
		this->setUp();

	}

	bool regis; // if true bang register xuat hien
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
	sf::Sprite _bgSprite;
	sf::RectangleShape _UserButton;
	sf::RectangleShape _PassWordButton;
	sf::RectangleShape _ConfirmButton;
	sf::RectangleShape _RegisterButton;
	sf::Text _UserText;
	sf::Text _PasswordText;
	sf::Text _ConfirmPassText;
	sf::Text _RegisterText;
};
