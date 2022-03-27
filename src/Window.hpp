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
#include <iostream>
#include <string>
#include "Sprite.hpp"
#include "buttons/ButtonStart.hpp"
#include "buttons/ButtonMusic.hpp"
#include "buttons/ButtonQuit.hpp"
#include "buttons/ButtonHelp.hpp"

class Window {
    public:
        Window();
        ~Window();
        void windowClear();
        void windowDisplay();
        void drawSprite(Sprite &spr, float x, float y);
        bool isWindowOpen();
        void initWindow();
        void getEvent();
        void loop();
        void loopMenu();
        void loopGame();

    private:
        std::vector<Sprite*> sprites;
        int mouse_x = 0;
        int mouse_y = 0;
        bool mb_left = false;
        bool left_released = false;
        sf::RenderWindow _window;
        
        bool menu;
        bool music;
        bool help;
        bool pause;
        
        ButtonStart *buttonStart;
        ButtonQuit *buttonQuit;
        ButtonMusic *buttonMusic;
        ButtonHelp *buttonHelp;
};

#endif /* !WINDOW_HPP_ */