#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class selectionSort
{
public:
	void selection_sort_run(std::vector<sf::RectangleShape>& arr, sf::RenderWindow& window);
	void swap_rect(sf::RectangleShape& s1, sf::RectangleShape& s2, sf::RenderWindow& window);
	void window_handler(std::vector<sf::RectangleShape>& arr, sf::RenderWindow& window);

private:
	sf::Clock clock;
};
