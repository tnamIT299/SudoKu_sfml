#pragma once

#include<iostream>
#include <SFML/Graphics.hpp>

enum class GamePages
{
	None,
	StartPage,
	LevelPage,
	GamePlayPage_P,
	GamePlayPage_C,
	LoginPage,
	Sign_In,
	//EasyPage;
};

class BasePageClass
{

public:
	BasePageClass() {};
	BasePageClass(sf::RenderWindow* window) {
		this->_window = window;
	}

	virtual void Display() {}
	virtual void HandleEvents(sf::Event*) {}

	std::string _pageID{ " " };
	bool ChangePage{ false };
	GamePages NavTOPage{ GamePages::StartPage };

	sf::RenderWindow* _window = nullptr;

	bool IsMouseOverButton(const sf::RectangleShape&);

	void AlertWindow(sf::Font cFont, std::string AlertMessage, int Wx, int Wy, sf::Color bgcolor = sf::Color(138, 183, 248), sf::Color messageColor = sf::Color::Black);

};
