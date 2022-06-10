#ifndef cookie_clicker_H
    #define cookie_clicker_H

    #include <SFML/Audio.hpp>
    #include <SFML/Graphics.hpp>
    #include <iostream>
    #include <memory>
    #include <string>

    #define CHECK_COOKIE_CLICKED sf::Mouse::getPosition(window).x >= game.get_bgsprite().getPosition().x && sf::Mouse::getPosition(window).x <= game.get_bgsprite().getPosition().x + game.get_bgsprite().getTextureRect().width && sf::Mouse::getPosition(window).y >= game.get_bgsprite().getPosition().y && sf::Mouse::getPosition(window).y <= game.get_bgsprite().getPosition().y + game.get_bgsprite().getTextureRect().height

// struct Bomb
// {
//     Bomb()
//     {
//         std::cout << "  Bomb::Bomb()\n";
//     }
//     // Note: non-virtual destructor is OK here
//     ~Bomb()
//     {
//         std::cout << "  Bomb::~Bomb()\n";
//     }
// };

class cookie_clicker
{
    private:
        float timer;
        int score;
        sf::Sprite bgsprite;
        sf::Texture bgtexture;
        sf::RenderWindow window;
        sf::Text score_text;
        sf::Text timer_text;
        sf::Font font;
        // std::unique_ptr<Bomb> bomb;
        // std::shared_ptr<sf::Texture> bomb_texture;
    public:
        cookie_clicker();
        void init_timer();
        float get_timer_value();
        void set_timer(float);
        void init_score();
        int get_score_value();
        void set_score(int);
        int create_background(std::string);
        int create_font(std::string);
        int create_score();
        sf::Text *get_score();
        int update_score(std::string);
        int create_timer();
        int update_timer(std::string);
        sf::Text *get_timer();
        sf::Sprite get_bgsprite();
        void create_window();
        sf::RenderWindow get_window();
        // void print_bomb1();
        ~cookie_clicker();
};

#endif
