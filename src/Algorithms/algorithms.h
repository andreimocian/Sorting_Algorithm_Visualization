#pragma once
#include <SFML/Graphics.hpp>

class algorithms
{
public:
	void swap_rect(sf::RectangleShape& s1, sf::RectangleShape& s2, sf::RenderWindow& window);
	void window_handler(std::vector<sf::RectangleShape>& arr, sf::RenderWindow& window);
	void make_green(std::vector<sf::RectangleShape>& arr, sf::RenderWindow& window);
};