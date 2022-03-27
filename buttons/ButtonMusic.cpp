/*
** EPITECH PROJECT, 2022
** jam_2022
** File description:
** ButtonMusic
*/

#include "ButtonMusic.hpp"

ButtonMusic::ButtonMusic(int x, int y)
{
    this->spriteIndex = 0;
    this->x = x;
    this->y = y;
    this->on = true;
}

ButtonMusic::~ButtonMusic()
{    
}

bool ButtonMusic::onStep(int mouse_x, int mouse_y, bool mb_left, bool left_released)
{
    int xdif = mouse_x - this->x;
    int ydif = mouse_y - this->y;
    
    if (xdif < 0)
        xdif = -1 * xdif;
    if (ydif < 0)
        ydif = -1 * ydif;
    
    if (on) {
        if (xdif < 22 && ydif < 22) {
            if (mb_left)
                this->spriteIndex = 8;
            else
                this->spriteIndex = 7;
            if (left_released)
                this->on = false;
        } else {
            this->spriteIndex = 6;
        }
    } else  {
        if (xdif < 22 && ydif < 22) {
            if (mb_left)
                this->spriteIndex = 11;
            else
                this->spriteIndex = 10;
            if (left_released)
                this->on = true;
        } else {
            this->spriteIndex = 9;
        }
    }
    return this->on;
}

int ButtonMusic::getSpriteIndex()
{
    return this->spriteIndex;
}

int ButtonMusic::getx()
{
    return this->x;
}

int ButtonMusic::gety()
{
    return this->y;
}