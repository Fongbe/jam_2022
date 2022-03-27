/*
** EPITECH PROJECT, 2022
** jam_2022
** File description:
** ButtonRestart
*/

#include "ButtonRestart.hpp"

ButtonRestart::ButtonRestart(int x, int y)
{
    this->spriteIndex = 0;
    this->x = x;
    this->y = y;
}

ButtonRestart::~ButtonRestart()
{    
}

bool ButtonRestart::onStep(int mouse_x, int mouse_y, bool mb_left, bool left_released)
{
    int xdif = mouse_x - this->x;
    int ydif = mouse_y - this->y;
    
    if (xdif < 0)
        xdif = -1 * xdif;
    if (ydif < 0)
        ydif = -1 * ydif;
    if (xdif < 22 && ydif < 22) {
        if (mb_left)
            this->spriteIndex = 30;
        else
            this->spriteIndex = 29;
        if (left_released)
            return true;
    } else {
        this->spriteIndex = 28;
    }
    return false;
}

int ButtonRestart::getSpriteIndex()
{
    return this->spriteIndex;
}

int ButtonRestart::getx()
{
    return this->x;
}

int ButtonRestart::gety()
{
    return this->y;
}