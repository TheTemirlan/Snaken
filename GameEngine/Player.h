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
	void cutFrom(SnakeNode* node) {
		if (node->first == nullptr) {
			return;
		}
		if (node->first->first == nullptr)
		{
			delete node->first;
			node->first = nullptr;
			return;
		}
		auto next = node->first;
		node->first = nullptr;
		node = next;
		while (next != nullptr)
		{
			next = node->first;
			delete node;
			node = next;
		}
		
	}
};


class Player
{
public:
	Player(std::vector<std::vector<MapPointType>>& map);

	void update(float dt, sf::Vector2i windPos);

	void updateDirection();

	void updateMouse(sf::Vector2i windPos);

	sf::RectangleShape& getShape();
private:
	//members
	sf::RectangleShape playerShape;

	std::vector<std::vector<MapPointType>>& map;
	SnakeNode* headPos;

	Coords startPos;
	int startLength;
	
	sf::Vector2i windPos;
	

	PlayerDirection direction = PlayerDirection::Right;

	//functions
	void updateMovement(float dt);


	void updateMap();

	void checkForMapBorder(Coords& coords);

	void lose(Coords& cutTo);

	

	void mousePaint(sf::Vector2i mousePos);

	PlayerDirection getInvers(PlayerDirection dir);
};

