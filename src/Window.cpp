/*
** EPITECH PROJECT, 2022
** jam2
** File description:
** Window
*/

#include "Window.hpp"

Window::Window()
{
    this->initWindow();
    this->music = true;
    this->pause = true;
    this->menu = true;
    this->help = true;

    this->buttonStart = new ButtonStart(512, 280);
    this->buttonQuit = new ButtonQuit(512, 340);
    this->buttonMusic = new ButtonMusic(48, 528);
    this->buttonHelp = new ButtonHelp(976, 528);

    // 0-2 START
    this->sprites.push_back(new Sprite("assets/start.png", 65, 24));
    this->sprites.push_back(new Sprite("assets/startBig.png", 65, 24));
    this->sprites.push_back(new Sprite("assets/startSmall.png", 65, 24));
    // 3-5 QUIT
    this->sprites.push_back(new Sprite("assets/quit.png", 65, 24));
    this->sprites.push_back(new Sprite("assets/quitBig.png", 65, 24));
    this->sprites.push_back(new Sprite("assets/quitSmall.png", 65, 24));
    // 6-8 SOUND ON
    this->sprites.push_back(new Sprite("assets/musicOn.png", 24, 24));
    this->sprites.push_back(new Sprite("assets/musicOnBig.png", 24, 24));
    this->sprites.push_back(new Sprite("assets/musicOnSmall.png", 24, 24));
    // 9-11 SOUND OFF
    this->sprites.push_back(new Sprite("assets/musicOff.png", 24, 24));
    this->sprites.push_back(new Sprite("assets/musicOffBig.png", 24, 24));
    this->sprites.push_back(new Sprite("assets/musicOffSmall.png", 24, 24));
    // 12-14 HELP ON
    this->sprites.push_back(new Sprite("assets/helpOn.png", 24, 24));
    this->sprites.push_back(new Sprite("assets/helpOnBig.png", 24, 24));
    this->sprites.push_back(new Sprite("assets/helpOnSmall.png", 24, 24));
    // 15-17 HELP OFF
    this->sprites.push_back(new Sprite("assets/helpOff.png", 24, 24));
    this->sprites.push_back(new Sprite("assets/helpOffBig.png", 24, 24));
    this->sprites.push_back(new Sprite("assets/helpOffSmall.png", 24, 24));
    // 18-20 PAUSE ON
    this->sprites.push_back(new Sprite("assets/pauseOn.png", 24, 24));
    this->sprites.push_back(new Sprite("assets/pauseOnBig.png", 24, 24));
    this->sprites.push_back(new Sprite("assets/pauseOnSmall.png", 24, 24));
    // 21-23 PAUSE OFF
    this->sprites.push_back(new Sprite("assets/pauseOff.png", 24, 24));
    this->sprites.push_back(new Sprite("assets/pauseOffBig.png", 24, 24));
    this->sprites.push_back(new Sprite("assets/pauseOffSmall.png", 24, 24));
    // 24 TITLE
    this->sprites.push_back(new Sprite("assets/title.png", 75, 54));
    // 25 RULES
    this->sprites.push_back(new Sprite("assets/rules.png", 570, 34));
    // 26 CELL
    this->sprites.push_back(new Sprite("assets/cell.png", 16, 16));
}

Window::~Window()
{
    if (this->_window.isOpen())
        this->_window.close();
    for (size_t i = 0; i < this->sprites.size(); i++)
        delete this->sprites[i];
    delete this->buttonStart;
}

void Window::initWindow()
{
    this->_window.create(sf::VideoMode(1024, 576, 32),  "GameOfLife");
    this->_window.setVerticalSyncEnabled(true);
    this->_window.setFramerateLimit(60);
    this->_window.setKeyRepeatEnabled(true);
}

bool Window::isWindowOpen()
{
    return this->_window.isOpen();
}

void Window::windowClear()
{
    this->_window.clear();
}

void Window::windowDisplay()
{
    this->_window.display();
}

void Window::drawSprite(Sprite &spr, float x, float y)
{
    spr.spr.setPosition(sf::Vector2f(x, y));
    this->_window.draw(spr.spr);
}

void Window::getEvent()
{
    sf::Event _event;

    this->left_released = false;
    while (this->_window.pollEvent(_event)) {
        if (_event.type == _event.Closed)
            this->_window.close();
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        this->mb_left = true;
    } else {
        if (this->mb_left == true)
            this->left_released = true;
        this->mb_left = false;
    }
    sf::Vector2i v = sf::Mouse::getPosition(this->_window);
    this->mouse_x = v.x;
    this->mouse_y = v.y;
}

void Window::loopMenu()
{
    this->getEvent();

    this->drawSprite(*this->sprites[24], 512, 100);

    this->menu = this->buttonStart->onStep(this->mouse_x, this->mouse_y, this->mb_left, this->left_released);
    if (this->buttonQuit->onStep(this->mouse_x, this->mouse_y, this->mb_left, this->left_released)) {
        this->_window.close();
        this->help = false;
    }
    this->music = this->buttonMusic->onStep(this->mouse_x, this->mouse_y, this->mb_left, this->left_released);
    this->help = this->buttonHelp->onStep(this->mouse_x, this->mouse_y, this->mb_left, this->left_released);
    
    this->drawSprite(*this->sprites[this->buttonStart->getSpriteIndex()], this->buttonStart->getx(), this->buttonStart->gety());
    this->drawSprite(*this->sprites[this->buttonQuit->getSpriteIndex()], this->buttonQuit->getx(), this->buttonQuit->gety());
    this->drawSprite(*this->sprites[this->buttonMusic->getSpriteIndex()], this->buttonMusic->getx(), this->buttonMusic->gety());
    this->drawSprite(*this->sprites[this->buttonHelp->getSpriteIndex()], this->buttonHelp->getx(), this->buttonHelp->gety());
    if (this->help)
        this->drawSprite(*this->sprites[25], this->buttonHelp->getx(), this->buttonHelp->gety());
}

void Window::loopGame()
{
    this->getEvent();

    this->music = this->buttonMusic->onStep(this->mouse_x, this->mouse_y, this->mb_left, this->left_released);
    this->help = this->buttonHelp->onStep(this->mouse_x, this->mouse_y, this->mb_left, this->left_released);

    this->drawSprite(*this->sprites[this->buttonMusic->getSpriteIndex()], this->buttonMusic->getx(), this->buttonMusic->gety());
    this->drawSprite(*this->sprites[this->buttonHelp->getSpriteIndex()], this->buttonHelp->getx(), this->buttonHelp->gety());
    if (this->help)
        this->drawSprite(*this->sprites[25], this->buttonHelp->getx(), this->buttonHelp->gety());
}

void Window::loop()
{
    sf::Event _event;

    while (this->isWindowOpen()) {
        this->windowClear();
        if (this->menu)
            this->loopMenu();
        else
            this->loopGame();
        this->windowDisplay();
    }
}