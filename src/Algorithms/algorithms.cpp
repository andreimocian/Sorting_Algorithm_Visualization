#include "algorithms.h"

void algorithms::swap_rect(sf::RectangleShape& s1, sf::RectangleShape& s2, sf::RenderWindow& window)
{
	sf::Vector2f aux_size;
	aux_size = s1.getSize();
	s1.setSize(s2.getSize());
	s1.setPosition(s1.getPosition().x, window.getView().getSize().y - s1.getSize().y);
	s2.setSize(aux_size);
	s2.setPosition(s2.getPosition().x, window.getView().getSize().y - s2.getSize().y);
}

void algorithms::window_handler(std::vector<sf::RectangleShape>& arr, sf::RenderWindow& window)
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