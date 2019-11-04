#include "Window.h"

Window::Window(int width, int heigth, std::string windName) :
	window(sf::VideoMode(800, 400), "main window"),
	colors(4),
	shapes(4)
{
	this->colors[(int)MapPointType::Snake] = sf::Color::Black;
	this->colors[(int)MapPointType::Food] = sf::Color::Green;
	this->colors[(int)MapPointType::Border] = sf::Color::Cyan;
	this->colors[(int)MapPointType::Default] = sf::Color::Blue;
	
	this->shapes[(int)MapPointType::Snake] = sf::RectangleShape(sf::Vector2f(10.f, 10.f));
	this->shapes[(int)MapPointType::Food] = sf::RectangleShape(sf::Vector2f(10.f, 10.f));
	this->shapes[(int)MapPointType::Border] = sf::RectangleShape(sf::Vector2f(10.f, 10.f));
	this->shapes[(int)MapPointType::Default] = sf::RectangleShape(sf::Vector2f(10.f, 10.f));

	this->shapes[(int)MapPointType::Snake].setFillColor(this->colors[(int)MapPointType::Snake]);
	this->shapes[(int)MapPointType::Food].setFillColor(this->colors[(int)MapPointType::Food]);
	this->shapes[(int)MapPointType::Border].setFillColor(this->colors[(int)MapPointType::Border]);
	this->shapes[(int)MapPointType::Default].setFillColor(this->colors[(int)MapPointType::Default]);
	




	//TODO: indexes as enum
	/*this->colors[MapPointType::Snake] = sf::Color::Black;
	this->colors[MapPointType::Food] = sf::Color::Green;
	this->colors[MapPointType::Border] = sf::Color::Cyan;
	this->colors[MapPointType::Default] = sf::Color::White;*/
}

void Window::draw(Player& player)
{
	auto& playerShape = player.getShape();

	
	window.draw(playerShape);
}

void Window::draw(Map& map)
{
	
	for (size_t i = 0; i < 80; i++)
	{
		for (size_t j = 0; j < 40; j++)
		{
			shapes[(int)map.map[i][j]].setPosition(sf::Vector2f((float)(i * 10), (float)(j * 10)));
			window.draw(shapes[(int)map.map[i][j]]);
		}
	}
}

void Window::draw(MapPointType pointType)
{
	
}

//void Window::draw(Map& map)
//{
//	for (auto& row : map.map)
//	{
//		for (auto& mapPoint : row)
//		{
//			this->draw(*mapPoint);
//		}
//	}
//}

//void Window::draw(MapPoint& point)
//{
//	pointShape.setPosition(point.scale);
//	pointShape.setFillColor(this->colors[(int)point.type]);
//
//	window.draw(pointShape);
//}
