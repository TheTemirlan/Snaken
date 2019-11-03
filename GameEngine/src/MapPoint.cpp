#include "MapPoint.h"
MapPoint::MapPoint(sf::Vector2f scale):
	scale(scale),
	type(MapPointType::Default)
{
	
}

MapPoint::MapPoint(sf::Vector2f scale, MapPointType type):
	scale(scale),
	type(MapPointType::Default)
{

}
