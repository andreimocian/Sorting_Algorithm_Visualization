#include <SFML/Graphics.hpp>
#include <ctime>
#include "Program.h"
#include "ui.h"
#include "Algorithms/insertionSort.h"
#include "Algorithms/bubbleSort.h"
#include "Algorithms/selectionSort.h"

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
        draw_rect();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            state = 0;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && clock.getElapsedTime().asMilliseconds() >= 200.0f)
        {
            clock.restart();
            insertion_sort.insertion_sort_run(arr, window);
            make_green();
        }
        break;
    case 2:
        draw_rect();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            state = 0;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && clock.getElapsedTime().asMilliseconds() >= 200.0f)
        {
            clock.restart();
            bubble_sort.bubble_sort_run(arr, window);
            make_green();
        }
        break;
    case 3:
        draw_rect();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            state = 0;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && clock.getElapsedTime().asMilliseconds() >= 200.0f)
        {
            clock.restart();
            selection_sort.selection_sort_run(arr, window);
            make_green();
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

void Program::draw_rect()
{
    for (int i = 0; i < arr.size(); i++)
    {
        window.draw(arr[i]);
    }
}

void Program::make_green()
{
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i].setFillColor(sf::Color::Green);
    }
}