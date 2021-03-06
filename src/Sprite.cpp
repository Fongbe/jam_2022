/*
** EPITECH PROJECT, 2022
** jam2
** File description:
** Sprite
*/

#include "Sprite.hpp"
#include <iostream>

Sprite::Sprite(const std::string &path, float xorigin, float yorigin)
{
    this->_path = path;
    if (!this->txt.loadFromFile(path))
        std::cerr << "Error loading " << path << std::endl;
    else {
        this->spr.setTexture(this->txt);
        this->spr.setOrigin(sf::Vector2f(xorigin, yorigin));
    }
}