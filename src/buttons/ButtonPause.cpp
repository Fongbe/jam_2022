/*
** EPITECH PROJECT, 2022
** jam_2022
** File description:
** ButtonPause
*/

#include "ButtonPause.hpp"

ButtonPause::ButtonPause(int x, int y)
{
    this->spriteIndex = 0;
    this->x = x;
    this->y = y;
    this->on = true;
}

ButtonPause::~ButtonPause()
{    
}

bool ButtonPause::onStep(int mouse_x, int mouse_y, bool mb_left, bool left_released)
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
                this->spriteIndex = 20;
            else
                this->spriteIndex = 19;
            if (left_released)
                this->on = false;
        } else {
            this->spriteIndex = 18;
        }
    } else  {
        if (xdif < 22 && ydif < 22) {
            if (mb_left)
                this->spriteIndex = 23;
            else
                this->spriteIndex = 22;
            if (left_released)
                this->on = true;
        } else {
            this->spriteIndex = 21;
        }
    }
    return this->on;
}

void ButtonPause::reset()
{
    this->on = true;
}

int ButtonPause::getSpriteIndex()
{
    return this->spriteIndex;
}

int ButtonPause::getx()
{
    return this->x;
}

int ButtonPause::gety()
{
    return this->y;
}