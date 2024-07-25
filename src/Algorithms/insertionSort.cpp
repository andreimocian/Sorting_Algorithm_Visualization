#include "insertionSort.h"
#include <SFML/Graphics.hpp>
#include <vector>

void insertionSort::insertion_sort_run(std::vector<sf::RectangleShape>& arr, sf::RenderWindow& window)
{
	for (int i = 1; i < arr.size(); i++)
	{
		int p = i;
		while (p > 0 && arr[p].getSize().y < arr[p - 1].getSize().y)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				return;
			arr[p].setFillColor(sf::Color::Blue);
			arr[p - 1].setFillColor(sf::Color::Blue);
			if (clock.getElapsedTime().asMilliseconds() >= 10.0f)
			{
				alg.swap_rect(arr[p], arr[p - 1], window);
				p--;
				alg.window_handler(arr, window);
				clock.restart();
				arr[p + 1].setFillColor(sf::Color::White);
				arr[p].setFillColor(sf::Color::White);
			}
			
		}
	}
	alg.make_green(arr, window);
}