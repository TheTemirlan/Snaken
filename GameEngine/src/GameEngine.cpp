// GameEngine.cpp : Defines the functions for the static library.
//

#include "GameEngine.h"
#include <iostream>
#include <SFML/Graphics.hpp>


GameEngine::GameEngine() :
	window(800, 400, "someName"),//only for now
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
		system("cls");
		auto currentTime = clock.getElapsedTime();
		oftenUpdate();
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
	this->player.update(this->dt, this->window.getInstance().getPosition());
	this->map.update(dt);
	
}

void GameEngine::render()
{
	auto& window = this->window.getInstance();

	window.clear();

	this->window.draw(map);


	window.display();
}

void GameEngine::oftenUpdate()
{
	this->player.updateDirection();
	this->player.updateMouse(this->window.getInstance().getPosition());
}

void GameEngine::checkForQuit()
{
	auto& window = this->window.getInstance();

	while (window.pollEvent(quitEvent))
		if (quitEvent.type == sf::Event::Closed)
			window.close();
}

