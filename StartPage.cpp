﻿#include "StartPage.h"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"

void StartPage::setUp() {

	if (!this->_HeaderFont.loadFromFile("Fonts/07558_CenturyGothic.ttf")) {
		std::cout << "Error Loading Fonts" << std::endl;
		std::cout << "Shutting Down!" << std::endl;
		this->_window->close();
	}

	if (!this->_bgTexture.loadFromFile("Images/bg.jpg")) {
		std::cout << "Error Loading Images/bg.jpg" << std::endl;
		std::cout << "Shutting Down!" << std::endl;
		this->_window->close();
	}

	if (!this->buffer.loadFromFile("music/mixkit-arcade-game-jump-coin-216.wav"))
	{
		std::cout << "ERROR: Loading Sound Effect" << std::endl;
		this->_window->close();
	}
	sound.setBuffer(buffer);

	auto textureSize = this->_bgTexture.getSize();
	auto WindowSize = this->_window->getSize();

	auto ScaleX = (float)WindowSize.x / textureSize.x;
	auto ScaleY = (float)WindowSize.y / textureSize.y;

	this->_bgSprite.setTexture(this->_bgTexture);
	this->_bgSprite.setScale(ScaleX, ScaleY);

	this->_mainTitle.setFont(this->_HeaderFont);
	this->_mainTitle.setString("SuDoKu");
	this->_mainTitle.setCharacterSize(45);
	this->_mainTitle.setFillColor(sf::Color::Red);
	this->_mainTitle.setPosition(sf::Vector2f(this->_window->getSize().x / 2.2f - (4.f * 45.f) / 3.2f, this->_window->getSize().y / 6.5f));
	this->_mainTitle.setStyle(sf::Text::Bold);

	auto Posx = this->_window->getSize().x / 2.3f - (170.f / 3.5f);
	auto Posy = this->_window->getSize().y / 3.f;

	const auto height = 40.f;

	this->_LevelButton.setSize(sf::Vector2f(170.f, height));
	this->_LevelButton.setPosition(sf::Vector2f(Posx, Posy));
	this->_LevelButton.setFillColor(CaramelColor);

	this->_levelText.setFillColor(sf::Color::Black);
	this->_levelText.setFont(this->_HeaderFont);
	this->_levelText.setCharacterSize(18);
	this->_levelText.setString("Play Game");
	auto Framex = Posx + this->_LevelButton.getLocalBounds().width / 1.4f - (this->_LevelButton.getLocalBounds().width / 2.f);
	auto Framey = Posy + this->_LevelButton.getLocalBounds().height / 1.5f - (this->_LevelButton.getLocalBounds().height / 2.f);
	this->_levelText.setPosition(Framex, Framey);


	Posy += 65;
	this->_computerPlayButton.setSize(sf::Vector2f(170.f, height));
	this->_computerPlayButton.setPosition(sf::Vector2f(Posx, Posy));
	this->_computerPlayButton.setFillColor(CaramelColor);

	this->_computerPlayText.setFillColor(sf::Color::Black);
	this->_computerPlayText.setFont(this->_HeaderFont);
	this->_computerPlayText.setCharacterSize(18);
	this->_computerPlayText.setString("Computer Solve");
	Framex = Posx + this->_computerPlayButton.getLocalBounds().width / 1.7f - (this->_computerPlayButton.getLocalBounds().width / 2.f);
	Framey = Posy + this->_computerPlayButton.getLocalBounds().height / 1.5f - (this->_computerPlayButton.getLocalBounds().height / 2.f);
	this->_computerPlayText.setPosition(Framex, Framey);

	Posy += 65;
	this->_HighSoccerButton.setSize(sf::Vector2f(170.f, height));
	this->_HighSoccerButton.setPosition(sf::Vector2f(Posx, Posy));
	this->_HighSoccerButton.setFillColor(CaramelColor);

	this->_HighSoccerText.setFillColor(sf::Color::Black);
	this->_HighSoccerText.setFont(this->_HeaderFont);
	this->_HighSoccerText.setCharacterSize(18);
	this->_HighSoccerText.setString("High Soccer");
	Framex = Posx + this->_HighSoccerButton.getLocalBounds().width / 1.7f - (this->_HighSoccerButton.getLocalBounds().width / 2.f);
	Framey = Posy + this->_HighSoccerButton.getLocalBounds().height / 1.5f - (this->_HighSoccerButton.getLocalBounds().height / 2.f);
	this->_HighSoccerText.setPosition(Framex+15, Framey);

	Posy += 65;
	this->_exitButton.setSize(sf::Vector2f(170.f, height));
	this->_exitButton.setPosition(sf::Vector2f(Posx, Posy));
	this->_exitButton.setFillColor(CaramelColor);

	this->_exitButtonText.setFillColor(sf::Color::Black);
	this->_exitButtonText.setFont(this->_HeaderFont);
	this->_exitButtonText.setCharacterSize(18);
	this->_exitButtonText.setString("Quit");
	Framex = Posx + this->_exitButton.getLocalBounds().width / 1.15f - (this->_exitButton.getLocalBounds().width / 2.f);
	Framey = Posy + this->_exitButton.getLocalBounds().height / 1.5f - (this->_exitButton.getLocalBounds().height / 2.f);
	this->_exitButtonText.setPosition(Framex, Framey);
}

void StartPage::Display() {

	this->_window->clear(sf::Color::Black);
	this->_window->draw(this->_bgSprite);
	this->_window->draw(this->_mainTitle);
	this->_window->draw(this->_LevelButton);
	this->_window->draw(this->_levelText);
	this->_window->draw(this->_computerPlayButton);
	this->_window->draw(this->_computerPlayText);
	this->_window->draw(this->_HighSoccerButton);
	this->_window->draw(this->_HighSoccerText);
	this->_window->draw(this->_exitButton);
	this->_window->draw(this->_exitButtonText);

	this->_window->display();
}

void StartPage::OnFocusEvent() {

    if (this->IsMouseOverButton(this->_PlayGameButton)) {

		this->ChangePage = true;
		this->NavTOPage = GamePages::GamePlayPage_P;
	}

	else if (this->IsMouseOverButton(this->_LevelButton)) {

		this->ChangePage = true;
		this->NavTOPage = GamePages::LevelPage;
	}

	else if (this->IsMouseOverButton(this->_computerPlayButton)) {

		this->ChangePage = true;
		this->NavTOPage = GamePages::GamePlayPage_C;
	}
	else if (this->IsMouseOverButton(this->_HighSoccerButton)) {

		this->ChangePage = true;
		this->NavTOPage = GamePages::HighSoccerPage;
	}


	else if (this->IsMouseOverButton(this->_exitButton)) {

		this->_window->close();
	}
}

void StartPage::MouseMoveTigger() {
	
	if (this->IsMouseOverButton(this->_PlayGameButton)) {

		this->_PlayGameButton.setFillColor(sf::Color::White);
		this->_playGameText.setFillColor(sf::Color::Black);
		//this->sound.play();
		this->sound.play();
	}                                                                       //PlayGame Btn	
	else {
		this->_PlayGameButton.setFillColor(CaramelColor);
		this->_playGameText.setFillColor(sf::Color::Black);
	}

	if (this->IsMouseOverButton(this->_LevelButton)) {

		this->_LevelButton.setFillColor(sf::Color::White);
		this->_levelText.setFillColor(sf::Color::Black);
		this->sound.play();
	}                                                                       //Level Btn	
	else {
		this->_LevelButton.setFillColor(CaramelColor);
		this->_levelText.setFillColor(sf::Color::Black);
	}

	if (this->IsMouseOverButton(this->_computerPlayButton)) {

		this->_computerPlayButton.setFillColor(sf::Color::White);
		this->_computerPlayText.setFillColor(sf::Color::Black);
		this->sound.play();
	}                                                                       //CompPlay
	else {
		this->_computerPlayButton.setFillColor(CaramelColor);
		this->_computerPlayText.setFillColor(sf::Color::Black);
	}

	if (this->IsMouseOverButton(this->_HighSoccerButton)) {

		this->_HighSoccerButton.setFillColor(sf::Color::White);
		this->_HighSoccerText.setFillColor(sf::Color::Black);
		this->sound.play();
	}                                                                       //High soccer
	else {
		this->_HighSoccerButton.setFillColor(CaramelColor);
		this->_HighSoccerText.setFillColor(sf::Color::Black);
	}

	if (this->IsMouseOverButton(this->_exitButton)) {

		this->_exitButton.setFillColor(sf::Color::White);
		this->_exitButtonText.setFillColor(sf::Color::Black);
		this->sound.play();
	}                                                                       //exit
	else {
		this->_exitButton.setFillColor(CaramelColor);
		this->_exitButtonText.setFillColor(sf::Color::Black);
	}
}


void StartPage::HandleEvents(sf::Event* event) {

	if (event->type == sf::Event::MouseButtonPressed)
		this->OnFocusEvent();

	if (event->type == sf::Event::MouseMoved)
		this->MouseMoveTigger();
}