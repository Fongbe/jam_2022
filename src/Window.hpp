/*
** EPITECH PROJECT, 2022
** jam2
** File description:
** Window
*/

#ifndef WINDOW_HPP_
#define WINDOW_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#include "Sprite.hpp"

class Window {
    public:
        Window();
        ~Window();
        void windowClear();
        void windowDisplay();
        void drawSprite(Sprite&, float x, float y);
        bool isWindowOpen();
        void initWindow();
        void menu();

    private:
        sf::RenderWindow _window;
};

#endif /* !WINDOW_HPP_ */