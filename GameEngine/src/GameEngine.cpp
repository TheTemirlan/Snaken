// GameEngine.cpp : Defines the functions for the static library.
//

#include "GameEngine.h"
#include <iostream>
#include <SFML/Graphics.hpp>


GameEngine::GameEngine():
	window(123, 123, "someName"),//only for now
	quitEvent(),
	map(800,400)
{
	
}

void GameEngine::run()
{
	//TODO: some aditioal initialization

	while (window.getInstance().isOpen())
	{
		updateDt();
		update();
		render();
	}
}

void GameEngine::update()
{
	checkForQuit();
	player.update(this->dt);

}

void GameEngine::render()
{
	auto& window = this->window.getInstance();

	
	window.clear();

	this->window.draw(player);


	window.display();
}

void GameEngine::updateDt()
{
	//DEBUG
	//system("cls");
	//std::cout << dt << std::endl;

	this->dt = this->dtClock.restart().asSeconds();
}

void GameEngine::checkForQuit()
{
	auto& window = this->window.getInstance();
	
	while (window.pollEvent(quitEvent))
		if (quitEvent.type == sf::Event::Closed)
			window.close();
}

