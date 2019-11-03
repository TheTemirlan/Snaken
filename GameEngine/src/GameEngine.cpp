// GameEngine.cpp : Defines the functions for the static library.
//

#include "GameEngine.h"
#include <iostream>
#include <SFML/Graphics.hpp>


GameEngine::GameEngine():
	window(123, 123, "someName"),//only for now
	quitEvent()
{
	
}

void GameEngine::run()
{
	//TODO: some aditioal initialization

	while (window.getInstance().isOpen())
	{
		update();
		render();
	}
}

void GameEngine::update()
{
	checkForQuit();
	player.update();

}

void GameEngine::render()
{
	auto& window = this->window.getInstance();

	//Epilepsiya effect	
	window.clear();
	this->window.draw(player);
	window.display();
}

void GameEngine::checkForQuit()
{
	auto& window = this->window.getInstance();
	
	while (window.pollEvent(quitEvent))
		if (quitEvent.type == sf::Event::Closed)
			window.close();
}

