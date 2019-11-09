#pragma once
#include "../Window.h"
#include "../Player.h"
#include <Map.h>

class GameEngine {
public:
	GameEngine();

	void run();


private:
	//members
	Window window;

	Player player;

	Map map;

	sf::Event quitEvent;

	sf::Clock dtClock;
	float dt;
	int previousUpdateTime_ = 0;
	int deltaTime_ = 50;
	sf::Clock clock;

	//functions
	void update();

	void render();

	void oftenUpdate();
	void checkForQuit();
};
