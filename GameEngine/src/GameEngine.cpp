// GameEngine.cpp : Defines the functions for the static library.
//

#include "GameEngine.h"
#include <iostream>
#include <SFML/Graphics.hpp>


GameEngine::GameEngine() :
	window(123, 123, "someName"),//only for now
	quitEvent(),
	map(80, 40),
	player(map.getMap()),
	clock()
{

}

void GameEngine::run()
{
	//TODO: some aditioal initialization

	while (window.getInstance().isOpen())
	{
		auto currentTime = clock.getElapsedTime();
		updateDt();
		if (currentTime.asMilliseconds() - previousUpdateTime_ > deltaTime_) {
			update();
			render();
			previousUpdateTime_ = currentTime.asMilliseconds();
		}
	}
}

void GameEngine::update()
{
	checkForQuit();
	this->player.update(this->dt);
	this->map.update(dt);
}

void GameEngine::render()
{
	auto& window = this->window.getInstance();

	window.clear();

	this->window.draw(map);


	window.display();
}

void GameEngine::updateDt()
{
	this->player.updateDirection();
}

void GameEngine::checkForQuit()
{
	auto& window = this->window.getInstance();

	while (window.pollEvent(quitEvent))
		if (quitEvent.type == sf::Event::Closed)
			window.close();
}

