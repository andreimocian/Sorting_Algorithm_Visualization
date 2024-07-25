#include "selectionSort.h"

void selectionSort::selection_sort_run(std::vector<sf::RectangleShape>& arr, sf::RenderWindow& window)
{
	for (int i = 0; i < arr.size() - 1; i++)
	{
		int j = i + 1;
		while(j < arr.size())
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				return;
			if (arr[i].getSize().y > arr[j].getSize().y)
			{
				arr[i].setFillColor(sf::Color::Blue);
				arr[j].setFillColor(sf::Color::Blue);
				alg.swap_rect(arr[i], arr[j], window);
				alg.window_handler(arr, window);
				arr[i].setFillColor(sf::Color::White);
				arr[j].setFillColor(sf::Color::White);
			}
			if (clock.getElapsedTime().asMilliseconds() >= 5.0f)
			{
				j++;
				clock.restart();
			}
		}	
	}
}