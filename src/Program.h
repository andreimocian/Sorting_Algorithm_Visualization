#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class Program
{
public:
	Program();
	void genereta_rect();
	void render_rect();

	std::vector<sf::RectangleShape>arr;

private:
	int w_width;
	int w_height;
	int rect_number = 80;
	sf::RenderWindow window;

};

