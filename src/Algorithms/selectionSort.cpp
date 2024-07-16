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
				swap_rect(arr[i], arr[j], window);
				window_handler(arr, window);
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

void selectionSort::swap_rect(sf::RectangleShape& s1, sf::RectangleShape& s2, sf::RenderWindow& window)
{
	sf::Vector2f aux_size;
	aux_size = s1.getSize();
	s1.setSize(s2.getSize());
	s1.setPosition(s1.getPosition().x, window.getView().getSize().y - s1.getSize().y);
	s2.setSize(aux_size);
	s2.setPosition(s2.getPosition().x, window.getView().getSize().y - s2.getSize().y);
}

void selectionSort::window_handler(std::vector<sf::RectangleShape>& arr, sf::RenderWindow& window)
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