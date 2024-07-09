#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "ui.h"
class Program
{
public:
	Program();
	void run();
	void generete_rect();
	void render_rect();
	void run_logic();

	std::vector<sf::RectangleShape>arr;
	
private:
	int w_width;
	int w_height;
	int rect_number = 80;
	sf::RenderWindow window;
	int state;
	UI ui;
};

