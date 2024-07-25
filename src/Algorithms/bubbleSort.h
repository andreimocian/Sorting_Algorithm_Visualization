#pragma once
#include "algorithms.h"
#include <SFML/Graphics.hpp>
#include <vector>

class bubbleSort
{
public:
	void bubble_sort_run(std::vector<sf::RectangleShape>& arr, sf::RenderWindow& window);

private:
	sf::Clock clock;
	algorithms alg;
};