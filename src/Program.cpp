#include <SFML/Graphics.hpp>
#include <ctime>
#include "Program.h"
#include "ui.h"
#include "Algorithms/insertionSort.h"

Program::Program()
{
    state = 0;
    w_width = 1024, w_height = 512;
    window.create(sf::VideoMode(w_width, w_height), "Visual Sort", sf::Style::Default);

    run();
}

void Program::run()
{
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
        run_logic();
        window.display();
    }
}

void Program::run_logic()
{
    switch (state)
    {
    case 0:
        ui.render_ui(window);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            arr.clear();
            generete_rect();
            state = ui.get_algorithm() + 1;
        }
        break;
    case 1:
        render_rect();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            state = 0;
        }
        break;
    case 2:
        render_rect();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            state = 0;
        }
        break;
    case 3:
        render_rect();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            state = 0;
        }
        break;
    default:
        break;
    }
}

void Program::generete_rect()
{
    srand((unsigned)time(NULL));

    sf::RectangleShape rectangle;
    int height;
    float rectangle_width = (float)w_width / rect_number;
    float position = 0;
    for (int i = 0; i < rect_number; i++)
    {
        height = 1 + rand() % 400;
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