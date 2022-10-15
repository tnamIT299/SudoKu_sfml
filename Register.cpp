#include "Register.h"

void Register::setUp()
{
	if (!this->_HeaderFont.loadFromFile("Fonts/07558_CenturyGothic.ttf")) {
		std::cout << "Error Loading Fonts" << std::endl;
		std::cout << "Shutting Down!" << std::endl;
		this->_window->close();
	}

	if (!this->_bgTexture.loadFromFile("Images/pexels-faik-akmd-1025469.jpg")) {
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
	this->_mainTitle.setString("Register");
	this->_mainTitle.setCharacterSize(45);
	this->_mainTitle.setFillColor(sf::Color::Red);
	this->_mainTitle.setPosition(sf::Vector2f(this->_window->getSize().x / 2.2f - (4.f * 45.f) / 3.2f, this->_window->getSize().y / 6.5f));
	this->_mainTitle.setStyle(sf::Text::Bold);

	auto Posx = this->_window->getSize().x / 2.3f - (170.f / 3.5f);
	auto Posy = this->_window->getSize().y / 3.f;

	const auto height = 40.f;

	this->_UserButton.setSize(sf::Vector2f(170.f, height));
	this->_UserButton.setPosition(sf::Vector2f(Posx - 190, Posy));
	this->_UserButton.setFillColor(CaramelColor);

	this->_UserText.setFillColor(sf::Color::Black);
	this->_UserText.setFont(this->_HeaderFont);
	this->_UserText.setCharacterSize(18);
	this->_UserText.setString("User Name");
	auto Framex = Posx + this->_UserButton.getLocalBounds().width / 1.4f - (this->_UserButton.getLocalBounds().width / 2.f);
	auto Framey = Posy + this->_UserButton.getLocalBounds().height / 1.5f - (this->_UserButton.getLocalBounds().height / 2.f);
	this->_UserText.setPosition(Framex - 190, Framey);


	Posy += 65;
	this->_PassWordButton.setSize(sf::Vector2f(170.f, height));
	this->_PassWordButton.setPosition(sf::Vector2f(Posx - 190, Posy));
	this->_PassWordButton.setFillColor(CaramelColor);

	this->_PasswordText.setFillColor(sf::Color::Black);
	this->_PasswordText.setFont(this->_HeaderFont);
	this->_PasswordText.setCharacterSize(18);
	this->_PasswordText.setString("Password");
	Framex = Posx + this->_PassWordButton.getLocalBounds().width / 1.4f - (this->_PassWordButton.getLocalBounds().width / 2.f);
	Framey = Posy + this->_PassWordButton.getLocalBounds().height / 1.5f - (this->_PassWordButton.getLocalBounds().height / 2.f);
	this->_PasswordText.setPosition(Framex - 190, Framey);



	Posy += 65;
	this->_ConfirmButton.setSize(sf::Vector2f(170.f, height));
	this->_ConfirmButton.setPosition(sf::Vector2f(Posx - 190, Posy));
	this->_ConfirmButton.setFillColor(CaramelColor);

	this->_ConfirmPassText.setFillColor(sf::Color::Black);
	this->_ConfirmPassText.setFont(this->_HeaderFont);
	this->_ConfirmPassText.setCharacterSize(18);
	this->_ConfirmPassText.setString("Confirm Password");
	Framex = Posx + this->_ConfirmButton.getLocalBounds().width / 1.4f - (this->_ConfirmButton.getLocalBounds().width / 2.f);
	Framey = Posy + this->_ConfirmButton.getLocalBounds().height / 1.5f - (this->_ConfirmButton.getLocalBounds().height / 2.f);
	this->_ConfirmPassText.setPosition(Framex - 220, Framey);

	Posy += 65;
	this->_RegisterButton.setSize(sf::Vector2f(200.f, height));
	this->_RegisterButton.setPosition(sf::Vector2f(Posx, Posy + 40));
	this->_RegisterButton.setFillColor(CaramelColor);

	this->_RegisterText.setFillColor(sf::Color::Black);
	this->_RegisterText.setFont(this->_HeaderFont);
	this->_RegisterText.setCharacterSize(18);
	this->_RegisterText.setString("Register");
	Framex = Posx + this->_RegisterButton.getLocalBounds().width / 1.4f - (this->_RegisterButton.getLocalBounds().width / 2.f);
	Framey = Posy + this->_RegisterButton.getLocalBounds().height / 1.5f - (this->_RegisterButton.getLocalBounds().height / 2.f);
	this->_RegisterText.setPosition(Framex + 20, Framey + 40);

}

void Register::Display()
{
	this->_window->clear(sf::Color::Black);
	this->_window->draw(this->_bgSprite);
	this->_window->draw(this->_mainTitle);
	this->_window->draw(this->_UserButton);
	this->_window->draw(this->_UserText);
	this->_window->draw(this->_PassWordButton);
	this->_window->draw(this->_PasswordText);
	this->_window->draw(this->_ConfirmButton);
	this->_window->draw(this->_ConfirmPassText);
	this->_window->draw(this->_RegisterButton);
	this->_window->draw(this->_RegisterText);

	this->_window->display();
}

void Register::MouseMoveTigger()
{
	if (this->IsMouseOverButton(this->_RegisterButton)) {

		this->_RegisterButton.setFillColor(sf::Color::White);
		this->_RegisterText.setFillColor(CaramelColor);
	}                                                                       //Register Btn	
	else {
		this->_RegisterButton.setFillColor(CaramelColor);
		this->_RegisterText.setFillColor(sf::Color::Black);
	}

}

void Register::OnFocusEvent()
{

	if (this->IsMouseOverButton(this->_RegisterButton)) {

		this->ChangePage = true;
		this->NavTOPage = GamePages::StartPage;
	}
}

void Register::HandleEvents(sf::Event* event)
{

	if (event->type == sf::Event::MouseButtonPressed)
		this->OnFocusEvent();

	if (event->type == sf::Event::MouseMoved)
		this->MouseMoveTigger();
}


