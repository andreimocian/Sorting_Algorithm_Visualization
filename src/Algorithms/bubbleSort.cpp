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
				swap_rect(arr[i], arr[i + 1], window);
				sorted = false;
				arr[i].setFillColor(sf::Color::Blue);
				arr[i+1].setFillColor(sf::Color::Blue);
				window_handler(arr, window);
				arr[i].setFillColor(sf::Color::White);
				arr[i + 1].setFillColor(sf::Color::White);
			}
			
			if (clock.getElapsedTime().asMilliseconds() >= 10.0f)
			{
				i++;
				clock.restart();
			}
		}
	} while (!sorted);
	
}

void bubbleSort::swap_rect(sf::RectangleShape& s1, sf::RectangleShape& s2, sf::RenderWindow& window)
{
	sf::Vector2f aux_size;
	aux_size = s1.getSize();
	s1.setSize(s2.getSize());
	s1.setPosition(s1.getPosition().x, window.getView().getSize().y - s1.getSize().y);
	s2.setSize(aux_size);
	s2.setPosition(s2.getPosition().x, window.getView().getSize().y - s2.getSize().y);
}

void bubbleSort::window_handler(std::vector<sf::RectangleShape>& arr, sf::RenderWindow& window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
			exit(0);
		}
	}
	window.clear();
	for (int i = 0; i < arr.size(); i++)
	{
		window.draw(arr[i]);
	}
	window.display();
}