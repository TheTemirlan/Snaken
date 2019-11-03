#include "Window.h"

Window::Window(int width, int heigth, std::string windName):
	window(sf::VideoMode(800, 400), "main window")
{
	
}

void Window::draw(Player player)
{
	auto& playerShape = player.getShape();

	
	window.draw(playerShape);
}

void Window::draw(Map map)
{

}
