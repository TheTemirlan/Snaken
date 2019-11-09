#include "Player.h"
#include <iostream>
#include <thread>

Player::Player(std::vector<std::vector<MapPointType>>& map):
	playerShape(sf::Vector2f(10.f,10.f)),
	map(map),
	headPos(new SnakeNode(new SnakeNode(new SnakeNode(nullptr, { 2,1 }), { 3,1 }), { 4,1 })),
	windPos(windPos)
{
	this->windPos = { 800,400 };
}

void Player::update(float dt, sf::Vector2i windPos)
{
	updateMovement(dt);
	updateMouse(windPos);
}

sf::RectangleShape& Player::getShape()
{
	return playerShape;
}

void Player::updateDirection() {
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
}

void Player::updateMovement(float dt)
{
	auto nextPos = this->headPos->second;

	static PlayerDirection oldDirection = this->direction;

	if (oldDirection == this->getInvers(this->direction))
		direction = oldDirection;

	switch (direction)
	{
	case PlayerDirection::Up:
		//this->headPos->second.second--;
		nextPos.second--;
		break;
	case PlayerDirection::Left:
		//this->headPos->second.first--;
		nextPos.first--;
		break;
	case PlayerDirection::Right:
		//this->headPos->second.first++;
		nextPos.first++;
		break;
	case PlayerDirection::Down:
		//this->headPos->second.second++;
		nextPos.second++;
		break;
	default:
		break;
	}

	oldDirection = this->direction;

	this->checkForMapBorder(nextPos);




	//CheckForBorderCollision
	if (this->map[nextPos.first][nextPos.second] == MapPointType::Border)
	{
		return;
	}



	//CheckForFoodCollision
	if (this->map[nextPos.first][nextPos.second] == MapPointType::Food)
	{
		auto temp = this->headPos;
		this->headPos = new SnakeNode(temp, nextPos);
		
		//Adding new food;
		this->map[rand() % 80][rand() % 40] = MapPointType::Food;
	}
	
	//SimpleMovement
	if (this->map[nextPos.first][nextPos.second] == MapPointType::Default)
	{
		auto result = this->headPos->setNewCoords(nextPos);
		map[result.first][result.second] = MapPointType::Default;
	}
	
	if (this->map[nextPos.first][nextPos.second] == MapPointType::Snake)
	{
		this->lose(nextPos);
		this->map[nextPos.first][nextPos.second] == MapPointType::Default;
	}

		
	this->updateMap();


}


void Player::updateMap()
{
	auto temp = headPos;
	while (temp->first != nullptr)
	{
		map[temp->second.first][temp->second.second] = MapPointType::Snake;
		temp = temp->first;
	}
	map[temp->second.first][temp->second.second] = MapPointType::Snake;
}



void Player::checkForMapBorder(Coords& nextPos)
{
	if (nextPos.second == 40)
		nextPos.second = 0;
	if (nextPos.second == -1)
		nextPos.second = 39;
	if (nextPos.first == 80)
		nextPos.first = 0;
	if (nextPos.first == -1)
		nextPos.first = 79;
}

void Player::lose(Coords& collisionCoords)
{
	auto posToCut = this->headPos->first;
	while (posToCut->first != nullptr)
	{
		if (posToCut->first->second.first == collisionCoords.first && posToCut->first->second.second == collisionCoords.second)
			break;
		posToCut = posToCut->first;
	}
	
	
	
	auto cutFrom = posToCut;
	posToCut = posToCut->first;
	while (posToCut != nullptr)
	{
		this->map[posToCut->second.first][posToCut->second.second] = MapPointType::Default;
		posToCut = posToCut->first;
	}

	cutFrom->cutFrom(cutFrom);
	/*while (1) {
		std::cout << "You lost!" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}*/
}

void Player::updateMouse(sf::Vector2i windPos)
{
	this->windPos = windPos;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		sf::Vector2i mousePos = sf::Mouse::getPosition() - this->windPos;
		mousePos.x -= 8;
		mousePos.y -= 30;
		std::cout << mousePos.x << "\t" << mousePos.y << std::endl;

		mousePaint(mousePos);
	}
}


void Player::mousePaint(sf::Vector2i mousePos)
{
	if (mousePos.x < 0 || mousePos.x > 800)
		return;
	if (mousePos.y < 0 || mousePos.y > 400)
		return;
	map[mousePos.x/10][mousePos.y/10] = MapPointType::Border;
}

PlayerDirection Player::getInvers(PlayerDirection dir)
{
	switch (dir)
	{
	case PlayerDirection::Up:
		return PlayerDirection::Down;
		break;
	case PlayerDirection::Left:
		return PlayerDirection::Right;
		break;
	case PlayerDirection::Right:
		return PlayerDirection::Left;
		break;
	case PlayerDirection::Down:
		return PlayerDirection::Up;
		break;
	case PlayerDirection::None:
		return PlayerDirection::None;
		break;
	default:
		break;
	}
}