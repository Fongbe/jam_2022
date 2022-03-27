/*
** EPITECH PROJECT, 2022
** jam_2022
** File description:
** ButtonQuit
*/

#ifndef BUTTONQUIT_HPP_
#define BUTTONQUIT_HPP_

class ButtonQuit {
    public:
        ButtonQuit(int _x, int _y);
        ~ButtonQuit();
        int getx();
        int gety();
        int getSpriteIndex();
        bool onStep(int mouse_x, int mouse_y, bool mb_left, bool left_released);

    private:
        int x;
        int y;
        int spriteIndex;
};

#endif /* !BUTTONQUIT_HPP_ */