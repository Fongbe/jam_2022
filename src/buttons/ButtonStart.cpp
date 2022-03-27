/*
** EPITECH PROJECT, 2022
** jam_2022
** File description:
** ButtonStart
*/

#include "ButtonStart.hpp"

ButtonStart::ButtonStart(int x, int y)
{
    this->spriteIndex = 0;
    this->x = x;
    this->y = y;
}

ButtonStart::~ButtonStart()
{    
}

bool ButtonStart::onStep(int mouse_x, int mouse_y, bool mb_left, bool left_released)
{
    int xdif = mouse_x - this->x;
    int ydif = mouse_y - this->y;
    
    if (xdif < 0)
        xdif = -1 * xdif;
    if (ydif < 0)
        ydif = -1 * ydif;
    if (xdif < 64 && ydif < 24) {
        if (mb_left)
            this->spriteIndex = 2;
        else
            this->spriteIndex = 1;
        if (left_released)
            return false;
    } else {
        this->spriteIndex = 0;
    }
    return true;
}

int ButtonStart::getSpriteIndex()
{
    return this->spriteIndex;
}

int ButtonStart::getx()
{
    return this->x;
}

int ButtonStart::gety()
{
    return this->y;
}