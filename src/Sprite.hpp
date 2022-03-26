/*
** EPITECH PROJECT, 2022
** jam2
** File description:
** Sprite
*/

#ifndef SPRITE_HPP_
#define SPRITE_HPP_

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>

class Sprite
{
    public:
        Sprite(const std::string &path, float rotation, float origin);
        ~Sprite() = default;

        sf::Sprite spr;
        sf::Texture txt;
        std::string _path;
};

#endif /* !SPRITE_HPP_ */