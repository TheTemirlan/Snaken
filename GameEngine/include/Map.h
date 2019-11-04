#pragma once
#include "SFML/Graphics.hpp"
#include <MapPoint.h>

enum class PlayerDirection { Up, Left, Right, Down, None };

class Map
{
public: 
	Map(int width, int heigth);
	void CreateMap();

	void update(float dt);

	friend class Window;

	std::vector<std::vector<MapPointType>>& getMap();
private:
	std::vector<std::vector<MapPointType>> map;




};

