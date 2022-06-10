#include "cookie_clicker.hpp"

cookie_clicker::cookie_clicker()
{
    this->init_timer();
    this->init_score();
}

cookie_clicker::~cookie_clicker()
{
}

void cookie_clicker::init_timer()
{
    this->timer = 0;
}

void cookie_clicker::init_score()
{
    this->score = 0;
}

float cookie_clicker::get_timer_value()
{
    return this->timer;
}

int cookie_clicker::get_score_value()
{
    return this->score;
}

void cookie_clicker::set_timer(float timer)
{
    this->timer = timer;
}

void cookie_clicker::set_score(int score)
{
    this->score = score;
}

int cookie_clicker::create_background(std::string filename)
{
    sf::Texture texture;
    if (!texture.loadFromFile(filename))
        return EXIT_FAILURE;
    this->bgtexture = texture;
    this->bgsprite = sf::Sprite(this->bgtexture);
    this->bgsprite.setPosition(250, 150);
    return EXIT_SUCCESS;
}

int cookie_clicker::create_font(std::string filename)
{
    sf::Font font;
    if (!font.loadFromFile(filename))
        return EXIT_FAILURE;
    this->font = font;
    return EXIT_SUCCESS;
}

int cookie_clicker::create_score()
{
    score_text.setFont(font);
    score_text.setString("Score: 0");
    score_text.setColor(sf::Color::Blue);
    score_text.setCharacterSize(30);
    score_text.setPosition(10, 10);
    return EXIT_SUCCESS;
}

int cookie_clicker::update_score(std::string score)
{
    score_text.setString("Score: " + score);
    return EXIT_SUCCESS;
}

sf::Text *cookie_clicker::get_score()
{
    sf::Text *score_text = &this->score_text;
    return score_text;
}

int cookie_clicker::create_timer()
{
    timer_text.setFont(font);
    timer_text.setString("Time: 0");
    timer_text.setCharacterSize(30);
    timer_text.setPosition(10, 50);
    return EXIT_SUCCESS;
}
        
int cookie_clicker::update_timer(std::string timer)
{
    timer_text.setString("Time: " + timer);
    return EXIT_SUCCESS;
}

sf::Text *cookie_clicker::get_timer()
{
    sf::Text *timer_text = &this->timer_text;
    return timer_text;
}

sf::Sprite cookie_clicker::get_bgsprite()
{
    return bgsprite;
}

// void cookie_clicker::create_window(void)
// {
//     sf::VideoMode mode(800, 600, 32);
//     window.create(mode, "Cookie Clicker", sf::Style::Close);
// }

// sf::RenderWindow cookie_clicker::get_window()
// {
//     sf::RenderWindow window = this->window;
//     return window;
// }

// void cookie_clicker::print_bomb1()
// {
//     this->bomb = std::make_shared<Bomb>(this->sprite);
// }