#include "ui.h"
#include "Program.h"
#include <iostream>
#include <cmath>

UI::UI()
{
	//algorithm 1: Insertion sort
	//algorithm 2: Bubble sort
	//algorithm 3: Selection sort
	alg_selector = 0;
	sf::Text text;
	
	load_font();
	text.setFont(font);
	text.setString("Insertion sort");
	text.setCharacterSize(48);
	algorithms.push_back(text);

	text.setString("Bubble sort");
	algorithms.push_back(text);

	text.setString("Selection sort");
	algorithms.push_back(text);
}

void UI::load_font()
{
	if (!font.loadFromFile("Assets/consola.ttf"))
	{
		std::cout << "Cannot load font";
		exit(-1);
	}
}

void UI::ui_input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && clock.getElapsedTime().asMilliseconds() >= 200.0f)
	{
		clock.restart();
		if (alg_selector == 0)
			alg_selector = algorithms.size() - 1;
		else
			alg_selector--;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right) && clock.getElapsedTime().asMilliseconds() >= 200.0f)
	{
		clock.restart();
		alg_selector++;
	}
	alg_selector = alg_selector % (algorithms.size());
	
}

void UI::render_triangles()
{
	right_triangle.setPointCount(3);
	right_triangle.setRadius(40);
	right_triangle.rotate(90.0f);
	right_triangle.setRotation(90.0f);
	right_triangle.setOrigin(right_triangle.getGlobalBounds().getSize() / 2.f + right_triangle.getLocalBounds().getPosition());

	left_triangle.setPointCount(3);
	left_triangle.setRadius(40);
	left_triangle.rotate(90.0f);
	left_triangle.setRotation(-90.0f);
	left_triangle.setOrigin(right_triangle.getGlobalBounds().getSize() / 2.f + right_triangle.getLocalBounds().getPosition());
}

void UI::render_ui(sf::RenderWindow &window)
{
	render_triangles();
	ui_input();
	algorithms[alg_selector].setOrigin(algorithms[alg_selector].getGlobalBounds().getSize() / 2.f + algorithms[alg_selector].getLocalBounds().getPosition());
	algorithms[alg_selector].setPosition(sf::Vector2f(window.getView().getCenter()));
	window.draw(algorithms[alg_selector]);

	right_triangle.setPosition(sf::Vector2f(window.getView().getSize()).x - 50 , sf::Vector2f(window.getView().getSize()).y / 2);
	window.draw(right_triangle);

	left_triangle.setPosition(50, sf::Vector2f(window.getView().getSize()).y / 2);
	window.draw(left_triangle);
}

int UI::get_algorithm()
{
	return alg_selector;
}