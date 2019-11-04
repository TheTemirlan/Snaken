#include "Player.h"
#include <iostream>
#include <thread>

Player::Player(std::vector<std::vector<MapPointType>>& map):
	playerShape(sf::Vector2f(10.f,10.f)),
	map(map),
	curPos(1,1)
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
	static PlayerDirection direction = PlayerDirection::Right;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && (direction != PlayerDirection::Down))
	{
		direction = PlayerDirection::Up;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (direction != PlayerDirection::Right))
	{
		direction = PlayerDirection::Left;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && (direction != PlayerDirection::Up))
	{
		direction = PlayerDirection::Down;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (direction != PlayerDirection::Left))
	{
		direction = PlayerDirection::Right;
	}

	auto oldPos = this->curPos;

	switch (direction)
	{
	case PlayerDirection::Up:
		this->curPos.second--;
		break;
	case PlayerDirection::Left:
		this->curPos.first--;
		break;
	case PlayerDirection::Right:
		this->curPos.first++;
		break;
	case PlayerDirection::Down:
		this->curPos.second++;
		break;
	default:
		break;
	}
	this->checkForMapBorder(direction);
	this->checkForCollision(direction);
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	//TODO: fist possition is not clearing

	//DEBUG 
	/*system("cls");
	std::cout << "player curpos" << this->curPos.first << "\t" << this->curPos.second << std::endl;
	std::cout << "player oldpos" << oldPos.first << "\t" << oldPos.second << std::endl;*/

	map[this->curPos.first][this->curPos.second] = MapPointType::Snake;
	map[oldPos.first][oldPos.second] = MapPointType::Default;
}

void Player::checkForCollision(PlayerDirection direction)
{
	if (this->map[curPos.first][curPos.second] == MapPointType::Food)
	{
		map[curPos.first][curPos.second] = MapPointType::Border;
		map[rand() % 80][rand() % 40] = MapPointType::Food;

	}
}

void Player::checkForMapBorder(PlayerDirection direction)
{
	if (this->curPos.first == 80)
		this->curPos.first = 0;
	if (this->curPos.first == -1)
		this->curPos.first = 79;
	if (this->curPos.second == 40)
		this->curPos.second = 0;
	if (this->curPos.second == -1)
		this->curPos.second = 39;
}
