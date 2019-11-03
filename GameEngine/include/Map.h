#pragma once
#include "SFML/Graphics.hpp"
#include <MapPoint.h>

class Map
{
public: 
	Map(int width, int heigth);
	void CreateMap();

	friend class Window;
private:
	std::vector<std::vector<MapPoint*>> map;

	void update();

};

