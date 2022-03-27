/*
** EPITECH PROJECT, 2022
** jam_2022
** File description:
** ButtonStart
*/

#ifndef BUTTONSTART_HPP_
#define BUTTONSTART_HPP_

class ButtonStart {
    public:
        ButtonStart(int _x, int _y);
        ~ButtonStart();
        int getx();
        int gety();
        int getSpriteIndex();
        bool onStep(int mouse_x, int mouse_y, bool mb_left, bool left_released);

    private:
        int x;
        int y;
        int spriteIndex;
};

#endif /* !BUTTONSTART_HPP_ */
