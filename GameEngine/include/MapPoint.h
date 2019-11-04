#pragma once
#include "SFML/Graphics.hpp"
enum class MapPointType{Snake, Food, Border, Default};


class MapPoint
{

public:
	MapPoint(sf::Vector2f);
	MapPoint(sf::Vector2f, MapPointType type);

	friend class Map;
	friend class Window;
private:
	sf::Vector2f scale;
	MapPointType type;
	

};

