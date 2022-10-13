#pragma once
#include "BasePageClass.h"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "fstream"
#include "sstream"

// Define keys:
#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Sign_In : public BasePageClass
{
public:

	Sign_In(sf::RenderWindow* window, bool sign_in) :BasePageClass(window) {
		this->setUp();
		this->_pageID = "Sign_In";
		this->sign_in = sign_in;
		this->NavTOPage = GamePages::None;
	}
	bool sign_in;
	void Display() override;
	void HandleEvents(sf::Event*) override;
	void FillInfor();

	const sf::Color CaramelColor = sf::Color(235, 114, 84);

	//textbox

	Sign_In(int size, sf::Color color, bool sel) {
		_textBox.setCharacterSize(size);
		_textBox.setFillColor(color);
		isSelected = sel;

		// Check if the textbox is selected upon creation and display it accordingly:
		if (isSelected)
			_textBox.setString("_");
		else
			_textBox.setString("");
	}

	// Make sure font is passed by reference:
	void setFont(sf::Font& fonts) {
		_textBox.setFont(fonts);
	}

	void setPosition(sf::Vector2f point) {
		_textBox.setPosition(point);
	}

	// Set char limits:
	void setLimit(bool ToF) {
		hasLimit = ToF;
	}

	void setLimit(bool ToF, int lim) {
		hasLimit = ToF;
		limit = lim - 1;
	}

	// Change selected state:
	void setSelected(bool sel) {
		isSelected = sel;

		// If not selected, remove the '_' at the end:
		if (!sel) {
			std::string t = text.str();
			std::string newT = "";
			for (int i = 0; i < t.length(); i++) {
				newT += t[i];
			}
			_textBox.setString(newT);
		}
	}

	std::string getText() {
		return text.str();
	}

	void drawTo(sf::RenderWindow* window) {
		this->_window = window;
		this->_window->draw(_textBox);
	}

	// Function for event loop:
	void typedOn(sf::Event input) {
		if (isSelected) {
			int charTyped = input.text.unicode;

			// Only allow normal inputs:
			if (charTyped < 128) {
				if (hasLimit) {
					// If there's a limit, don't go over it:
					if (text.str().length() <= limit) {
						inputLogic(charTyped);
					}
					// But allow for char deletions:
					else if (text.str().length() > limit && charTyped == DELETE_KEY) {
						deleteLastChar();
					}
				}
				// If no limit exists, just run the function:
				else {
					inputLogic(charTyped);
				}
			}
		}
	}
	void setScn(int scn) {
		this->scene = scn;
	}
	int getScn() {
		return this->scene;
	}
	/*static Sign_In* getInstance()
	{
		return s
	}*/
private:
	void setUp();
	void MouseMoveTigger();
	void OnFocusEvent();
	static Sign_In* sInstance;
	sf::Texture _bgTexture;
	sf::Sprite _bgSprite;
	sf::Text _mainTitle;
	sf::Font _HeaderFont;
	sf::RectangleShape _UserButton;
	sf::RectangleShape _PassWordButton;
	sf::RectangleShape _Sign_InButton;
	sf::Text _textBox;
	sf::Text _UserText;
	sf::Text _PassWordText;
	sf::Text _Sign_InText;
	sf::Text _Sign_In;

	//Textbox
	std::ostringstream text;
	bool isSelected = false;
	bool hasLimit = false;
	int limit = 0;

	struct scn2
	{
		bool user = false;
		bool password = false;
	};

	struct scn3
	{
		bool user = false;
		bool password = false;
		bool confirmPassword = false;
	};

	struct account
	{
		std::string user;
		std::string password;
	};

	int scene = 1, i = 1;

	scn2 scene2;
	scn3 scene3;
	account acc[100];
	bool first = true;



	void input()
	{
		std::ifstream fin("login.txt", std::ios::in | std::ios::out);
		while (fin >> acc[i].user)
		{
			fin >> acc[i].password;
			i++;
		}
		fin.close();
	}

	void deleteLastChar() {
		std::string t = text.str();
		std::string newT = "";
		for (int i = 0; i < t.length() - 1; i++) {
			newT += t[i];
		}
		text.str("");
		text << newT;
		_textBox.setString(text.str() + "_");
	}

	// Get user input:
	void inputLogic(int charTyped) {
		// If the key pressed isn't delete, or the two selection keys, then append the text with the char:
		if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY) {
			text << static_cast<char>(charTyped);
		}
		// If the key is delete, then delete the char:
		else if (charTyped == DELETE_KEY) {
			if (text.str().length() > 0) {
				deleteLastChar();
			}
		}
		// Set the textbox text:
		_textBox.setString(text.str() + "_");
	}
};

