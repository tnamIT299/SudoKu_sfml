#pragma once
#include "BasePageClass.h"
#include "IceMapGen.h"
#include "sstream"
#include "string"
#include "SFML/Audio.hpp"
#include "XacThuc.h"
class IMapPlay :public BasePageClass
{
public:
	IMapPlay() {};
	IMapPlay(sf::RenderWindow* window, bool compPlay) : BasePageClass(window)
	{
		this->_pageID = "MainPage";
		this->NavTOPage = GamePages::None;
		this->computerPlay = compPlay;
		this->setUp();
	}

	bool computerPlay; // if true "AI" is playing
	//h?m c?i time
	void TimePlay();

	void DeleteGrid();


	void Display() override;
	void HandleEvents(sf::Event*) override;
	const sf::Color CaramelColor = sf::Color(235, 114, 84);
private:
	void setUp();
	void MouseMoveTigger();
	void HoverCheck(sf::RectangleShape*, sf::Text*);
	void OnFocusEvent();
	bool AISolve(int grid[IceMapGen::MaxSize][IceMapGen::MaxSize]);
	IceMapGen _sudokuMap;
	//IceBreaker _icebreaker_map;
	sf::RectangleShape _gameBoard;
	sf::Font _HeaderFont;
	sf::Texture _bgTexture;
	sf::Sprite _bgSprite;
	sf::RectangleShape _vLine1;
	sf::RectangleShape _vLine2;
	sf::RectangleShape _hLine1;
	sf::RectangleShape _hLine2;
	sf::RectangleShape _gameGridMap[IceMapGen::MaxSize][IceMapGen::MaxSize];
	sf::Text _textGridMap[IceMapGen::MaxSize][IceMapGen::MaxSize];
	sf::Text _optionText[IceMapGen::MaxSize];
	sf::RectangleShape _optionField[IceMapGen::MaxSize];
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
	sf::Text _errorText;
	sf::Text _checkText;
	sf::Text _BackText;
	sf::Text _StartText;
	sf::Text _ErorText;
	int errorCount;
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
	//t?o th?m bi?n ? ??y
	int getTime = 0;
	XacThuc verify;
};

