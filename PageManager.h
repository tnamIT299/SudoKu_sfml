#pragma once

#include "StartPage.h"
#include "LevelPage.h"
#include "GamePlayPage.h"
#include "LoginPage.h"
#include "Sign_In.h"
#include "Register.h"
#include "Game_Medium_Play.h"
#include "Game_Hard_Play.h"
#include "IMapPlay.h"

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
