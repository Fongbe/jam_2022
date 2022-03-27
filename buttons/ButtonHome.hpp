/*
** EPITECH PROJECT, 2022
** jam_2022
** File description:
** ButtonHome
*/

#ifndef BUTTONHOME_HPP_
#define BUTTONHOME_HPP_

class ButtonHome {
    public:
        ButtonHome(int _x, int _y);
        ~ButtonHome();
        int getx();
        int gety();
        int getSpriteIndex();
        bool onStep(int mouse_x, int mouse_y, bool mb_left, bool left_released);

    private:
        int x;
        int y;
        int spriteIndex;
};

#endif /* !BUTTONHOME_HPP_ */