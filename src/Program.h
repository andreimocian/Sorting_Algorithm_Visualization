#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "ui.h"
#include "Algorithms/insertionSort.h"
#include "Algorithms/bubbleSort.h"
#include "Algorithms/selectionSort.h"
#include "Algorithms/mergeSort.h"

class Program
{
public:
	Program();
	void run();
	void generete_rect();
	void draw_rect();
	void run_logic();
	void window_display();
	void make_green();

	std::vector<sf::RectangleShape>arr;
	
private:
	int w_width;
	int w_height;
	int rect_number = 80;
	sf::RenderWindow window;
	int state;
	UI ui;
	insertionSort insertion_sort;
	bubbleSort bubble_sort;
	selectionSort selection_sort;
	mergeSort merge_sort;
	sf::Clock clock;
};

