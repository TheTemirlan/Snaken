#pragma once
#include"SFML/Graphics.hpp"
#include "Player.h"
#include <Map.h>

class Window
{
public:
	Window(int width, int heigth, std::string windName);

	sf::RenderWindow& getInstance() {
		return window;
	}

	void draw(Player& player);
	
	void draw(Map& map);
	
	void draw(MapPointType pointType);

	
private:
	//members
	sf::RenderWindow window;

	std::vector<sf::Color> colors;

	std::vector<sf::RectangleShape> shapes;

	PlayerDirection getInvers(PlayerDirection dir);
	
	//functions
	void draw(MapPoint& point);
};

