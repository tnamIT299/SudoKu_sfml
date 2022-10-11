#include "Sign_In.h"


void Sign_In::setUp()
{
	if (!this->_HeaderFont.loadFromFile("Fonts/07558_CenturyGothic.ttf")) {
		std::cout << "Error Loading Fonts" << std::endl;
		std::cout << "Shutting Down!" << std::endl;
		this->_window->close();
	}

	if (!this->_bgTexture.loadFromFile("Images/log_in.jpg")) {
		std::cout << "Error Loading Images/log_in.jpg" << std::endl;
		std::cout << "Shutting Down!" << std::endl;
		this->_window->close();
	}

	auto textureSize = this->_bgTexture.getSize();
	auto WindowSize = this->_window->getSize();

	auto ScaleX = (float)WindowSize.x / textureSize.x;
	auto ScaleY = (float)WindowSize.y / textureSize.y;

	this->_bgSprite.setTexture(this->_bgTexture);
	this->_bgSprite.setScale(ScaleX, ScaleY);

	this->_mainTitle.setFont(this->_HeaderFont);
	this->_mainTitle.setString("Sign In");
	this->_mainTitle.setCharacterSize(45);
	this->_mainTitle.setFillColor(sf::Color::Red);
	this->_mainTitle.setPosition(sf::Vector2f(this->_window->getSize().x / 2.2f - (4.f * 45.f) / 3.2f, this->_window->getSize().y / 6.5f));
	this->_mainTitle.setStyle(sf::Text::Bold);

	auto Posx = this->_window->getSize().x / 2.3f - (170.f / 3.5f);
	auto Posy = this->_window->getSize().y / 3.f;

	const auto height = 40.f;

	this->_UserButton.setSize(sf::Vector2f(170.f, height));
	this->_UserButton.setPosition(sf::Vector2f(Posx, Posy));
	this->_UserButton.setFillColor(CaramelColor);

	this->_UserText.setFillColor(sf::Color::Black);
	this->_UserText.setFont(this->_HeaderFont);
	this->_UserText.setCharacterSize(18);
	this->_UserText.setString("User Name");
	auto Framex = Posx + this->_UserButton.getLocalBounds().width / 1.4f - (this->_UserButton.getLocalBounds().width / 2.f);
	auto Framey = Posy + this->_UserButton.getLocalBounds().height / 1.5f - (this->_UserButton.getLocalBounds().height / 2.f);
	this->_UserText.setPosition(Framex, Framey);


	Posy += 65;
	this->_PassWordButton.setSize(sf::Vector2f(170.f, height));
	this->_PassWordButton.setPosition(sf::Vector2f(Posx, Posy));
	this->_PassWordButton.setFillColor(CaramelColor);

	this->_PassWordText.setFillColor(sf::Color::Black);
	this->_PassWordText.setFont(this->_HeaderFont);
	this->_PassWordText.setCharacterSize(18);
	this->_PassWordText.setString("Password");
	Framex = Posx + this->_PassWordButton.getLocalBounds().width / 1.4f - (this->_PassWordButton.getLocalBounds().width / 2.f);
	Framey = Posy + this->_PassWordButton.getLocalBounds().height / 1.5f - (this->_PassWordButton.getLocalBounds().height / 2.f);
	this->_PassWordText.setPosition(Framex, Framey);

	Posy += 65;
	this->_Sign_InButton.setSize(sf::Vector2f(200.f, height));
	this->_Sign_InButton.setPosition(sf::Vector2f(Posx , Posy + 40));
	this->_Sign_InButton.setFillColor(CaramelColor);

	this->_Sign_InText.setFillColor(sf::Color::Black);
	this->_Sign_InText.setFont(this->_HeaderFont);
	this->_Sign_InText.setCharacterSize(18);
	this->_Sign_InText.setString("Sign In");
	Framex = Posx + this->_Sign_InButton.getLocalBounds().width / 1.4f - (this->_Sign_InButton.getLocalBounds().width / 2.f);
	Framey = Posy + this->_Sign_InButton.getLocalBounds().height / 1.5f - (this->_Sign_InButton.getLocalBounds().height / 2.f);
	this->_Sign_InText.setPosition(Framex + 20, Framey + 40);

}
void Sign_In::Display()
{
	this->_window->clear(sf::Color::Black);
	this->_window->draw(this->_bgSprite);
	this->_window->draw(this->_mainTitle);
	this->_window->draw(this->_UserButton);
	this->_window->draw(this->_UserText);
	this->_window->draw(this->_PassWordButton);
	this->_window->draw(this->_PassWordText);
	this->_window->draw(this->_Sign_InButton);
	this->_window->draw(this->_Sign_InText);

	this->_window->display();
}


void Sign_In::MouseMoveTigger()
{
	if (this->IsMouseOverButton(this->_Sign_InButton)) {

		this->_Sign_InButton.setFillColor(sf::Color::White);
		this->_Sign_InText.setFillColor(CaramelColor);
		//this->sound.play();
	}                                                                       //Sign_in Btn	
	else {
		this->_Sign_InButton.setFillColor(CaramelColor);
		this->_Sign_InText.setFillColor(sf::Color::Black);
	}
}

void Sign_In::OnFocusEvent()
{
	if (this->IsMouseOverButton(this->_Sign_InButton)) {

		this->ChangePage = true;
		this->NavTOPage = GamePages::StartPage;
	}
}

void Sign_In::HandleEvents(sf::Event* event)
{
	if (event->type == sf::Event::MouseButtonPressed)
		this->OnFocusEvent();

	if (event->type == sf::Event::MouseMoved)
		this->MouseMoveTigger();
}
