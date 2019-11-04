#pragma once
#include "SFML/Graphics.hpp"
#include <Map.h>

class Player
{
public:
	Player(std::vector<std::vector<MapPointType>>& map);

	void update(float dt);

	sf::RectangleShape& getShape();
private:
	//members
	sf::RectangleShape playerShape;

	std::vector<std::vector<MapPointType>>& map;
	std::pair<int, int> curPos;

	//functions
	void updateMovement(float dt);

	void checkForCollision(PlayerDirection direction);

	void checkForMapBorder(PlayerDirection direction);
};

