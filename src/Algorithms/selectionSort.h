#pragma once
#include "algorithms.h"
#include <SFML/Graphics.hpp>
#include <vector>
class selectionSort
{
public:
	void selection_sort_run(std::vector<sf::RectangleShape>& arr, sf::RenderWindow& window);

private:
	sf::Clock clock;
	algorithms alg;
};
