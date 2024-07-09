#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class UI
{
public:
	UI();
	void load_font();
	void render_triangles();
	void render_ui(sf::RenderWindow &get_window);
	void ui_input();
	int get_algorithm();
	std::vector<sf::Text>algorithms;

private:
	sf::Font font;
	sf::Clock clock;
	sf::CircleShape right_triangle;
	sf::CircleShape left_triangle;
	int alg_selector;
};

