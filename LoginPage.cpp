#include "LoginPage.h"

void LoginPage::setUp()
{
	//sf::RenderWindow window(sf::VideoMode(600, 900), "Log In", sf::Style::Titlebar | sf::Style::Close);
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
	this->_mainTitle.setString("Accout");
	this->_mainTitle.setCharacterSize(45);
	this->_mainTitle.setFillColor(sf::Color::Red);
	this->_mainTitle.setPosition(sf::Vector2f(this->_window->getSize().x / 2.2f - (4.f * 45.f) / 3.2f, this->_window->getSize().y / 6.5f));
	this->_mainTitle.setStyle(sf::Text::Bold);

	auto Posx = this->_window->getSize().x / 2.3f - (170.f / 3.5f);
	auto Posy = this->_window->getSize().y / 3.f;

	const auto height = 40.f;

	this->_SignInButton.setSize(sf::Vector2f(170.f, height));
	this->_SignInButton.setPosition(sf::Vector2f(Posx, Posy));
	this->_SignInButton.setFillColor(CaramelColor);

	this->_SignInText.setFillColor(sf::Color::Black);
	this->_SignInText.setFont(this->_HeaderFont);
	this->_SignInText.setCharacterSize(18);
	this->_SignInText.setString("Sign In");
	auto Framex = Posx + this->_SignInButton.getLocalBounds().width / 1.4f - (this->_SignInButton.getLocalBounds().width / 2.f);
	auto Framey = Posy + this->_SignInButton.getLocalBounds().height / 1.5f - (this->_SignInButton.getLocalBounds().height / 2.f);
	this->_SignInText.setPosition(Framex, Framey);


	Posy += 65;
	this->_RegisterButton.setSize(sf::Vector2f(170.f, height));
	this->_RegisterButton.setPosition(sf::Vector2f(Posx, Posy));
	this->_RegisterButton.setFillColor(CaramelColor);

	this->_RegisterText.setFillColor(sf::Color::Black);
	this->_RegisterText.setFont(this->_HeaderFont);
	this->_RegisterText.setCharacterSize(18);
	this->_RegisterText.setString("Register");
	Framex = Posx + this->_RegisterButton.getLocalBounds().width / 1.2f - (this->_RegisterButton.getLocalBounds().width / 2.f);
	Framey = Posy + this->_RegisterButton.getLocalBounds().height / 1.5f - (this->_RegisterButton.getLocalBounds().height / 2.f);
	this->_RegisterText.setPosition(Framex, Framey);

}

void LoginPage::Display()
{
	this->_window->clear(sf::Color::Black);
	this->_window->draw(this->_bgSprite);
	this->_window->draw(this->_mainTitle);
	this->_window->draw(this->_SignInButton);
	this->_window->draw(this->_SignInText);
	this->_window->draw(this->_RegisterButton);
	this->_window->draw(this->_RegisterText);

	this->_window->display();
}

void LoginPage::MouseMoveTigger()
{

	if (this->IsMouseOverButton(this->_SignInButton)) {

		this->_SignInButton.setFillColor(sf::Color::White);
		this->_SignInText.setFillColor(CaramelColor);
		//this->music.play();
	}                                                                       //sign in Btn	
	else {
		this->_SignInButton.setFillColor(CaramelColor);
		this->_SignInText.setFillColor(sf::Color::Black);
	}

	if (this->IsMouseOverButton(this->_RegisterButton)) {

		this->_RegisterButton.setFillColor(sf::Color::White);
		this->_RegisterText.setFillColor(CaramelColor);
		//this->music.pause();
	}                                                                       //register Btn	
	else {
		this->_RegisterButton.setFillColor(CaramelColor);
		this->_RegisterText.setFillColor(sf::Color::Black);
	}
}


void LoginPage::OnFocusEvent()
{
	if (this->IsMouseOverButton(this->_SignInButton)) {

		this->ChangePage = true;
		this->NavTOPage = GamePages::Sign_In;
	}

	else if (this->IsMouseOverButton(this->_RegisterButton)) {

		//this->ChangePage = true;
		//this->NavTOPage = GamePages::LevelPage;
	}
}

void LoginPage::HandleEvents(sf::Event* event)
{
	if (event->type == sf::Event::MouseButtonPressed)
		this->OnFocusEvent();

	if (event->type == sf::Event::MouseMoved)
		this->MouseMoveTigger();
}
