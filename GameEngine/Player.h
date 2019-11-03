#pragma once
#include "SFML/Graphics.hpp"

class Player
{
public:
	Player();

	void update();

	sf::RectangleShape& getShape();
private:
	//members
	sf::RectangleShape playerShape;


	//functions
	void updateMovement();
};

