#include <SFML/Graphics.hpp>
#include <ctime>
#include "Program.h"
#include "Algorithms/insertionSort.h"

Program::Program()
{
    w_width = 1024, w_height = 512;
    window.create(sf::VideoMode(w_width, w_height), "Visual Sort", sf::Style::Default);

    genereta_rect();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        render_rect();
        window.display();
    }
}

void Program::genereta_rect()
{
    srand((unsigned)time(NULL));

    sf::RectangleShape rectangle;
    int height;
    float rectangle_width = (float)w_width / rect_number;
    float position = 0;
    for (int i = 0; i < rect_number; i++)
    {
        height = 1 + rand() % 400;
        printf("%d ", height);
        rectangle.setSize(sf::Vector2f(rectangle_width, height));
        rectangle.setPosition(position, w_height - height);
        arr.push_back(rectangle);
        position += (float)w_width / rect_number;
    }
}

void Program::render_rect()
{
    for (int i = 0; i < arr.size(); i++)
    {
        window.draw(arr[i]);
    }
}