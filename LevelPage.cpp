#include "LevelPage.h"
#include "SFML/Audio.hpp"

void LevelPage::setUp() {

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


	auto textureSize =this->_bgTexture.getSize();
	auto WindowSize = this->_window->getSize();

	auto ScaleX = (float)WindowSize.x / textureSize.x;
	auto ScaleY = (float)WindowSize.y / textureSize.y;

	this->_bgSprite.setTexture(this->_bgTexture);
	this->_bgSprite.setScale(ScaleX, ScaleY);

	this->_level.setFillColor(sf::Color(209, 201, 178));
	this->_level.setSize(sf::Vector2f(500.f, 450.f));
	this->_level.setPosition(sf::Vector2f(this->_window->getSize().x / 2.7f - this->_level.getLocalBounds().width / 2.f,
	this->_window->getSize().y / 2.f - this->_level.getLocalBounds().height / 2.f));

	auto boardOriginX = this->_level.getPosition().x;
	auto boardOriginY = this->_level.getPosition().y;

	auto buttonX = boardOriginX + 43;
	auto ButtonY = boardOriginY - 55;

	this->_BackButton.setFillColor(LineColor);
	this->_BackButton.setSize(sf::Vector2f(133.f, 40.f));
	this->_BackButton.setPosition(sf::Vector2f(buttonX, ButtonY));

	this->_BackText.setFont(this->_HeaderFont);
	this->_BackText.setCharacterSize(18);
	this->_BackText.setFillColor(sf::Color::Black);

	float sizex;
	float sizey;

	if (this->level == true)
	{
		this->_BackText.setString("BACK");
		sizex = this->_BackText.getLocalBounds().width / 1.2f;
		sizey = this->_BackText.getLocalBounds().height / 1.6f;
		this->_BackText.setPosition(sf::Vector2f(buttonX + sizex, ButtonY + sizey));
	}

	else
	{
		//this->_BackText.setString("Back");
		//sizex = this->_BackText.getLocalBounds().width / 2.6f;
	    //sizey = this->_BackText.getLocalBounds().height / 2.8f;
		//this->_BackText.setPosition(sf::Vector2f(buttonX + sizex, ButtonY + sizey));
	}

	this->_mainTitle.setFont(this->_HeaderFont);
	this->_mainTitle.setString("LEVEL");
	this->_mainTitle.setCharacterSize(45);
	this->_mainTitle.setFillColor(sf::Color::Red);
	this->_mainTitle.setPosition(sf::Vector2f(this->_window->getSize().x / 2.1f - (4.f * 45.f) / 3.2f, this->_window->getSize().y / 6.5f));
	this->_mainTitle.setStyle(sf::Text::Bold);

	auto Posx = this->_window->getSize().x / 2.3f - (170.f / 3.5f);
	auto Posy = this->_window->getSize().y / 3.f;

	const auto height = 40.f;
	this->_EasyButton.setSize(sf::Vector2f(170.f, height));
	this->_EasyButton.setPosition(sf::Vector2f(Posx, Posy));
	this->_EasyButton.setFillColor(CaramelColor);

	this->_EasyText.setFillColor(sf::Color::Black);
	this->_EasyText.setFont(this->_HeaderFont);
	this->_EasyText.setCharacterSize(18);
	this->_EasyText.setString("Easy");
	auto Framex = Posx + this->_EasyButton.getLocalBounds().width / 1.2f - (this->_EasyButton.getLocalBounds().width / 2.f);
	auto Framey = Posy + this->_EasyButton.getLocalBounds().height / 1.5f - (this->_EasyButton.getLocalBounds().height / 2.f);
	this->_EasyText.setPosition(Framex, Framey);


	Posy += 65;
	this->_MediumButton.setSize(sf::Vector2f(170.f, height));
	this->_MediumButton.setPosition(sf::Vector2f(Posx, Posy));
	this->_MediumButton.setFillColor(CaramelColor);

	this->_MediumText.setFillColor(sf::Color::Black);
	this->_MediumText.setFont(this->_HeaderFont);
	this->_MediumText.setCharacterSize(18);
	this->_MediumText.setString("Medium");
	Framex = Posx + this->_MediumButton.getLocalBounds().width / 1.2f - (this->_MediumButton.getLocalBounds().width / 2.f);
	Framey = Posy + this->_MediumButton.getLocalBounds().height / 1.5f - (this->_MediumButton.getLocalBounds().height / 2.f);
	this->_MediumText.setPosition(Framex-15, Framey);


	Posy += 65;
	this->_HardButton.setSize(sf::Vector2f(170.f, height));
	this->_HardButton.setPosition(sf::Vector2f(Posx, Posy));
	this->_HardButton.setFillColor(CaramelColor);

	this->_HardText.setFillColor(sf::Color::Black);
	this->_HardText.setFont(this->_HeaderFont);
	this->_HardText.setCharacterSize(18);
	this->_HardText.setString("Hard");
	Framex = Posx + this->_HardButton.getLocalBounds().width / 1.2f - (this->_HardButton.getLocalBounds().width / 2.f);
	Framey = Posy + this->_HardButton.getLocalBounds().height / 1.5f - (this->_HardButton.getLocalBounds().height / 2.f);
	this->_HardText.setPosition(Framex, Framey);


	Posy += 65;
	this->_Ice_BreakerButton.setSize(sf::Vector2f(170.f, height));
	this->_Ice_BreakerButton.setPosition(sf::Vector2f(Posx, Posy));
	this->_Ice_BreakerButton.setFillColor(CaramelColor);

	this->_Ice_BreakerText.setFillColor(sf::Color::Black);
	this->_Ice_BreakerText.setFont(this->_HeaderFont);
	this->_Ice_BreakerText.setCharacterSize(18);
	this->_Ice_BreakerText.setString("Ice-Breaker");
	Framex = Posx + this->_Ice_BreakerButton.getLocalBounds().width / 1.4f - (this->_Ice_BreakerButton.getLocalBounds().width / 2.f);
	Framey = Posy + this->_Ice_BreakerButton.getLocalBounds().height / 1.5f - (this->_Ice_BreakerButton.getLocalBounds().height / 2.f);
	this->_Ice_BreakerText.setPosition(Framex, Framey);
	



}

void LevelPage::Display() {

	this->_window->clear(sf::Color::Black);
	this->_window->draw(this->_bgSprite);
	this->_window->draw(this->_mainTitle);
	this->_window->draw(this->_EasyButton);
	this->_window->draw(this->_EasyText);
	this->_window->draw(this->_MediumButton);
	this->_window->draw(this->_MediumText);
	this->_window->draw(this->_HardButton);
	this->_window->draw(this->_HardText);
	this->_window->draw(this->_Ice_BreakerButton);
	this->_window->draw(this->_Ice_BreakerText);
	this->_window->draw(this->_BackButton);
	this->_window->draw(this->_BackText);
	
	this->_window->display();
}

void LevelPage::OnFocusEvent() {

	if (this->IsMouseOverButton(this->_EasyButton)) {

		this->ChangePage = true;
	    this->NavTOPage = GamePages::GamePlayPage_P;

	}

	else if (this->IsMouseOverButton(this->_MediumButton)) {

		this->ChangePage = true;
		this->NavTOPage = GamePages::Game_Medium_Play;
	}


	else if (this->IsMouseOverButton(this->_HardButton)) {

		this->ChangePage = true;
		this->NavTOPage = GamePages::Game_Hard_Play;
	}

	else if (this->IsMouseOverButton(this->_Ice_BreakerButton)) {

		this->ChangePage = true;
		this->NavTOPage = GamePages::IMapPlay;
	}


	else if (this->IsMouseOverButton(this->_BackButton)) {

		this->ChangePage = true;
		this->NavTOPage = GamePages::StartPage;
	}
}

void LevelPage::MouseMoveTigger() {

	if (this->IsMouseOverButton(this->_EasyButton)) {

		this->_EasyButton.setFillColor(sf::Color::White);
		this->_EasyText.setFillColor(sf::Color::Black);
		this->sound.play();
	}                                                                       //easy Btn	
	else {
		this->_EasyButton.setFillColor(CaramelColor);
		this->_EasyText.setFillColor(sf::Color::Black);
	}

	if (this->IsMouseOverButton(this->_MediumButton)) {

		this->_MediumButton.setFillColor(sf::Color::White);
		this->_MediumText.setFillColor(sf::Color::Black);
		this->sound.play();
	}                                                                       //medium Btn	
	else {
		this->_MediumButton.setFillColor(CaramelColor);
		this->_MediumText.setFillColor(sf::Color::Black);
	}

	if (this->IsMouseOverButton(this->_HardButton)) {

		this->_HardButton.setFillColor(sf::Color::White);
		this->_HardText.setFillColor(sf::Color::Black);
		this->sound.play();
	}                                                                       //hard btn
	else {
		this->_HardButton.setFillColor(CaramelColor);
		this->_HardText.setFillColor(sf::Color::Black);
	}

	if (this->IsMouseOverButton(this->_Ice_BreakerButton)) {

		this->_Ice_BreakerButton.setFillColor(sf::Color::White);
		this->_Ice_BreakerText.setFillColor(sf::Color::Black);
		this->sound.play();
	}                                                                       //ice-breaker btn
	else {
		this->_Ice_BreakerButton.setFillColor(CaramelColor);
		this->_Ice_BreakerText.setFillColor(sf::Color::Black);
	}

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


void LevelPage::HandleEvents(sf::Event* event) {

	if (event->type == sf::Event::MouseButtonPressed)
		this->OnFocusEvent();

	if (event->type == sf::Event::MouseMoved)
		this->MouseMoveTigger();
}
