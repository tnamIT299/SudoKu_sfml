#include "Sign_In.h"
#include <fstream>
#include <SFML/Graphics.hpp>

//Sign_In* Sign_In::sInstance = nullptr;

void Sign_In::setUp()
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
	this->_mainTitle.setString("Sign In");
	this->_mainTitle.setCharacterSize(45);
	this->_mainTitle.setFillColor(sf::Color::Red);
	this->_mainTitle.setPosition(sf::Vector2f(this->_window->getSize().x / 2.2f - (4.f * 45.f) / 3.2f, this->_window->getSize().y / 6.5f));
	this->_mainTitle.setStyle(sf::Text::Bold);

	auto Posx = this->_window->getSize().x / 2.3f - (170.f / 3.5f);
	auto Posy = this->_window->getSize().y / 3.f;

	const auto height = 40.f;

	this->_UserButton.setSize(sf::Vector2f(170.f, height));
	this->_UserButton.setPosition(sf::Vector2f(Posx-190, Posy));
	this->_UserButton.setFillColor(CaramelColor);

	this->_UserText.setFillColor(sf::Color::Black);
	this->_UserText.setFont(this->_HeaderFont);
	this->_UserText.setCharacterSize(18);
	this->_UserText.setString("User Name");
	auto Framex = Posx + this->_UserButton.getLocalBounds().width / 1.4f - (this->_UserButton.getLocalBounds().width / 2.f);
	auto Framey = Posy + this->_UserButton.getLocalBounds().height / 1.5f - (this->_UserButton.getLocalBounds().height / 2.f);
	this->_UserText.setPosition(Framex -190, Framey);


	Posy += 65;
	this->_PassWordButton.setSize(sf::Vector2f(170.f, height));
	this->_PassWordButton.setPosition(sf::Vector2f(Posx-190, Posy));
	this->_PassWordButton.setFillColor(CaramelColor);

	this->_PassWordText.setFillColor(sf::Color::Black);
	this->_PassWordText.setFont(this->_HeaderFont);
	this->_PassWordText.setCharacterSize(18);
	this->_PassWordText.setString("Password");
	Framex = Posx + this->_PassWordButton.getLocalBounds().width / 1.4f - (this->_PassWordButton.getLocalBounds().width / 2.f);
	Framey = Posy + this->_PassWordButton.getLocalBounds().height / 1.5f - (this->_PassWordButton.getLocalBounds().height / 2.f);
	this->_PassWordText.setPosition(Framex-190, Framey);

	Posy += 65;
	this->_Sign_InButton.setSize(sf::Vector2f(200.f, height));
	this->_Sign_InButton.setPosition(sf::Vector2f(Posx  , Posy + 40));
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
	//this->FillInfor();
}


void Sign_In::MouseMoveTigger()
{
	if (this->IsMouseOverButton(this->_Sign_InButton)) {

		this->_Sign_InButton.setFillColor(sf::Color::White);
		this->_Sign_InText.setFillColor(CaramelColor);
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

//void Sign_In::FillInfor()
//{
//	sf::Font font;
//	if (!font.loadFromFile("Fonts/07558_CenturyGothic.ttf"))
//	{
//		std::cout << "Error Loading Fonts" << std::endl;
//		std::cout << "Shutting Down!" << std::endl;
//		this->_window->close();
//	}
//
//	Sign_In textSignInUser(30, sf::Color::White, false);
//	textSignInUser.setFont(font);
//	Sign_In textSignInPassword(30, sf::Color::White, false);
//	textSignInPassword.setFont(font);
//	Sign_In textRegisterUser(30, sf::Color::White, false);
//	textRegisterUser.setFont(font);
//	Sign_In textRegisterPassword(30, sf::Color::White, false);
//	textRegisterPassword.setFont(font);
//	Sign_In textRegisterConfirmPassword(30, sf::Color::White, false);
//	textRegisterConfirmPassword.setFont(font);
//
//
//}
//void Sign_In::FillInfor()
//{
//	
//	sf::Font font;
//	if (!font.loadFromFile("Fonts/07558_CenturyGothic.ttf"))
//	{
//		std::cout << "Error Loading Fonts" << std::endl;
//		std::cout << "Shutting Down!" << std::endl;
//		this->_window->close();
//	}
//
//	Sign_In textSignInUser(30, sf::Color::White, false);
//	textSignInUser.setFont(font);
//	Sign_In textSignInPassword(30, sf::Color::White, false);
//	textSignInPassword.setFont(font);
//	Sign_In textRegisterUser(30, sf::Color::White, false);
//	textRegisterUser.setFont(font);
//	Sign_In textRegisterPassword(30, sf::Color::White, false);
//	textRegisterPassword.setFont(font);
//	Sign_In textRegisterConfirmPassword(30, sf::Color::White, false);
//	textRegisterConfirmPassword.setFont(font);
//
//	input();
//
//	std::ofstream fout("login.txt", std::ios::in | std::ios::out);
//
//	if (first == true)
//	{
//		for (int j = 1; j < i; j++)
//		{
//			fout << acc[j].user << "\n";
//			fout << acc[j].password << "\n";
//		}
//		first = false;
//	}
//
//	//if (event->type == sf::Event::MouseButtonPressed)
//	//{
//	//	if (event->key.code == sf::Mouse::Left)
//		//
//	sf::Event e;
//	while (this->_window->pollEvent(e)) {
//		int x = sf::Mouse::getPosition().x;
//		int y = sf::Mouse::getPosition().y;
//		
//		if (scene == 1)
//		{
//			if (x >= 75 && x <= 525 && y >= 87 && y <= 257)
//			{
//				// LOGIN
//				scene = 2;
//			}
//			if (x >= 75 && x <= 525 && y >= 343 && y <= 513)
//			{
//				// REGISTER
//				scene = 3;
//			}
//		}
//		if (scene == 2)
//		{
//			// back
//			if (x >= 233 && x <= 368 && y >= 530 && y <= 580)
//			{
//				scene = 1;
//			}
//			if (x >= 50 && x <= 200 && y >= 75 && y <= 125)
//			{
//				// click on user
//				scene2.user = true;
//				textSignInUser.setSelected(true);
//			}
//			if (x >= 50 && x <= 259 && y >= 235 && y <= 285)
//			{
//				//click on password
//				scene2.password = true;
//				textSignInPassword.setSelected(true);
//			}
//			// submit
//			if (x >= 143 && x <= 457 && y >= 405 && y <= 480)
//			{
//
//				std::string e, p;
//				e = textSignInUser.getText();
//				p = textSignInPassword.getText();
//				if (e.empty() == false && p.empty() == false)
//				{
//					for (int j = 1; j <= i; j++)
//					{
//						if (e == acc[j].user && p == acc[j].password)
//						{
//							scene = 4;
//						}
//					}
//				}
//			}
//		}
//		if (scene == 3)
//		{
//			// back
//			if (x >= 233 && x <= 368 && y >= 530 && y <= 580)
//			{
//				scene = 1;
//			}
//			// email
//			if (x >= 15 && x <= 165 && y >= 34 && y <= 84)
//			{
//				scene3.user = true;
//				textRegisterUser.setSelected(true);
//			}
//			// password
//			if (x >= 15 && x <= 224 && y >= 198 && y <= 248)
//			{
//				scene3.password = true;
//				textRegisterPassword.setSelected(true);
//			}
//			// confirm password
//			if (x >= 15 && x <= 329 && y >= 280 && y <= 330)
//			{
//				scene3.confirmPassword = true;
//				textRegisterConfirmPassword.setSelected(true);
//			}
//			this->OnFocusEvent();
//			//submit
//			if (x >= 143 && x <= 457 && y >= 405 && y <= 480)
//			{
//				std::string e, ce, p, cp;
//				e = textRegisterUser.getText();
//				p = textRegisterPassword.getText();
//				cp = textRegisterConfirmPassword.getText();
//				if (e.empty() == false && ce.empty() == false && p.empty() == false && cp.empty() == false)
//				{
//					if (e == ce && p == cp)
//					{
//						fout << e << "\n";
//						fout << p << "\n";
//					}
//				}
//			}
//		}
//		if (e.type == sf::Event::TextEntered)
//		{
//			if (scene == 2)
//			{
//				if (scene2.user == true)
//				{
//					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
//					{
//						textSignInUser.setSelected(false);
//						scene2.user = false;
//					}
//					else
//					{
//						textSignInUser.typedOn(e);
//					}
//				}
//				else if (scene2.password == true)
//				{
//					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
//					{
//						textSignInPassword.setSelected(false);
//						scene2.password = false;
//					}
//					else
//					{
//						textSignInPassword.typedOn(e);
//					}
//				}
//			}
//			if (scene == 3)
//			{
//				if (scene3.user == true)
//				{
//					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
//					{
//						textRegisterUser.setSelected(false);
//						scene3.user = false;
//					}
//					else
//					{
//						textRegisterUser.typedOn(e);
//					}
//				}
//				else if (scene3.password == true)
//				{
//					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
//					{
//						textRegisterPassword.setSelected(false);
//						scene3.password = false;
//					}
//					else
//					{
//						textRegisterPassword.typedOn(e);
//					}
//				}
//				else if (scene3.confirmPassword == true)
//				{
//					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
//					{
//						textRegisterConfirmPassword.setSelected(false);
//						scene3.confirmPassword = false;
//					}
//					else
//					{
//						textRegisterConfirmPassword.typedOn(e);
//					}
//				}
//			}
//		}
//	}
//
//	if (scene == 2)
//	{
//		textSignInUser.setPosition({ 210,76 });
//		textSignInUser.drawTo(_window);
//		textSignInPassword.setPosition({ 269,237 });
//		textSignInPassword.drawTo(_window);
//
//	}
//	if (scene == 4)
//	{
//		//LoginOK.setPosition(193, 219);
//	}
//}

