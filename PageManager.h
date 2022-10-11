#pragma once

#include "StartPage.h"
#include "LevelPage.h"
#include "GamePlayPage.h"
#include "LoginPage.h"
#include "Sign_In.h"

class PagesManager
{

public:

	PagesManager(sf::RenderWindow* window) {

		this->_window = window;
		//this->_currentPage = new StartPage(this->_window);
		this->_currentPage = new LoginPage(this->_window);
	}

	void HandleEvents(sf::Event*);
	void Display();

private:
	sf::RenderWindow* _window;
	BasePageClass* _currentPage = nullptr;

};
