#include <iostream>

#include "cookie_clicker.hpp"

int init_cookie_clicker()
{
    cookie_clicker game;
    // game.create_window();
    sf::RenderWindow window;
    bool event_passed;
    window.create(sf::VideoMode(1000, 800, 32), "Cookie Clicker", sf::Style::Close);
    std::cout << "  init_cookie_clicker()" << std::endl;
    // game.print_bomb1();
    if (game.create_background("Sprites/Cookie.png"))
        std::cout << "  init_cookie_clicker() - create_background() failed" << std::endl;
    else
        std::cout << "  init_cookie_clicker() - create_background() succeeded" << std::endl;
    game.init_score();
    game.init_timer();
    game.create_font("Sprites/ARIBL0.ttf");
    game.create_score();
    game.create_timer();
    sf::Clock clock;
    while(game.get_score_value() < 21 && window.isOpen()) {
        game.update_score(std::to_string(game.get_score_value()));
        window.clear(sf::Color::Black);
        window.draw(game.get_bgsprite());
        // window.draw(*game.get_timer());
        window.draw(*game.get_score());
        window.display();
        sf::Time elapsed = clock.restart();
        game.set_timer(game.get_timer_value() + elapsed.asSeconds());
        std::cout << "  cookie_clicker() - elapsed: " << elapsed.asSeconds() << "s" << std::endl;
        std::cout << "  cookie_clicker() - timer: " << game.get_timer_value() << "s" << std::endl;
        std::cout << "  cookie_clicker() - score: " << game.get_score_value() << std::endl;
        std::cout << "  cookie_clicker() - click on cookie to continue" << std::endl << std::endl;
        sf::Event event;
        event_passed = false;
        while (event_passed == false && window.waitEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape) {
                        window.close();
                    }
                    break;
                case sf::Event::MouseButtonReleased:
                    if (CHECK_COOKIE_CLICKED) {
                        game.set_score(game.get_score_value() + 1);
                        event_passed = true;
                    }
                    break;
                default:
                    continue;
            }
        }
    }
    return (0);
}

int main(void)
{
    return (init_cookie_clicker());
}
