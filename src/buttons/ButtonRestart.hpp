/*
** EPITECH PROJECT, 2022
** jam_2022
** File description:
** ButtonRestart
*/

#ifndef BUTTONRESTART_HPP_
#define BUTTONRESTART_HPP_

class ButtonRestart {
    public:
        ButtonRestart(int _x, int _y);
        ~ButtonRestart();
        int getx();
        int gety();
        int getSpriteIndex();
        bool onStep(int mouse_x, int mouse_y, bool mb_left, bool left_released);

    private:
        int x;
        int y;
        int spriteIndex;
};

#endif /* !BUTTONRESTART_HPP_ */