/*
** EPITECH PROJECT, 2022
** jam_2022
** File description:
** ButtonPause
*/

#ifndef BUTTONPAUSE_HPP_
#define BUTTONPAUSE_HPP_

class ButtonPause {
    public:
        ButtonPause(int _x, int _y);
        ~ButtonPause();
        int getx();
        int gety();
        int getSpriteIndex();
        bool onStep(int mouse_x, int mouse_y, bool mb_left, bool left_released);
        void reset();

    private:
        int on;
        int x;
        int y;
        int spriteIndex;
};

#endif /* !BUTTONPAUSE_HPP_ */
