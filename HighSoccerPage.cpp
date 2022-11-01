#include "HighSoccerPage.h"
#include "SFML/Audio.hpp"

void HighSoccerPage::setUp() {

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

	this->_soccer.setFillColor(sf::Color(209, 201, 178));
	this->_soccer.setSize(sf::Vector2f(500.f, 450.f));
	this->_soccer.setPosition(sf::Vector2f(this->_window->getSize().x / 2.7f - this->_soccer.getLocalBounds().width / 2.f,
		this->_window->getSize().y / 2.f - this->_soccer.getLocalBounds().height / 2.f));

	auto boardOriginX = this->_soccer.getPosition().x;
	auto boardOriginY = this->_soccer.getPosition().y;

	auto buttonX = boardOriginX + 43;
	auto ButtonY = boardOriginY - 55;

	this->_BackButton.setFillColor(LineColor);
	this->_BackButton.setSize(sf::Vector2f(133.f, 40.f));
	this->_BackButton.setPosition(sf::Vector2f(buttonX -20, ButtonY -60));

	this->_BackText.setFont(this->_HeaderFont);
	this->_BackText.setCharacterSize(18);
	this->_BackText.setFillColor(sf::Color::Black);

	float sizex;
	float sizey;

	if (this->hsoccer == true)
	{
		this->_BackText.setString("BACK");
		sizex = this->_BackText.getLocalBounds().width / 1.9f;
		sizey = this->_BackText.getLocalBounds().height / 1.6f;
		this->_BackText.setPosition(sf::Vector2f(buttonX + sizex , ButtonY + sizey -60));
	}

	else
	{
		//this->_BackText.setString("Back");
		//sizex = this->_BackText.getLocalBounds().width / 2.6f;
		//sizey = this->_BackText.getLocalBounds().height / 2.8f;
		//this->_BackText.setPosition(sf::Vector2f(buttonX + sizex, ButtonY + sizey));
	}

	this->_mainTitle.setFont(this->_HeaderFont);
	this->_mainTitle.setString("High Soccer");
	this->_mainTitle.setCharacterSize(45);
	this->_mainTitle.setFillColor(sf::Color::Red);
	this->_mainTitle.setPosition(sf::Vector2f(this->_window->getSize().x / 2.5f - (4.f * 45.f) / 3.2f, this->_window->getSize().y / 6.5f));
	this->_mainTitle.setStyle(sf::Text::Bold);
	
	auto Posx = this->_window->getSize().x / 2.3f - (170.f / 3.5f);
	auto Posy = this->_window->getSize().y / 3.f;

	const auto height = 40.f;

}

void HighSoccerPage::Display() {

	this->_window->clear(sf::Color::Black);
	this->_window->draw(this->_bgSprite);
	this->_window->draw(this->_mainTitle);
	this->_window->draw(this->_BackButton);
	this->_window->draw(this->_BackText);

	this->_window->display();
}

void HighSoccerPage::OnFocusEvent() {

    if (this->IsMouseOverButton(this->_BackButton)) {

		this->ChangePage = true;
		this->NavTOPage = GamePages::StartPage;
	}
}

void HighSoccerPage::MouseMoveTigger() {

	if (this->IsMouseOverButton(this->_BackButton)) {

		this->_BackButton.setFillColor(sf::Color::White);
		this->_BackText.setFillColor(sf::Color::Black);
		this->sound.play();
	}                                                                       //back btn
	else {
		this->_BackButton.setFillColor(CaramelColor);
		this->_BackText.setFillColor(sf::Color::Black);
	}

}


void HighSoccerPage::HandleEvents(sf::Event* event) {

	if (event->type == sf::Event::MouseButtonPressed)
		this->OnFocusEvent();

	if (event->type == sf::Event::MouseMoved)
		this->MouseMoveTigger();
}
