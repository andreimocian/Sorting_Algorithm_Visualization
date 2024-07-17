#include "mergeSort.h"
#include <SFML/Graphics.hpp>
#include <vector>

void mergeSort::merge_sort_run(std::vector<sf::RectangleShape>& arr, sf::RenderWindow& window)
{
	int left = 0;
	int right = arr.size() - 1;
	tmp.resize(arr.size() + 1);
	merge_sort(left, right, arr, window);
}

void mergeSort::merge_sort(int left, int right, std::vector<sf::RectangleShape>& arr, sf::RenderWindow& window)
{
	if (left < right)
	{
		int m = (left + right) / 2;
		merge_sort(left, m, arr, window);
		merge_sort(m + 1, right, arr, window);
		merge(left, right, m, arr, window);
	}
}

void mergeSort::merge(int left, int right, int m, std::vector<sf::RectangleShape>& arr, sf::RenderWindow& window)
{
	int i = left, j = m + 1, k = 0;
	while (i <= m && j <= right)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			return;
		if (arr[i].getSize().y < arr[j].getSize().y)
		{
			if (clock.getElapsedTime().asMilliseconds() >= 5.0f)
			{
				k++;
				tmp[k].setSize(arr[i].getSize());
				tmp[k].setPosition(tmp[k].getPosition().x, window.getView().getSize().y - tmp[k].getSize().y);
				i++;
				clock.restart();
			}
		}
		else
		{
			if (clock.getElapsedTime().asMilliseconds() >= 5.0f)
			{
				k++;
				tmp[k].setSize(arr[j].getSize());
				tmp[k].setPosition(tmp[k].getPosition().x, window.getView().getSize().y - tmp[k].getSize().y);
				j++;
				clock.restart();
			}
		}
	}

	while (i <= m)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			return;
		if (clock.getElapsedTime().asMilliseconds() >= 5.0f)
		{
			k++;
			tmp[k].setSize(arr[i].getSize());
			tmp[k].setPosition(tmp[k].getPosition().x, window.getView().getSize().y - tmp[k].getSize().y);
			i++;
			clock.restart();
		}
	}

	while (j <= right)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			return;
		if (clock.getElapsedTime().asMilliseconds() >= 5.0f)
		{
			k++;
			tmp[k].setSize(arr[j].getSize());
			tmp[k].setPosition(tmp[k].getPosition().x, window.getView().getSize().y - tmp[k].getSize().y);
			j++;
			clock.restart();
		}
	}

	i = left, j = 1;
	while (i <= right)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			return;
		if (clock.getElapsedTime().asMilliseconds() >= 5.0f)
		{
			arr[i].setSize(tmp[j].getSize());
			arr[i].setPosition(arr[i].getPosition().x, window.getView().getSize().y - arr[i].getSize().y);
			i++;
			j++;
			clock.restart();
			window_handler(arr, window);
		}
	}
	window_handler(arr, window);
}

void mergeSort::window_handler(std::vector<sf::RectangleShape>& arr, sf::RenderWindow& window)
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