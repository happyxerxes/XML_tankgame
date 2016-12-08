// demo.cpp : ∂®“Âøÿ÷∆Ã®”¶”√≥Ã–Úµƒ»Îø⁄µ„°£
//

//#include "stdafx.h"
//#include<SFML/Graphics.hpp>


#include <SFML/Graphics.hpp>
#include "Game.h"





int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "TANK");
    Game *game = new Game();
    game->delete_game();
    
    while (window.isOpen()) {
        game->start_game(window);
        
        
        
        game->play_game(window);
        
        game->delete_game();
        
        printf("1");
        
        
        
    }
    
    delete game;
    return 0;
}



