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
				swap_rect(arr[p], arr[p - 1], window);
				p--;
				window_handler(arr, window);
				clock.restart();
				arr[p + 1].setFillColor(sf::Color::White);
				arr[p].setFillColor(sf::Color::White);
			}
			
		}
	}
}

void insertionSort::swap_rect(sf::RectangleShape &s1, sf::RectangleShape &s2, sf::RenderWindow& window)
{
	sf::Vector2f aux_size;
	aux_size = s1.getSize();
	s1.setSize(s2.getSize());
	s1.setPosition(s1.getPosition().x, window.getView().getSize().y - s1.getSize().y);
	s2.setSize(aux_size);
	s2.setPosition(s2.getPosition().x, window.getView().getSize().y - s2.getSize().y);
}

void insertionSort::window_handler(std::vector<sf::RectangleShape>& arr, sf::RenderWindow& window)
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