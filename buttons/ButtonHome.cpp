/*
** EPITECH PROJECT, 2022
** jam_2022
** File description:
** ButtonHome
*/

#include "ButtonHome.hpp"

ButtonHome::ButtonHome(int x, int y)
{
    this->spriteIndex = 0;
    this->x = x;
    this->y = y;
}

ButtonHome::~ButtonHome()
{    
}

bool ButtonHome::onStep(int mouse_x, int mouse_y, bool mb_left, bool left_released)
{
    int xdif = mouse_x - this->x;
    int ydif = mouse_y - this->y;
    
    if (xdif < 0)
        xdif = -1 * xdif;
    if (ydif < 0)
        ydif = -1 * ydif;
    if (xdif < 22 && ydif < 22) {
        if (mb_left)
            this->spriteIndex = 33;
        else
            this->spriteIndex = 32;
        if (left_released)
            return true;
    } else {
        this->spriteIndex = 31;
    }
    return false;
}

int ButtonHome::getSpriteIndex()
{
    return this->spriteIndex;
}

int ButtonHome::getx()
{
    return this->x;
}

int ButtonHome::gety()
{
    return this->y;
}