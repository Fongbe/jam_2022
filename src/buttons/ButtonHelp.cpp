/*
** EPITECH PROJECT, 2022
** jam_2022
** File description:
** ButtonHelp
*/

#include "ButtonHelp.hpp"

ButtonHelp::ButtonHelp(int x, int y)
{
    this->spriteIndex = 0;
    this->x = x;
    this->y = y;
    this->on = false;
}

ButtonHelp::~ButtonHelp()
{    
}

void ButtonHelp::reset()
{
    this->on = false;
}

bool ButtonHelp::onStep(int mouse_x, int mouse_y, bool mb_left, bool left_released)
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
                this->spriteIndex = 14;
            else
                this->spriteIndex = 13;
            if (left_released)
                this->on = false;
        } else {
            this->spriteIndex = 12;
        }
    } else  {
        if (xdif < 22 && ydif < 22) {
            if (mb_left)
                this->spriteIndex = 17;
            else
                this->spriteIndex = 16;
            if (left_released)
                this->on = true;
        } else {
            this->spriteIndex = 15;
        }
    }
    return this->on;
}

int ButtonHelp::getSpriteIndex()
{
    return this->spriteIndex;
}

int ButtonHelp::getx()
{
    return this->x;
}

int ButtonHelp::gety()
{
    return this->y;
}