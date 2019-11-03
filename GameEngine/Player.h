#pragma once
#include "SFML/Graphics.hpp"

class Player
{
public:
	Player();

	void update(float dt);

	sf::RectangleShape& getShape();
private:
	//members
	sf::RectangleShape playerShape;


	//functions
	void updateMovement(float dt);
};

