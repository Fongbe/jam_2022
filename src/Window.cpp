/*
** EPITECH PROJECT, 2022
** jam2
** File description:
** Window
*/

#include <vector>
#include <iostream>
#include "Window.hpp"

Window::Window()
{
    this->initWindow();
}

Window::~Window()
{
    if (this->_window.isOpen())
        this->_window.close();
}

void Window::initWindow()
{
    this->_window.create(sf::VideoMode(1600, 900, 32),  "GameOfLife");
    this->_window.setVerticalSyncEnabled(true);
    this->_window.setFramerateLimit(60);
    this->_window.setKeyRepeatEnabled(true);
}

bool Window::isWindowOpen()
{
    return this->_window.isOpen();
}

void Window::windowClear()
{
    this->_window.clear();
}

void Window::windowDisplay()
{
    this->_window.display();
}

void Window::drawSprite(Sprite &spr, float x, float y)
{
    spr.spr.setPosition(sf::Vector2f(x, y));
    this->_window.draw(spr.spr);
}
void Window::menu()
{
    sf::Event _event;

    while (this->isWindowOpen()) {

        while (this->_window.pollEvent(_event)) {
            if (_event.type == _event.Closed)
                this->_window.close();
        }

        this->windowClear();

        this->windowDisplay();
    }
}