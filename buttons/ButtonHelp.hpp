/*
** EPITECH PROJECT, 2022
** jam_2022
** File description:
** ButtonHelp
*/

#ifndef BUTTONHELP_HPP_
#define BUTTONHELP_HPP_

class ButtonHelp {
    public:
        ButtonHelp(int _x, int _y);
        ~ButtonHelp();
        int getx();
        int gety();
        int getSpriteIndex();
        bool onStep(int mouse_x, int mouse_y, bool mb_left, bool left_released);
        void reset();

    private:
        int x;
        int y;
        int spriteIndex;
        bool on;
};

#endif /* !BUTTONHELP_HPP_ */
