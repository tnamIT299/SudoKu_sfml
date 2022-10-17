
#include "LevelPage.h"
#include "sstream"
#include "windows.h"
#include "SFML/Audio.hpp"
#include "Game_Hard_Play.h"

void Game_Hard_Play::setUp() {

	if (!this->_bgTexture.loadFromFile("Images/bg.jpg")) {
		std::cout << "Error Loading Images/bg.jpg" << std::endl;
		std::cout << "Shutting Down!" << std::endl;
		this->_window->close();
	}

	if (!this->_HeaderFont.loadFromFile("Fonts/07558_CenturyGothic.ttf")) {
		std::cout << "Error Loading Fonts" << std::endl;
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

	this->_gameBoard.setFillColor(sf::Color(209, 201, 178));
	this->_gameBoard.setSize(sf::Vector2f(500.f, 450.f));
	this->_gameBoard.setPosition(sf::Vector2f(this->_window->getSize().x / 2.f - this->_gameBoard.getLocalBounds().width / 2.f,
		this->_window->getSize().y / 2.f - this->_gameBoard.getLocalBounds().height / 2.f));

#pragma region Vertical BoardLine

	auto boardOriginX = this->_gameBoard.getPosition().x;
	auto boardOriginY = this->_gameBoard.getPosition().y;

	this->_vLine1.setFillColor(LineColor);
	this->_vLine1.setSize(sf::Vector2f(3.f, 450));
	this->_vLine1.setPosition(sf::Vector2f(boardOriginX + 166.7f, boardOriginY));

	this->_vLine2.setFillColor(LineColor);
	this->_vLine2.setSize(sf::Vector2f(3.f, 450));
	this->_vLine2.setPosition(sf::Vector2f(boardOriginX + 333.3f, boardOriginY));

#pragma endregion


#pragma region Horizontal BoardLine

	this->_hLine1.setFillColor(LineColor);
	this->_hLine1.setSize(sf::Vector2f(500.f, 3.f));
	this->_hLine1.setPosition(sf::Vector2f(boardOriginX, boardOriginY + 150.f));

	this->_hLine2.setFillColor(LineColor);
	this->_hLine2.setSize(sf::Vector2f(500.f, 3.f));
	this->_hLine2.setPosition(sf::Vector2f(boardOriginX, boardOriginY + 300.f));

#pragma endregion

	auto buttonX = boardOriginX + 43;
	auto ButtonY = boardOriginY - 55;

	this->_submitButton.setFillColor(LineColor);
	this->_submitButton.setSize(sf::Vector2f(133.f, 40.f));
	this->_submitButton.setPosition(sf::Vector2f(buttonX, ButtonY));

	this->_submitText.setFont(this->_HeaderFont);
	this->_submitText.setCharacterSize(18);
	this->_submitText.setFillColor(sf::Color::Black);

	float sizex;
	float sizey;

	if (this->hard_play == true)
	{
		//this->_submitText.setString("START");
	//	sizex = this->_submitText.getLocalBounds().width / 1.1f;
		//sizey = this->_submitText.getLocalBounds().height / 1.7f;
		//this->_submitText.setPosition(sf::Vector2f(buttonX + sizex , ButtonY + sizey));
	  //buttonX += 20.f * 2;

		this->_StartButton.setFillColor(LineColor);
		this->_StartButton.setSize(sf::Vector2f(133.f, 40.f));
		this->_StartButton.setPosition(sf::Vector2f(buttonX - 80, ButtonY - 97));

		this->_StartText.setFont(this->_HeaderFont);
		this->_StartText.setCharacterSize(18);
		this->_StartText.setFillColor(sf::Color::Black);
		this->_StartText.setString("START");
		sizex = this->_StartText.getLocalBounds().width / 0.9f;
		sizey = this->_StartText.getLocalBounds().height / 2.3f;

		this->_StartText.setPosition(sf::Vector2f(buttonX + sizex - 90, ButtonY + sizey - 95));


		buttonX += 10.f;

		this->_BackButton.setFillColor(LineColor);
		this->_BackButton.setSize(sf::Vector2f(133.f, 40.f));
		this->_BackButton.setPosition(sf::Vector2f(buttonX - 50, ButtonY));

		this->_BackText.setFont(this->_HeaderFont);
		this->_BackText.setCharacterSize(18);
		this->_BackText.setFillColor(sf::Color::Black);
		this->_BackText.setString("BACK");


		sizex = this->_BackText.getLocalBounds().width / 1.7f;
		sizey = this->_BackText.getLocalBounds().height / 2.3f;

		this->_BackText.setPosition(sf::Vector2f(buttonX + sizex, ButtonY + sizey));

	}

	/*else
	{
		this->_submitText.setString("Submit");
		sizex = this->_submitText.getLocalBounds().width / 2.f;
		sizey = this->_submitText.getLocalBounds().height / 2.f;
		this->_submitText.setPosition(sf::Vector2f(buttonX + sizex, ButtonY + sizey));

	}
	*/



	buttonX += 140.f;

	this->_checkButton.setFillColor(LineColor);
	this->_checkButton.setSize(sf::Vector2f(133.f, 40.f));
	this->_checkButton.setPosition(sf::Vector2f(buttonX - 160, ButtonY));

	this->_ErorText.setFont(this->_HeaderFont);
	this->_ErorText.setCharacterSize(18);
	this->_ErorText.setFillColor(sf::Color::Black);
	this->_ErorText.setString("Error : ");
	this->_ErorText.setPosition(200, 130);

	this->_checkText.setFont(this->_HeaderFont);
	this->_checkText.setCharacterSize(18);
	this->_checkText.setFillColor(sf::Color::Black);
	this->_checkText.setString("");
	sizex = this->_checkText.getLocalBounds().width / 2.2f;
	sizey = this->_checkText.getLocalBounds().height / 2.f;

	this->_checkText.setPosition(sf::Vector2f(buttonX + sizex - 60, ButtonY + sizey +10));

	buttonX += 140.f;

	this->_submitButton.setFillColor(LineColor);
	this->_submitButton.setSize(sf::Vector2f(133.f, 40.f));
	this->_submitButton.setPosition(sf::Vector2f(buttonX - 120, ButtonY));

	this->_submitText.setFont(this->_HeaderFont);
	this->_submitText.setCharacterSize(18);
	this->_submitText.setFillColor(sf::Color::Black);
	this->_submitText.setString("Submit");


	sizex = this->_submitText.getLocalBounds().width / 12.f;
	sizey = this->_submitText.getLocalBounds().height / 2.f;

	this->_submitText.setPosition(sf::Vector2f(buttonX + sizex - 90, ButtonY + sizey));
	buttonX += 140.f;

	this->_undoButton.setFillColor(LineColor);
	this->_undoButton.setSize(sf::Vector2f(133.f, 40.f));
	this->_undoButton.setPosition(sf::Vector2f(buttonX - 90, ButtonY));

	this->_undoText.setFont(this->_HeaderFont);
	this->_undoText.setCharacterSize(18);
	this->_undoText.setFillColor(sf::Color::Black);
	this->_undoText.setString("Erase");


	sizex = this->_undoText.getLocalBounds().width / 1.2f;
	sizey = this->_undoText.getLocalBounds().height / 2.f;

	this->_undoText.setPosition(sf::Vector2f(buttonX + sizex - 90, ButtonY + sizey));

	buttonX += 120.f;

	this->_BackButton.setFillColor(LineColor);
	this->_BackButton.setSize(sf::Vector2f(133.f, 40.f));
	this->_BackButton.setPosition(sf::Vector2f(buttonX - 100.f, ButtonY - 100.f));

	this->_BackText.setFont(this->_HeaderFont);
	this->_BackText.setCharacterSize(18);
	this->_BackText.setFillColor(sf::Color::Black);
	this->_BackText.setString("BACK");


	sizex = this->_BackText.getLocalBounds().width / 1.7f;
	sizey = this->_BackText.getLocalBounds().height / 2.3f;

	this->_BackText.setPosition(sf::Vector2f(buttonX + sizex - 85, ButtonY + sizey - 100));

#pragma region SetInitGrid

	auto gridPosX = boardOriginX;
	auto gridPosY = boardOriginY;


	for (int i = 0; i < ISudokuMapGen::MaxSize; ++i) {

		for (int j = 0; j < ISudokuMapGen::MaxSize; ++j) {

			this->_gameGridMap[i][j].setFillColor(sf::Color(223, 229, 237));
			this->_gameGridMap[i][j].setOutlineColor(sf::Color(sf::Color(55, 57, 59)));
			this->_gameGridMap[i][j].setOutlineThickness(2.f);
			this->_gameGridMap[i][j].setSize(sf::Vector2f(55.55f, 50.f));
			this->_gameGridMap[i][j].setPosition(sf::Vector2f(gridPosX, gridPosY));

			this->_textGridMap[i][j].setFont(this->_HeaderFont);
			this->_textGridMap[i][j].setCharacterSize(30);
			this->_textGridMap[i][j].setFillColor(sf::Color(55, 57, 59));

			auto boxVal = this->_hard_map.gameMap[i][j];           // load values from gridMap 
			auto strBoxVal = std::to_string(boxVal);
			this->_textGridMap[i][j].setString(strBoxVal);

			auto sizex = this->_textGridMap[i][j].getLocalBounds().width / 0.8f;
			auto sizey = this->_textGridMap[i][j].getLocalBounds().height / 2.f;

			this->_textGridMap[i][j].setPosition(sf::Vector2f(gridPosX + sizex, gridPosY + sizey));

			gridPosX += 55.55f;
		}
		gridPosY += 50.f;
		gridPosX = boardOriginX;
	}

#pragma endregion


#pragma region Option Selector

	if (this->hard_play == false)
	{
		gridPosX = boardOriginX;
		gridPosY += 20;
		int fillval = 1;

		for (int i = 0; i < ISudokuMapGen::MaxSize; ++i) {

			this->_optionField[i].setFillColor(sf::Color(223, 229, 237));
			this->_optionField[i].setOutlineColor(sf::Color(sf::Color(92, 95, 99)));
			this->_optionField[i].setOutlineThickness(1.f);
			this->_optionField[i].setSize(sf::Vector2f(55.55f, 50.f));
			this->_optionField[i].setPosition(sf::Vector2f(gridPosX, gridPosY));

			this->_optionText[i].setFont(this->_HeaderFont);
			this->_optionText[i].setCharacterSize(30);
			this->_optionText[i].setFillColor(sf::Color(55, 57, 59));
			this->_optionText[i].setString(std::to_string(fillval));

			auto sizex = this->_optionText[i].getLocalBounds().width / 0.8f;
			auto sizey = this->_optionText[i].getLocalBounds().height / 2.f;

			this->_optionText[i].setPosition(sf::Vector2f(gridPosX + sizex, gridPosY + sizey));

			gridPosX += 55.55f;
			++fillval;
		}

		this->_optionField[this->_selectedIndex].setFillColor(sf::Color(223, 229, 237));
	}//

#pragma endregion

}

void Game_Hard_Play::Display() {

	this->_window->clear();

	this->_window->draw(this->_bgSprite);
	this->_window->draw(this->_gameBoard);


	for (int i = 0; i < ISudokuMapGen::MaxSize; ++i) {

		if (this->hard_play == false) {
			this->_window->draw(this->_optionField[i]);    //Option Selector
			this->_window->draw(this->_optionText[i]);
		}

		for (int j = 0; j < ISudokuMapGen::MaxSize; ++j) {

			this->_window->draw(this->_gameGridMap[i][j]); //

			if (this->_hard_map.gameMap[i][j] == 0)
				continue;
			this->_window->draw(this->_textGridMap[i][j]);
		}
	}//

	this->_window->draw(this->_vLine1);
	this->_window->draw(this->_vLine2);
	this->_window->draw(this->_hLine1);
	this->_window->draw(this->_hLine2);

	if (this->hard_play == false) {
		this->_window->draw(this->_submitButton);
		this->_window->draw(this->_submitText);
		this->_window->draw(this->_checkButton);
		this->_window->draw(this->_undoButton);
		this->_window->draw(this->_checkText);
		this->_window->draw(this->_undoText);
		this->_window->draw(this->_TimeButton);
		this->_window->draw(this->_TimeText);
		this->_window->draw(this->_BackButton);
		this->_window->draw(this->_BackText);
		this->_window->draw(this->_ErorText);

		//Vong lap timeplay
		this->TimePlay();

	}
	this->_window->draw(this->_BackButton);
	this->_window->draw(this->_BackText);

	this->_window->draw(this->_StartButton);
	this->_window->draw(this->_StartText);


	this->_window->display();
}

void Game_Hard_Play::MouseMoveTigger() {

	if (this->IsMouseOverButton(this->_BackButton)) {

		this->_BackButton.setFillColor(sf::Color::White);
		this->_BackText.setFillColor(sf::Color::Black);
		this->sound.play();
	}                                                                       //back btn
	else {
		this->_BackButton.setFillColor(CaramelColor);
		this->_BackText.setFillColor(sf::Color::Black);
	}

	for (int i = 0; i < ISudokuMapGen::MaxSize; ++i) {

		if (this->IsMouseOverButton(this->_optionField[i]))
			this->_optionField[i].setFillColor(sf::Color::Yellow);
		else
		{
			if (i != this->_selectedIndex)
				this->_optionField[i].setFillColor(sf::Color(223, 229, 237));
		}

		for (int j = 0; j < ISudokuMapGen::MaxSize; ++j) {

			if (this->IsMouseOverButton(this->_gameGridMap[i][j]))
				this->_gameGridMap[i][j].setFillColor(sf::Color(235, 114, 84));
			else
				this->_gameGridMap[i][j].setFillColor(sf::Color(223, 229, 237));
		}
	}

	HoverCheck(&this->_submitButton, &this->_submitText);
	HoverCheck(&this->_checkButton, &this->_checkText);
	HoverCheck(&this->_undoButton, &this->_undoText);
	HoverCheck(&this->_BackButton, &this->_BackText);
}

void Game_Hard_Play::HoverCheck(sf::RectangleShape* button, sf::Text* buttonText) {

	if (this->IsMouseOverButton(*button))
	{
		button->setFillColor(sf::Color::White);
		buttonText->setFillColor(sf::Color::Black);
	}
	else
	{
		button->setFillColor(LineColor);
		buttonText->setFillColor(sf::Color::Black);
	}
}

void Game_Hard_Play::OnFocusEvent() {
	if (this->IsMouseOverButton(this->_BackButton)) {

		this->ChangePage = true;
		this->NavTOPage = GamePages::LevelPage;
	}

	for (int i = 0; i < ISudokuMapGen::MaxSize; ++i) {

		if (this->IsMouseOverButton(this->_undoButton)) {
			this->_undoButton.setFillColor(sf::Color::White);
			this->_selectedIndex = i;
			this->_selectedNumber = _selectedIndex * 0;
		}

		if (this->IsMouseOverButton(this->_optionField[i])) {

			this->_optionField[this->_selectedIndex].setFillColor(sf::Color::White); //reset element Previously highlighted.. 
			this->_selectedIndex = i;
			this->_optionField[i].setFillColor(sf::Color::White);
			this->_selectedNumber = this->_selectedIndex + 1;
		}

		for (int j = 0; j < ISudokuMapGen::MaxSize; ++j) {

			if (this->IsMouseOverButton(this->_gameGridMap[i][j])) {
				if (this->_hard_map.gameMap[i][j] < 0)
				{
					this->_textGridMap[i][j].setString(std::to_string(this->_selectedNumber));
					this->_hard_map.gameMap[i][j] = -this->_selectedNumber;
					this->_selections.push_back({ i,j });
				}

				if (this->_hard_map.gameMap[i][j] == 0)
				{
					if (this->_hard_map.isSafe(this->_hard_map.gameMap, i, j, this->_selectedNumber)) {
						this->_textGridMap[i][j].setString(std::to_string(this->_selectedNumber));
						this->_textGridMap[i][j].setFillColor(sf::Color::Blue);
						this->_hard_map.gameMap[i][j] = -(this->_selectedNumber);
						this->_selections.push_back({ i,j });
					}
					else {
						errorCount++;
						this->_checkText.setString(std::to_string(errorCount));
					}
				}
			}

		}
	}


	if (this->IsMouseOverButton(this->_submitButton)) {

		int rol, col;
		if (this->_hard_map.FindUnassignedLocation(this->_hard_map.gameMap, rol, col))
		{
			this->AlertWindow(this->_HeaderFont, "Grid not completely filled!", 300, 100, sf::Color(223, 229, 237), LineColor);
		}

		else
		{
			if (this->_checkErr == false) {

				for (int i = 0; i < ISudokuMapGen::MaxSize; ++i) {
					for (int j = 0; j < ISudokuMapGen::MaxSize; ++j) {

						auto value = this->_hard_map.gameMap[i][j];

						if (this->_hard_map.isSafe(this->_hard_map.gameMap, i, j, value) == false)
						{
							this->_checkErr = true;
							this->_textGridMap[i][j].setFillColor(sf::Color::Red);
						}
					}
				}//
			}//
			if (this->_checkErr == false) {

				this->AlertWindow(this->_HeaderFont, "Completed! You Won!", 200, 100, sf::Color(223, 229, 237), LineColor);
			}
		}
	}

}

void Game_Hard_Play::HandleEvents(sf::Event* event) {

	if (this->hard_play == false) {
		if (event->type == sf::Event::MouseButtonPressed)
			this->OnFocusEvent();

		if (event->type == sf::Event::MouseMoved)
			this->MouseMoveTigger();
	}

	else
	{

		if (this->hard_play == true) {
			if (event->type == sf::Event::MouseButtonPressed)
				this->OnFocusEvent();

			if (event->type == sf::Event::MouseMoved)
				this->MouseMoveTigger();
		}
		if (event->type == sf::Event::MouseMoved)
			HoverCheck(&this->_StartButton, &this->_StartText);

		if (event->type == sf::Event::MouseButtonPressed) {

			if (this->IsMouseOverButton(this->_StartButton))
				this->_initAi = true;
		}
	}

	if (event->type == sf::Event::KeyPressed) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) // Go back to startPage
		{
			this->_window->clear(sf::Color::Black);
			this->ChangePage = true;
			this->NavTOPage = GamePages::StartPage;
		}
	}

	if (this->hard_play == true && this->_aiDone != true && this->_initAi) {

		auto check = this->AISolve(this->_hard_map.gameMap);
		this->_aiDone = true;

		if (check)
			this->AlertWindow(this->_HeaderFont, "Completed!", 150, 100, sf::Color(223, 229, 237), LineColor);
		else
			this->AlertWindow(this->_HeaderFont, "Can't be Solved!", 200, 100, sf::Color(223, 229, 237), LineColor);
	}
}

bool Game_Hard_Play::AISolve(int grid[ISudokuMapGen::MaxSize][ISudokuMapGen::MaxSize])
{
	int row, col;

	if (!this->_hard_map.FindUnassignedLocation(grid, row, col))
		return true;

	for (int value = 1; value <= ISudokuMapGen::MaxSize; value++)
	{

		if (this->_hard_map.isSafe(grid, row, col, value))
		{
			grid[row][col] = value;
			this->_textGridMap[row][col].setString(std::to_string(value));
			this->Display();

			if (AISolve(grid))
				return true;

			grid[row][col] = 0;
			this->_textGridMap[row][col].setString(std::to_string(0));
			this->Display();
		}
	}
	return false;
}
void Game_Hard_Play::TimePlay() {
	//TIME
	sf::Font font;
	if (!font.loadFromFile("Fonts/07558_CenturyGothic.ttf"))
	{
		std::cout << "Error Loading Fonts" << std::endl;
		std::cout << "Shutting Down!" << std::endl;
		this->_window->close();
	}
	float  sizex = this->_TimeText.getLocalBounds().width / 12.f;
	float sizey = this->_TimeText.getLocalBounds().height / 2.f;
	this->_TimeButton.setFillColor(LineColor);
	this->_TimeButton.setSize(sf::Vector2f(133.f, 40.f));
	this->_TimeButton.setPosition(sf::Vector2f(700 - 660.f, 700 - 680.f));

	this->_TimeText.setFont(this->_HeaderFont);
	this->_TimeText.setCharacterSize(20);
	this->_TimeText.setFillColor(sf::Color::Black);
	this->_TimeText.setString(ss.str());
	this->_TimeText.setPosition(sf::Vector2f(100 + sizex - 50, 100 + sizey - 80));
	Sleep(1);
	milisecond++;
	if (milisecond == 60) {
		second++;
		milisecond = 0;
	}
	if (second == 60) {
		minute++;
		second = 0;
		milisecond = 0;
	}
	if (minute == 60) {
		hours++;
		second = 0;
		milisecond = 0;
		minute = 0;
	}

	ss.str("");

	if (hours < 10)
	{
		ss << "0" << hours << ":";
	}
	else
	{
		ss << hours;
	}
	if (minute < 10)
	{
		ss << "0" << minute << ":";
	}
	else
	{
		ss << minute << ":";
	}

	if (second < 10)
	{
		ss << "0" << second << ":";
	}
	else
	{
		ss << second << ":";
	}

	if (milisecond < 10)
	{
		ss << "0" << milisecond;
	}
	else
	{
		ss << milisecond;
	}

}


