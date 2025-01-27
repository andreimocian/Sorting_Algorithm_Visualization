#pragma once
#include "algorithms.h"
#include <SFML/Graphics.hpp>
#include <vector>
class mergeSort
{
public:
	void merge_sort_run(std::vector<sf::RectangleShape>& arr, sf::RenderWindow& window);
	void merge_sort(int left, int right, std::vector<sf::RectangleShape>& arr, sf::RenderWindow& window);
	void merge(int left, int right, int m, std::vector<sf::RectangleShape>& arr, sf::RenderWindow& window);
private:
	bool exit;
	std::vector <sf::RectangleShape> tmp;
	sf::Clock clock;
	algorithms alg;
};