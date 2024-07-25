#pragma once
#include "algorithms.h"
#include <vector>
#include <SFML/Graphics.hpp>

class insertionSort
{
public:
	void insertion_sort_run(std::vector<sf::RectangleShape>&arr, sf::RenderWindow& window);
	void swap_rect(sf::RectangleShape &s1, sf::RectangleShape &s2, sf::RenderWindow& window);
	void window_handler(std::vector<sf::RectangleShape>& arr, sf::RenderWindow& window);
private:
	sf::Clock clock;
	algorithms alg;
};
