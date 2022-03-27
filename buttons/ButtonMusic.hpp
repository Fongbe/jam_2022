/*
** EPITECH PROJECT, 2022
** jam_2022
** File description:
** ButtonMusic
*/

#ifndef BUTTONMUSIC_HPP_
#define BUTTONMUSIC_HPP_

class ButtonMusic {
    public:
        ButtonMusic(int _x, int _y);
        ~ButtonMusic();
        int getx();
        int gety();
        int getSpriteIndex();
        bool onStep(int mouse_x, int mouse_y, bool mb_left, bool left_released);

    private:
        int on;
        int x;
        int y;
        int spriteIndex;
};

#endif /* !BUTTONMUSIC_HPP_ */
