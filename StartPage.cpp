#include "StartPage.h"
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

	if (!music.openFromFile("music/Nhac-Thien-Tinh-Tam-V-A.ogg"))
	{
		std::cout << "ERROR: Loading File Music" << std::endl;
		this->_window->close();
	}
	music.setVolume(50.f);
	music.play();
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
	//Music play
	this->_music_Play_Button.setSize(sf::Vector2f(50.f, height));
	this->_music_Play_Button.setPosition(sf::Vector2f(20, 20));
	this->_music_Play_Button.setFillColor(CaramelColor);

	this->_music_PlayText.setFillColor(sf::Color::Black);
	this->_music_PlayText.setFont(this->_HeaderFont);
	this->_music_PlayText.setCharacterSize(20);
	this->_music_PlayText.setString("| |");
	auto Framex = Posx + this->_music_Play_Button.getLocalBounds().width / 1.4f - (this->_music_Play_Button.getLocalBounds().width / 2.f);
	auto Framey = Posy + this->_music_Play_Button.getLocalBounds().height / 1.5f - (this->_music_Play_Button.getLocalBounds().height / 2.f);
	this->_music_PlayText.setPosition(31, 27);

	//Music Pause

	this->_music_Pause_Button.setSize(sf::Vector2f(50.f, height));
	this->_music_Pause_Button.setPosition(sf::Vector2f(120, 20));
	this->_music_Pause_Button.setFillColor(CaramelColor);

	this->_music_PauseText.setFillColor(sf::Color::Black);
	this->_music_PauseText.setFont(this->_HeaderFont);
	this->_music_PauseText.setCharacterSize(20);
	this->_music_PauseText.setString("|>");
	Framex = Posx + this->_music_Pause_Button.getLocalBounds().width / 1.4f - (this->_music_Pause_Button.getLocalBounds().width / 2.f);
	Framey = Posy + this->_music_Pause_Button.getLocalBounds().height / 1.5f - (this->_music_Pause_Button.getLocalBounds().height / 2.f);
	this->_music_PauseText.setPosition(133, 27);

	//Music Stop
	this->_music_Stop_Button.setSize(sf::Vector2f(50.f, height));
	this->_music_Stop_Button.setPosition(sf::Vector2f(220, 20));
	this->_music_Stop_Button.setFillColor(CaramelColor);

	this->_music_StopText.setFillColor(sf::Color::Black);
	this->_music_StopText.setFont(this->_HeaderFont);
	this->_music_StopText.setCharacterSize(20);
	this->_music_StopText.setString("X");
	Framex = Posx + this->_music_Stop_Button.getLocalBounds().width / 1.4f - (this->_music_Stop_Button.getLocalBounds().width / 2.f);
	Framey = Posy + this->_music_Stop_Button.getLocalBounds().height / 1.5f - (this->_music_Stop_Button.getLocalBounds().height / 2.f);
	this->_music_StopText.setPosition(239, 27);

	//Play Game button
	this->_PlayGameButton.setSize(sf::Vector2f(170.f, height));
	this->_PlayGameButton.setPosition(sf::Vector2f(Posx, Posy));
	this->_PlayGameButton.setFillColor(CaramelColor);

	this->_playGameText.setFillColor(sf::Color::Black);
	this->_playGameText.setFont(this->_HeaderFont);
	this->_playGameText.setCharacterSize(18);
	this->_playGameText.setString("Play Game");
	Framex = Posx + this->_PlayGameButton.getLocalBounds().width / 1.4f - (this->_PlayGameButton.getLocalBounds().width / 2.f);
    Framey = Posy + this->_PlayGameButton.getLocalBounds().height / 1.5f - (this->_PlayGameButton.getLocalBounds().height / 2.f);
	this->_playGameText.setPosition(Framex, Framey);


	Posy += 65;
	this->_LevelButton.setSize(sf::Vector2f(170.f, height));
	this->_LevelButton.setPosition(sf::Vector2f(Posx, Posy));
	this->_LevelButton.setFillColor(CaramelColor);

	this->_levelText.setFillColor(sf::Color::Black);
	this->_levelText.setFont(this->_HeaderFont);
	this->_levelText.setCharacterSize(18);
	this->_levelText.setString("Level");
	Framex = Posx + this->_LevelButton.getLocalBounds().width / 1.2f - (this->_LevelButton.getLocalBounds().width / 2.f);
	Framey = Posy + this->_LevelButton.getLocalBounds().height / 1.5f - (this->_LevelButton.getLocalBounds().height / 2.f);
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
	this->_window->draw(this->_music_Play_Button);
	this->_window->draw(this->_music_PlayText);
	this->_window->draw(this->_music_Pause_Button);
	this->_window->draw(this->_music_PauseText);
	this->_window->draw(this->_music_Stop_Button);
	this->_window->draw(this->_music_StopText);
	this->_window->draw(this->_music_PauseText);
	this->_window->draw(this->_playGameText);
	this->_window->draw(this->_playGameText);
	this->_window->draw(this->_PlayGameButton);
	this->_window->draw(this->_playGameText);
	this->_window->draw(this->_LevelButton);
	this->_window->draw(this->_levelText);
	this->_window->draw(this->_computerPlayButton);
	this->_window->draw(this->_computerPlayText);
	this->_window->draw(this->_exitButton);
	this->_window->draw(this->_exitButtonText);

	this->_window->display();
}

void StartPage::OnFocusEvent() {
	if (this->IsMouseOverButton(this->_music_Play_Button)) {

		this->music.play();
	}
	else if (this->IsMouseOverButton(this->_music_Pause_Button)) {

		this->music.pause();
	}
	else if (this->IsMouseOverButton(this->_music_Stop_Button)) {

		this->music.stop();
	}
	else if (this->IsMouseOverButton(this->_PlayGameButton)) {

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


	else if (this->IsMouseOverButton(this->_exitButton)) {

		this->_window->close();
	}
}

void StartPage::MouseMoveTigger() {
	if (this->IsMouseOverButton(this->_music_Play_Button)) {

		this->_music_Play_Button.setFillColor(sf::Color::White);
		this->_music_PlayText.setFillColor(CaramelColor);
		//this->music.play();
	}                                                                       //PlayMusic Btn	
	else {
		this->_music_Play_Button.setFillColor(CaramelColor);
		this->_music_PlayText.setFillColor(sf::Color::Black);
	}

	if (this->IsMouseOverButton(this->_music_Pause_Button)) {

		this->_music_Pause_Button.setFillColor(sf::Color::White);
		this->_music_PauseText.setFillColor(CaramelColor);
		//this->music.pause();
	}                                                                       //PauseMusic Btn	
	else {
		this->_music_Pause_Button.setFillColor(CaramelColor);
		this->_music_PauseText.setFillColor(sf::Color::Black);
	}
	if (this->IsMouseOverButton(this->_music_Stop_Button)) {

		this->_music_Stop_Button.setFillColor(sf::Color::White);
		this->_music_StopText.setFillColor(CaramelColor);
		//this->music.stop();
	}                                                                       //StopMusic Btn	
	else {
		this->_music_Stop_Button.setFillColor(CaramelColor);
		this->_music_StopText.setFillColor(sf::Color::Black);
	}

	if (this->IsMouseOverButton(this->_PlayGameButton)) {

		this->_PlayGameButton.setFillColor(sf::Color::White);
		this->_playGameText.setFillColor(CaramelColor);
		//this->sound.play();
		this->sound.play();
	}                                                                       //PlayGame Btn	
	else {
		this->_PlayGameButton.setFillColor(CaramelColor);
		this->_playGameText.setFillColor(sf::Color::Black);
	}

	if (this->IsMouseOverButton(this->_LevelButton)) {

		this->_LevelButton.setFillColor(sf::Color::White);
		this->_levelText.setFillColor(CaramelColor);
		this->sound.play();
	}                                                                       //Level Btn	
	else {
		this->_LevelButton.setFillColor(CaramelColor);
		this->_levelText.setFillColor(sf::Color::Black);
	}

	if (this->IsMouseOverButton(this->_computerPlayButton)) {

		this->_computerPlayButton.setFillColor(sf::Color::White);
		this->_computerPlayText.setFillColor(CaramelColor);
		this->sound.play();
	}                                                                       //CompPlay
	else {
		this->_computerPlayButton.setFillColor(CaramelColor);
		this->_computerPlayText.setFillColor(sf::Color::Black);
	}

	if (this->IsMouseOverButton(this->_exitButton)) {

		this->_exitButton.setFillColor(sf::Color::White);
		this->_exitButtonText.setFillColor(CaramelColor);
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