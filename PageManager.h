#pragma once

#include "StartPage.h"
#include "LevelPage.h"
#include "HighSoccerPage.h"
#include "GamePlayPage.h"
#include "Game_Medium_Play.h"
#include "Game_Hard_Play.h"
#include "IMapPlay.h"

class PagesManager
{

public:

	PagesManager(sf::RenderWindow* window) {

		this->_window = window;
		this->_currentPage = new StartPage(this->_window);
	}

	void HandleEvents(sf::Event*);
	void Display();

private:
	sf::RenderWindow* _window;
	BasePageClass* _currentPage = nullptr;

};
