#pragma once
#include "algorithms.h"
#include <vector>
#include <SFML/Graphics.hpp>

class insertionSort
{
public:
	void insertion_sort_run(std::vector<sf::RectangleShape>&arr, sf::RenderWindow& window);
private:
	sf::Clock clock;
	algorithms alg;
};
