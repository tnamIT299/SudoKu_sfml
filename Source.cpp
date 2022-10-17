#include"PageManager.h"
#include"SudokuMapGen.h"
#include<SFML/Graphics.hpp>
#include<iostream>
#include<sstream>
#include<windows.h>
#include<SFML/Audio.hpp>
using namespace std;
using namespace sf;
int main()
{
	
	sf::RenderWindow window(sf::VideoMode(800, 800), "Sudoku", sf::Style::Titlebar | sf::Style::Close);
	sf::Music music;
	if (!music.openFromFile("music/Nhac-Thien-Tinh-Tam-V-A.ogg"))
		return -1; // error
	music.setVolume(10.f);
	music.play();

	
	PagesManager pageManager(&window);
	GamePlayPage gameplay;
	/*SudokuMapGen gen;
	gen.printGrid(gen.gameMap);
	gen.Solve(gen.gameMap);                // debug
	std::cout << "\n\n\n\n";
	gen.printGrid(gen.gameMap);*/

	//time
	window.setFramerateLimit(60);
	srand(time(NULL));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			pageManager.HandleEvents(&event);
		}
		pageManager.Display();
	}
}