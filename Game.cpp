#include "Game.h"

void Game::is_exit(sf::Event &event, sf::RenderWindow &window)
{
	//≈–∂œ «∑Òµ„°¡
	bool close = (event.type == sf::Event::Closed);
	//≈–∂œ «∑Ò∞¥ESC
	bool escape = (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape);
	if (close || escape)
		window.close();
}
void Game::Draw_Tank(Tank &tank, sf::Time elapsed, sf::RenderWindow &window)
{
	tank.update(elapsed, window);
	window.draw(tank);
	window.draw(tank.gun);
}

Game::Game() {
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "TANK");
	sf::Clock clock;
	sf::Clock clock1;
	tanks[0] = new Tank();
	Tank enemy_tank;
	enemy_tank.setPosition(150, 150);
	enemy_tank.gun.setPosition(350, 450);
    
    
    sf::Event event;
    
    
    
    
    sf::Texture startgame_texture;
    if (!startgame_texture.loadFromFile("/Users/XHZ/Library/Developer/Xcode/DerivedData/XML_Tank-endjjnmbmexpiehiwzrtpzwayevi/Build/Products/Release/XML_Tank.app/Contents/Resources/gamestart.jpg")) {
        return;
    }
    sf::Sprite startgame_sprite(startgame_texture);
    
    
    
    window.draw(startgame_sprite);
    window.display();
    
    bool flag = true;
    
    while (window.isOpen() && flag){
        while (window.pollEvent(event))
        {
            is_exit(event, window);
            
            
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    flag = false;
                    break;
                }
            }
        }
        
    }

    
    

	Shield shield_a(SHIELD_A);
	/*SYSTEMTIME sys;
	GetLocalTime(&sys);
	int fire_time = sys.wSecond;*/
	sf::Time fire_time = clock1.restart();
//	sf::Event event;
	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{
			is_exit(event, window);

			tanks[0]->move_tank(event);

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					for (int i = 0; i < 10; i++) {
						if (bullets[i] == NULL) {
							bullets[i] = new Bullet(tanks[0]->fire(window));
							break;
						}
					}

				}
			}
		}
		sf::Time fire_gap = clock1.getElapsedTime();
		sf::Vector2f vector = tanks[0]->getPosition() - enemy_tank.getPosition();
		float distance = (sqrt(vector.x*vector.x + vector.y*vector.y));
		if (distance<150)
		{
			float angle =enemy_tank.enemy_fire_angle(vector);
			enemy_tank.gun.setRotation(angle);
			if (fire_gap.asSeconds() > 1)
			{
				for (int i = 0; i < 10; i++) {
					if (bullets[i] == NULL) {
						bullets[i] = new Bullet(enemy_tank.enemy_fire2tank(*tanks[0]));
						break;
					}
				}
				fire_time = clock1.restart();
			}	
		}
		enemy_tank.enemy_move();
		
		window.clear(sf::Color(225, 225, 225));

		window.draw(shield_a);
		/*if (enemy_tank.is_exist == true)
		{
			window.draw(enemy_tank);
			window.draw(enemy_tank.gun);
		}*/
		window.draw(enemy_tank);
		window.draw(enemy_tank.gun);
		sf::Time elapsed = clock.restart();
		Draw_Tank(*tanks[0], elapsed, window);
		tanks[0]->tank_collison(enemy_tank);//坦克碰撞
		enemy_tank.enemy_update(elapsed, window);
		//check_collsion
		for (int i = 0; i<10; i++) {
			if (bullets[i] != NULL) {
				shield_a.A_check_collsion_with_bullet(*bullets[i]);
				tanks[0]->bullet_collision(*bullets[i]);
				enemy_tank.bullet_collision(*bullets[i]);

				for (int j = i + 1; j<10; j++) {
					if (bullets[j] != NULL) {
						bullets[i]->bullet_collision_check(bullets[j]);
					}

				}

			}
		}


		shield_a.A_check_collsion_with_tank(*tanks[0]);
		shield_a.A_check_collsion_with_tank(enemy_tank);
		//check_exit

		for (int i = 0; i<10; i++) {
			if (bullets[i] != NULL && bullets[i]->is_exist == false) {
				delete bullets[i];
				bullets[i] = NULL;
			}
		}

		for (int i = 0; i<10; i++) {
			if (bullets[i] && bullets[i]->is_exist == true)
			{
				bullets[i]->update(elapsed);
				window.draw(*bullets[i]);

			}
		}


		window.display();
	}

}

