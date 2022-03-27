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

    if (!font.loadFromFile("assets/COMIC.TTF"))
        std::cerr << "Failed to load the font" << std::endl;
    
    this->text.setFont(font);
    this->text.setString("");
    this->text.setCharacterSize(14);
    this->text.setFillColor(sf::Color::White);

    this->buttonStart = new ButtonStart(512, 280);
    this->buttonQuit = new ButtonQuit(512, 340);
    this->buttonMusic = new ButtonMusic(48, 528);
    this->buttonHelp = new ButtonHelp(976, 528);
    this->buttonPause = new ButtonPause(932, 350);
    this->buttonRestart = new ButtonRestart(982, 350);
    this->buttonHome = new ButtonHome(957, 400);

    std::vector<std::vector<bool>> newTab;
    for (size_t x = 0; x < 26; x++) {
        std::vector<bool> newLine;
        newTab.push_back(newLine);
        for (size_t y = 0; y < 14; y++) {
            newTab[x].push_back(false);
        }
    }
    this->tab = newTab;


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
    this->sprites.push_back(new Sprite("assets/title.png", 106, 40));
    // 25 RULES
    this->sprites.push_back(new Sprite("assets/rules.png", 570, 34));
    // 26 CELL
    this->sprites.push_back(new Sprite("assets/cell.png", 0, 0));
    // 27 DEAD CELL
    this->sprites.push_back(new Sprite("assets/deadCell.png", 0, 0));
    // 28-30 RESTART
    this->sprites.push_back(new Sprite("assets/restart.png", 24, 24));
    this->sprites.push_back(new Sprite("assets/restartBig.png", 24, 24));
    this->sprites.push_back(new Sprite("assets/restartSmall.png", 24, 24));
    // 31-33 HOME
    this->sprites.push_back(new Sprite("assets/home.png", 24, 24));
    this->sprites.push_back(new Sprite("assets/homeBig.png", 24, 24));
    this->sprites.push_back(new Sprite("assets/homeSmall.png", 24, 24));
    // 34 SELECT
    this->sprites.push_back(new Sprite("assets/select.png", 0, 0));
    // 25 BACKGROUND
    this->sprites.push_back(new Sprite("assets/back.png", 0, 0));
}

Window::~Window()
{
    if (this->_window.isOpen())
        this->_window.close();
    for (size_t i = 0; i < this->sprites.size(); i++)
        delete this->sprites[i];
    delete this->buttonStart;
    delete this->buttonQuit;
    delete this->buttonHelp;
    delete this->buttonMusic;
    delete this->buttonPause;
    delete this->buttonRestart;
    delete this->buttonHome;
}

void Window::drawText(float x, float y, std::string str, int size)
{
    this->text.setCharacterSize(size);
    this->text.setString(str);
    this->text.setPosition(x, y);
    this->_window.draw(this->text);
}

int getCell(int x, int y, std::vector<std::vector<bool>> tab)
{
    if (x < 0 || y < 0 || x >= tab.size() || y >= tab[0].size())
        return 0;
    if (tab[x][y] == false)
        return 0;
    else
        return 1;
}

int getNbCell(int x, int y, std::vector<std::vector<bool>> tab)
{
    int nb = 0;

    nb += getCell(x-1, y+1, tab);
    nb += getCell(x, y+1, tab);
    nb += getCell(x+1, y+1, tab);
    nb += getCell(x-1, y-1, tab);
    nb += getCell(x, y-1, tab);
    nb += getCell(x+1, y-1, tab);
    nb += getCell(x-1, y, tab);
    nb += getCell(x+1, y, tab);
    return nb;
}

void Window::nextGen()
{
    int nb = 0;
    bool end = true;

    this->generation += 1;
    std::vector<std::vector<bool>> next;
    for (size_t x = 0; x < 26; x++) {
        std::vector<bool> newLine;
        next.push_back(newLine);
        for (size_t y = 0; y < 14; y++) {
            next[x].push_back(false);
        }
    }
    for (size_t x = 0; x < next.size(); x++) {
        for (size_t y = 0; y < next[x].size(); y++) {
            nb = getNbCell(x, y, this->tab);
            if (this->tab[x][y] == false) {
                if (nb == 3)
                    next[x][y] = true;
                else
                    next[x][y] = false;
            } else {
                end = false;
                if (nb == 3 || nb == 2)
                    next[x][y] = true;
                else
                    next[x][y] = false;
            }
        }
    }
    this->tab = next;
    if (end) {
        this->buttonPause->reset();
        this->pause = true;
    }
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
    this->left_pressed = false;
    while (this->_window.pollEvent(_event)) {
        if (_event.type == _event.Closed)
            this->_window.close();
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if (this->mb_left == false)
            this->left_pressed = true;
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
    if (this->buttonQuit->onStep(this->mouse_x, this->mouse_y, this->mb_left, this->left_released))
        this->_window.close();
    this->music = this->buttonMusic->onStep(this->mouse_x, this->mouse_y, this->mb_left, this->left_released);
    this->help = this->buttonHelp->onStep(this->mouse_x, this->mouse_y, this->mb_left, this->left_released);
    
    this->drawSprite(*this->sprites[this->buttonStart->getSpriteIndex()], this->buttonStart->getx(), this->buttonStart->gety());
    this->drawSprite(*this->sprites[this->buttonQuit->getSpriteIndex()], this->buttonQuit->getx(), this->buttonQuit->gety());
    this->drawSprite(*this->sprites[this->buttonMusic->getSpriteIndex()], this->buttonMusic->getx(), this->buttonMusic->gety());
    this->drawSprite(*this->sprites[this->buttonHelp->getSpriteIndex()], this->buttonHelp->getx(), this->buttonHelp->gety());
    if (this->help)
        this->drawSprite(*this->sprites[25], this->buttonHelp->getx(), this->buttonHelp->gety());
    
    if (!this->menu) {
        this->help = false;
        this->pause = true;
        this->buttonPause->reset();
        this->buttonHelp->reset();
    }
}

void Window::onClick(int xpos, int ypos)
{
    if (this->mouse_x >= 64 && xpos < this->tab.size() && this->mouse_y >= 32 && ypos < this->tab[0].size()) {
        if (this->left_pressed) {
            if (this->tab[xpos][ypos] == true)
                this->tab[xpos][ypos] = false;
            else
                this->tab[xpos][ypos] = true;
        }
    }
}

void Window::loopGame()
{
    int xpos;
    int ypos;

    this->getEvent();

    xpos = ((this->mouse_x-64) - ((this->mouse_x-64)%32)) / 32;
    ypos = ((this->mouse_y-32) - ((this->mouse_y-32)%32)) / 32;

    this->music = this->buttonMusic->onStep(this->mouse_x, this->mouse_y, this->mb_left, this->left_released);
    this->help = this->buttonHelp->onStep(this->mouse_x, this->mouse_y, this->mb_left, this->left_released);
    this->pause = this->buttonPause->onStep(this->mouse_x, this->mouse_y, this->mb_left, this->left_released);
    if (this->buttonRestart->onStep(this->mouse_x, this->mouse_y, this->mb_left, this->left_released)) {
        this->buttonPause->reset();
        std::vector<std::vector<bool>> newTab;
        for (size_t x = 0; x < 26; x++) {
            std::vector<bool> newLine;
            newTab.push_back(newLine);
            for (size_t y = 0; y < 14; y++) {
                newTab[x].push_back(false);
            }
        }
        this->tab = newTab;
        this->generation = 0;
        this->pause = true;
    }

    if (this->buttonHome->onStep(this->mouse_x, this->mouse_y, this->mb_left, this->left_released)) {
        this->buttonPause->reset();
        std::vector<std::vector<bool>> newTab;
        for (size_t x = 0; x < 26; x++) {
            std::vector<bool> newLine;
            newTab.push_back(newLine);
            for (size_t y = 0; y < 14; y++) {
                newTab[x].push_back(false);
            }
        }
        this->tab = newTab;
        this->generation = 0;
        this->pause = true;
        this->menu = true;
    }

    this->onClick(xpos, ypos);

    this->drawText(910, 200, "GENERATION :", 14);
    this->drawText(912, 225, std::to_string(this->generation), 18);

    this->drawSprite(*this->sprites[this->buttonHome->getSpriteIndex()], this->buttonHome->getx(), this->buttonHome->gety());
    this->drawSprite(*this->sprites[this->buttonRestart->getSpriteIndex()], this->buttonRestart->getx(), this->buttonRestart->gety());
    this->drawSprite(*this->sprites[this->buttonMusic->getSpriteIndex()], this->buttonMusic->getx(), this->buttonMusic->gety());
    this->drawSprite(*this->sprites[this->buttonHelp->getSpriteIndex()], this->buttonHelp->getx(), this->buttonHelp->gety());
    this->drawSprite(*this->sprites[this->buttonPause->getSpriteIndex()], this->buttonPause->getx(), this->buttonPause->gety());
    if (this->help)
        this->drawSprite(*this->sprites[25], this->buttonHelp->getx(), this->buttonHelp->gety());
    
    for (size_t x = 0; x < this->tab.size(); x++) {
        for (size_t y = 0; y < this->tab[x].size(); y++) {
            this->drawSprite(*this->sprites[27], 64 + x*32, 32 + y*32);
            if (this->tab[x][y] == true)
                this->drawSprite(*this->sprites[26], 64 + x*32, 32 + y*32);
        }
    }
    if (this->mouse_x >= 64 && xpos < this->tab.size() && this->mouse_y >= 32 && ypos < this->tab[0].size())
        this->drawSprite(*this->sprites[34], xpos*32+64, ypos*32+32);
    
    if (!this->pause) {
        if (this->cl.getElapsedTime() >= sf::milliseconds(200)) {
            this->cl.restart();
            this->nextGen();
        }
    }
}

void Window::loop()
{
    sf::Event _event;

    this->cl.restart();
    while (this->isWindowOpen()) {
        this->windowClear();
        this->drawSprite(*this->sprites[35], 0, 0);
        if (this->menu)
            this->loopMenu();
        else
            this->loopGame();
        this->windowDisplay();
    }
}