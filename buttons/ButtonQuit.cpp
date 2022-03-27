/*
** EPITECH PROJECT, 2022
** jam_2022
** File description:
** ButtonQuit
*/

#include "ButtonQuit.hpp"

ButtonQuit::ButtonQuit(int x, int y)
{
    this->spriteIndex = 0;
    this->x = x;
    this->y = y;
}

ButtonQuit::~ButtonQuit()
{    
}

bool ButtonQuit::onStep(int mouse_x, int mouse_y, bool mb_left, bool left_released)
{
    int xdif = mouse_x - this->x;
    int ydif = mouse_y - this->y;
    
    if (xdif < 0)
        xdif = -1 * xdif;
    if (ydif < 0)
        ydif = -1 * ydif;
    if (xdif < 64 && ydif < 24) {
        if (mb_left)
            this->spriteIndex = 5;
        else
            this->spriteIndex = 4;
        if (left_released)
            return true;
    } else {
        this->spriteIndex = 3;
    }
    return false;
}

int ButtonQuit::getSpriteIndex()
{
    return this->spriteIndex;
}

int ButtonQuit::getx()
{
    return this->x;
}

int ButtonQuit::gety()
{
    return this->y;
}