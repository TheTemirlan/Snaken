#include "Player.h"
#include <iostream>

Player::Player():
	playerShape(sf::Vector2f(20.f,20.f))
{

}

void Player::update(float dt)
{
	updateMovement(dt);
}

sf::RectangleShape& Player::getShape()
{
	return playerShape;
}

void Player::updateMovement(float dt)
{
	// DEBUG
	std::cout << "Player " << playerShape.getPosition().x << "\t" << playerShape.getPosition().y << std::endl;
	
	static float step = 400;
	static float deltaY = 0.f,
		deltaX = step;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		step += 20.f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		step -= 20.f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (deltaY == 0.f))
	{
		deltaY = -step;
		deltaX = 0.f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (deltaX == 0.f))
	{
		deltaX = -step;
		deltaY = 0.f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (deltaY == 0.f))
	{
		deltaY = step;
		deltaX = 0.f;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (deltaX == 0.f))
	{
		deltaX = step;
		deltaY = 0.f;
	}
	
	if (playerShape.getPosition().x > 800.f)
		playerShape.setPosition(
			0.f,
			playerShape.getPosition().y);
	if (playerShape.getPosition().x < 0.f)
		playerShape.setPosition(
			800.f,
			playerShape.getPosition().y);
	if (playerShape.getPosition().y > 400.f)
		playerShape.setPosition(
			playerShape.getPosition().x,
			0.f);
	if (playerShape.getPosition().y < 0.f)
		playerShape.setPosition(
			playerShape.getPosition().x,
			400.f);

	playerShape.setPosition(
		playerShape.getPosition().x + deltaX * dt, 
		playerShape.getPosition().y + deltaY * dt);
}
