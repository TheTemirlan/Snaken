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

	void draw(Player player);
	
	void draw(Map map);


private:
	sf::RenderWindow window; 

};

