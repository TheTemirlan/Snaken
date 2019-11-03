#include "Player.h"
#include <iostream>

Player::Player():
	playerShape(sf::Vector2f(20.f,20.f))
{

}

void Player::update()
{
	updateMovement();
}

sf::RectangleShape& Player::getShape()
{
	return playerShape;
}

void Player::updateMovement()
{
	// DEBUG
	std::cout << "Player " << playerShape.getPosition().x << "\t" << playerShape.getPosition().y << std::endl;
	float step = 1.f;
	static float deltaY = 0.f,
		deltaX = step;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		deltaY = -step;
		deltaX = 0.f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		deltaX = -step;
		deltaY = 0.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		deltaY = step;
		deltaX = 0.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		deltaX = step;
		deltaY = 0.f;
	}

	playerShape.setPosition(
		playerShape.getPosition().x + deltaX, 
		playerShape.getPosition().y + deltaY);
}
