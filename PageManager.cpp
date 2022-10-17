#include "PageManager.h"

void PagesManager::HandleEvents(sf::Event* event) {

	this->_currentPage->HandleEvents(event);
	//std::cout << this->_currentPage->_pageID << std::endl;
}

void PagesManager::Display() {

	if (this->_currentPage->ChangePage) {

		if (this->_currentPage->NavTOPage == GamePages::StartPage)
			this->_currentPage = new StartPage(this->_window);

		else if (this->_currentPage->NavTOPage == GamePages::LevelPage)
			this->_currentPage = new LevelPage(this->_window , true);

		else if (this->_currentPage->NavTOPage == GamePages::GamePlayPage_P)
			this->_currentPage = new GamePlayPage(this->_window, false);

		else if (this->_currentPage->NavTOPage == GamePages::Game_Medium_Play)
			this->_currentPage = new Game_Medium_Play(this->_window, false);

		else if (this->_currentPage->NavTOPage == GamePages::Game_Hard_Play)
			this->_currentPage = new Game_Hard_Play(this->_window, false);

		else if (this->_currentPage->NavTOPage == GamePages::IMapPlay)
			this->_currentPage = new IMapPlay(this->_window, false);

		else if (this->_currentPage->NavTOPage == GamePages::GamePlayPage_C)
			this->_currentPage = new GamePlayPage(this->_window, true);

		else if (this->_currentPage->NavTOPage == GamePages::HighSoccerPage)
			this->_currentPage = new HighSoccerPage(this->_window, true);

		return;
	}

	this->_currentPage->Display();
}
