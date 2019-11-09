#pragma once
#include "SFML/Graphics.hpp"
#include <Map.h>

using Coords = std::pair<int, int>;

class SnakeNode {
public:
	SnakeNode* first;
	Coords second;
	SnakeNode(SnakeNode* first, Coords second):
		first(first),
		second(second)
	{}
	Coords setNewCoords(Coords coords) {
		Coords result = this->second;
		if (this->first != nullptr) {
			result = this->first->setNewCoords(this->second);
			this->second = coords;
		}
		else {
			this->second = coords;
		}
		return result;
	}
};


class Player
{
public:
	Player(std::vector<std::vector<MapPointType>>& map);

	void update(float dt);

	void updateDirection();
	
	sf::RectangleShape& getShape();
private:
	//members
	sf::RectangleShape playerShape;

	std::vector<std::vector<MapPointType>>& map;
	SnakeNode* headPos;

	Coords startPos;
	int startLength;

	PlayerDirection direction = PlayerDirection::Right;

	//functions
	void updateMovement(float dt);


	void updateMap();

	void checkForMapBorder(Coords& coords);

	void chechForBorders();

	void lose();
};

