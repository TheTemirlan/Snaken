#pragma once
#include "../Window.h"
#include "../Player.h"

class GameEngine {
public:
	GameEngine();

	void run();


private:
	//members
	Window window;

	Player player;

	sf::Event quitEvent;


	//functions
	void update();

	void render();

	void checkForQuit();
};
