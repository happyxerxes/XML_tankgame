﻿
#include <SFML/Graphics.hpp>
#include "Game.h"





int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "TANK");
    Game *game = new Game();
    game->delete_game();
    
    while (window.isOpen()) {
        
        game->start_game(window);
        
        for (int i = 0; i < 3; i++) {
            game->next_game(window,i);
            bool pass = game->play_game(window,i);
            if (!pass) {
                break;
            }
        }
        
        
        game->delete_game();
        
        
        
        
    }
    
    delete game;
    return 0;
}



