// demo.cpp : ∂®“Âøÿ÷∆Ã®”¶”√≥Ã–Úµƒ»Îø⁄µ„°£
//

//#include "stdafx.h"
//#include<SFML/Graphics.hpp>


#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
	Game game;
	return 0;
}
//#include "Graphics.h"

/*
#include "tank.h"
#include "bullet.h"
#include "shield.hpp"


#define WIDTH 800
#define HEIGHT 600

using namespace std;
using namespace sf;

void is_exit(sf::Event &event, sf::RenderWindow &window)
{
//≈–∂œ «∑Òµ„°¡
bool close = (event.type == sf::Event::Closed);
//≈–∂œ «∑Ò∞¥ESC
bool escape = (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape);
if (close || escape)
window.close();
}
void Draw_Tank(Tank &tank, sf::Time elapsed, sf::RenderWindow &window)
{
tank.update(elapsed, window);
window.draw(tank);
window.draw(tank.gun);
}

int main()
{
sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "TANK");
sf::Clock clock;
Tank tank;
Shield shield_a(SHIELD_A);
Bullet *bullet = NULL;
sf::Event event;
while (window.isOpen())
{

while (window.pollEvent(event))
{
is_exit(event, window);

tank.move_tank(event);

if (event.type == sf::Event::MouseButtonPressed)
{
if (event.mouseButton.button == sf::Mouse::Left)
{
bullet = new Bullet(tank.fire(window));
}
}

}

sf::Time elapsed = clock.restart();
window.clear(sf::Color(255, 255, 255));

window.draw(shield_a);

Draw_Tank(tank, elapsed, window);

if (bullet) {
shield_a.A_check_collsion_with_bullet(*bullet);
}
shield_a.A_check_collsion_with_tank(tank);


if (bullet&&bullet->is_exist == true)
{
bullet->update();
window.draw(*bullet);

}
window.display();
}

}

*/


/*
int _tmain(int argc, _TCHAR* argv[])
{
RenderWindow window(VideoMode(200, 200), "SFML works!");
CircleShape shape(100.f);
shape.setFillColor(Color::Green);

while (window.isOpen())
{
Event event;
while (window.pollEvent(event))
{
if (event.type == Event::Closed)
window.close();
}

window.clear();
window.draw(shape);
window.display();
}
return 0;
}
*/

