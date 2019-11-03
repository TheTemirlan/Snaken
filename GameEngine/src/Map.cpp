#include "Map.h"

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
			map[i][j] = new MapPoint(
				sf::Vector2f((float)i * 10, (float)j * 10), MapPointType::Default);
		}
	}
}

void Map::CreateMap()
{

}

void Map::update()
{

}
