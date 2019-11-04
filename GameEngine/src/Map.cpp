#include "Map.h"
#include <thread>
#include <iostream>


Map::Map(int width, int heigth) :
	map(width)
{
	for (size_t i = 0; i < this->map.size(); i++)
	{
		this->map[i].resize(heigth);
	}
	for (size_t i = 0; i < this->map.size(); i++)
	{
		for (size_t j = 0; j < this->map[i].size(); j++)
		{
			/*map[i][j] = new MapPoint(
				sf::Vector2f((float)i * 10, (float)j * 10), MapPointType::Default);*/
			map[i][j] = MapPointType::Default;
		}
	}

	//Delete later
	map[20][1] = MapPointType::Food;
	map[21][1] = MapPointType::Food;
	map[22][1] = MapPointType::Food;
	map[23][1] = MapPointType::Food;
	map[24][1] = MapPointType::Food;
	map[25][1] = MapPointType::Food;
	map[26][1] = MapPointType::Food;
	map[27][1] = MapPointType::Food;
	map[28][1] = MapPointType::Food;
	map[29][1] = MapPointType::Food;
	map[30][1] = MapPointType::Food;
	
}

void Map::CreateMap()
{

}

void Map::update(float dt)
{
	//this->updatePlayer(dt);
}

std::vector<std::vector<MapPointType>>& Map::getMap()
{
	return this->map;
}

