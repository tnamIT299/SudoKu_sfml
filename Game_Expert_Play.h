#pragma once
#pragma once

#include "BasePageClass.h"
#include "SudokuMapGen.h"
#include "SudokuMapExpert.h"
#include "sstream"
#include "string"
#include "SFML/Audio.hpp"

using namespace std;
class Game_Expert_Play : public BasePageClass
{

public:
	Game_Expert_Play() {};
	Game_Expert_Play(sf::RenderWindow* window, bool expert_play) : BasePageClass(window)
	{
		this->_pageID = "Game_Expert";
		this->NavTOPage = GamePages::None;
		this->expert_play = expert_play;
		this->setUp();
	}

	bool expert_play; // if true "AI" is playing
	//hàm cài time
	void TimePlay();


	void Display() override;
	void HandleEvents(sf::Event*) override;
	const sf::Color CaramelColor = sf::Color(235, 114, 84);
private:
	void setUp();
	void MouseMoveTigger();
	void HoverCheck(sf::RectangleShape*, sf::Text*);
	void OnFocusEvent();
	bool AISolve(int grid[SudokuMapExpert::MaxSize][SudokuMapExpert::MaxSize]);
	SudokuMapExpert _expert_map;
	sf::RectangleShape _gameBoard;
	sf::Font _HeaderFont;
	sf::Texture _bgTexture;
	sf::Sprite _bgSprite;
	sf::RectangleShape _vLine1;
	sf::RectangleShape _vLine2;
	sf::RectangleShape _hLine1;
	sf::RectangleShape _hLine2;
	sf::RectangleShape _gameGridMap[SudokuMapExpert::MaxSize][SudokuMapExpert::MaxSize];
	sf::Text _textGridMap[SudokuMapExpert::MaxSize][SudokuMapExpert::MaxSize];
	sf::Text _optionText[SudokuMapExpert::MaxSize];
	sf::RectangleShape _optionField[SudokuMapExpert::MaxSize];
	int _selectedNumber{ 1 }; //default
	int _selectedIndex{ 0 }; //default
	std::vector<Field> _selections;
	sf::RectangleShape _TimeButton;
	sf::RectangleShape _submitButton;
	sf::RectangleShape _undoButton;
	sf::RectangleShape _checkButton;
	sf::RectangleShape _BackButton;
	sf::RectangleShape _StartButton;
	sf::Text _TimeText;
	sf::Text _submitText;
	sf::Text _undoText;
	sf::Text _checkText;
	sf::Text _BackText;
	sf::Text _StartText;

	//Music
	sf::SoundBuffer buffer;
	sf::Sound sound;
	sf::Music music;

	const sf::Color LineColor = sf::Color(235, 114, 84);
	bool _checkErr{ false };
	bool _resetErrColor{ false };
	bool _aiDone{ false };
	bool _initAi{ false };

	// TIME
	stringstream ss;
	stringstream data;
	stringstream c;

	int second = 0;
	int milisecond = 0;
	int minute = 0;
	int hours = 0;
};


