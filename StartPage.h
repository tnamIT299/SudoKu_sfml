#pragma once

#include"BasePageClass.h"
#include"SFML/Audio.hpp"
#include"SFML/Graphics.hpp"

class StartPage : public BasePageClass
{
public:

	StartPage(sf::RenderWindow* window) :BasePageClass(window) {
		this->setUp();
		this->_pageID = "StartPage";
		this->NavTOPage = GamePages::None;
	}

	void Display() override;
	void HandleEvents(sf::Event*) override;

	const sf::Color CaramelColor = sf::Color(235, 114, 84);

private:
	void setUp();
	void MouseMoveTigger();
	void OnFocusEvent();
	sf::Texture _bgTexture;
	sf::Sprite _bgSprite;
	sf::Text _mainTitle;
	sf::Font _HeaderFont;
	sf::RectangleShape _PlayGameButton;
	sf::RectangleShape _LevelButton;
	sf::RectangleShape _computerPlayButton;
	sf::RectangleShape _exitButton;
	sf::RectangleShape _HighSoccerButton;
	sf::Text _playGameText;
	sf::Text _levelText;
	sf::Text _computerPlayText;
	sf::Text _exitButtonText;
	sf::Text _HighSoccerText;
	sf::SoundBuffer buffer;
	sf::Sound sound;
	sf::Music music;
};
