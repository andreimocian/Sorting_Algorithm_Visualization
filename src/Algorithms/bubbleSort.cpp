#include "bubbleSort.h"
#include <SFML/Graphics.hpp>
#include <vector>

void bubbleSort::bubble_sort_run(std::vector<sf::RectangleShape>& arr, sf::RenderWindow& window)
{
	bool sorted;
	do
	{
		sorted = true;
		int i = 0;
		while(i < arr.size() - 1)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				return;
			if (arr[i].getSize().y > arr[i + 1].getSize().y)
			{
				alg.swap_rect(arr[i], arr[i + 1], window);
				sorted = false;
				arr[i].setFillColor(sf::Color::Blue);
				arr[i+1].setFillColor(sf::Color::Blue);
				alg.window_handler(arr, window);
				arr[i].setFillColor(sf::Color::White);
				arr[i + 1].setFillColor(sf::Color::White);
			}
			if (clock.getElapsedTime().asMilliseconds() >= 5.0f)
			{
				i++;
				clock.restart();
			}
		}
	} while (!sorted);
	
}