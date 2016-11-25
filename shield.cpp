
#include "shield.h"


Shield::Shield(unsigned int category) {
	switch (category) {
	case SHIELD_A:
		//            ConvexShape(6);
		setshape_A();
		break;
	case SHIELD_B:
		//            ConvexShape(8);
		setshape_B();
		break;
		/*
		case SHIELD_Cup:
		setshape_Cup();
		break;
		case SHIELD_Cdown:
		setshape_Cdown();
		break;
		case SHIELD_Cleft:
		setshape_Cleft();
		break;
		case SHIELD_Cright:
		setshape_Cright();
		break;
		*/

	default:
		break;
	}
}

void Shield::A_check_collsion_with_bullet(Bullet &bullet) {
	sf::Vector2f centre_A, bullet_position;
	centre_A.x = a_position_x + 20;
	centre_A.y = a_position_y + 20;

	bullet_position = bullet.getPosition();

	float x = bullet_position.x - centre_A.x;
	float y = bullet_position.y - centre_A.y;

	if (x<35 && x>-35 && y<35 && y>-35) {
		if ((y>x && y>-x) || (y<x && y<-x)) {
			bullet.reverse_dy();
		}
		else { bullet.reverse_dx(); }
	}
}
void Shield::A_check_collsion_with_tank(Tank &tank) {
	sf::Vector2f centre_A, bullet_position, tank_position;
	centre_A.x = a_position_x + 25;
	centre_A.y = a_position_y + 25;

	tank_position = tank.getPosition();

	float x = tank_position.x - centre_A.x;
	float y = tank_position.y - centre_A.y;

	if (sqrt(x*x + y*y)<(50 * 1.414)) {

		sf::Vector2f left_up_point, right_down_point, right_up_point, left_down_point;
		float l = sqrt(TANK_WIDTH*TANK_WIDTH + TANK_HEIGHT*TANK_HEIGHT)*0.5;
		sf::Vector2f p = tank.getPosition();
		// 左上
		float angle = 3.1416*0.25 - tank.getRotation() TO_RADIAN;

		left_up_point.x = p.x - l*sin(angle);
		left_up_point.y = p.y - l*cos(angle);

		//右下

		right_down_point.x = p.x + l*sin(angle);
		right_down_point.y = p.y + l*cos(angle);
		//右上
		angle = 3.1415926535*0.25 + tank.getRotation() TO_RADIAN;
		right_up_point.x = p.x + l*sin(angle);
		right_up_point.y = p.y - l*cos(angle);



		//左下
		left_down_point.x = p.x - l*sin(angle);
		left_down_point.y = p.y + l*cos(angle);


		//前面取10个点
		float k = (right_up_point.y - left_up_point.y) / (right_up_point.x - left_up_point.x);
		float dx = (right_up_point.x - left_up_point.x) / 9;
		//        float x,y;


		for (int i = 0; i<10; i++) {
			x = left_up_point.x + dx*i;
			y = k*(x - left_up_point.x) + left_up_point.y;

			x = x - centre_A.x;
			y = y - centre_A.y;

			if (x<27 && x>-27 && y<27 && y>-27) {
				tank.setPosition(tank.previous_position.x, tank.previous_position.y);
				tank.setRotation(tank.previous_rotation);
				break;
			}

		}



		//后面取10个点
		k = (right_down_point.y - left_down_point.y) / (right_down_point.x - left_down_point.x);
		dx = (right_down_point.x - left_down_point.x) / 9;
		//        float x,y;


		for (int i = 0; i<10; i++) {
			x = left_down_point.x + dx*i;
			y = k*(x - left_down_point.x) + left_down_point.y;

			x = x - centre_A.x;
			y = y - centre_A.y;

			if (x<27 && x>-27 && y<27 && y>-27) {
				tank.setPosition(tank.previous_position.x, tank.previous_position.y);
				tank.setRotation(tank.previous_rotation);
				break;
			}

		}





	}

}

void Shield::setshape_A() {
	//*

	// set_block_counts(get_block_counts()+3);

	this->setPointCount(4);
	this->setPoint(0, sf::Vector2f(0, 0));
	this->setPoint(1, sf::Vector2f(0, 50));
	this->setPoint(2, sf::Vector2f(50, 50));
	this->setPoint(3, sf::Vector2f(50, 0));



	this->setOutlineThickness(5);
	this->setOutlineColor(sf::Color::Red);
	//   this->setFillColor(sf::Color::Red);
	this->setPosition(a_position_x, a_position_y);

}

void Shield::setshape_B() {

	//*
	//**
	//*


	//  set_block_counts(get_block_counts()+4);
	/*

	add_centre(sf::Vector2f(200+25,200+25));
	add_centre(sf::Vector2f(200+25,200+75));
	add_centre(sf::Vector2f(200+25,200+125));
	add_centre(sf::Vector2f(200+75,200+75));
	*/

	this->setPointCount(8);
	this->setPoint(0, sf::Vector2f(0, 0));
	this->setPoint(1, sf::Vector2f(0, 150));
	this->setPoint(2, sf::Vector2f(50, 150));
	this->setPoint(3, sf::Vector2f(50, 100));
	this->setPoint(4, sf::Vector2f(100, 100));
	this->setPoint(5, sf::Vector2f(100, 50));
	this->setPoint(6, sf::Vector2f(50, 50));
	this->setPoint(7, sf::Vector2f(50, 0));


	this->setFillColor(sf::Color::Red);
	//   this->setOutlineThickness(3);
	this->setPosition(600, 400);
}
/*
void Shield::setshape_Cup(){


this->setPointCount(3);
this->setPoint(0, sf::Vector2f(0, 0));
this->setPoint(1, sf::Vector2f(-50, -50));
this->setPoint(2, sf::Vector2f(50, -50));


this->setFillColor(sf::Color(ObjectGroup::red_up));
this->setPosition(400, 300);

}
void Shield::setshape_Cdown(){

this->setPointCount(3);
this->setPoint(0, sf::Vector2f(0, 0));
this->setPoint(1, sf::Vector2f(-50, 50));
this->setPoint(2, sf::Vector2f(50, 50));


this->setFillColor(sf::Color(ObjectGroup::red_down));
this->setPosition(400, 300);
}
void Shield::setshape_Cleft(){

this->setPointCount(3);
this->setPoint(0, sf::Vector2f(0, 0));
this->setPoint(1, sf::Vector2f(-50, -50));
this->setPoint(2, sf::Vector2f(-50, 50));


this->setFillColor(sf::Color(ObjectGroup::red_left));
this->setPosition(400, 300);
}
void Shield::setshape_Cright(){

this->setPointCount(3);
this->setPoint(0, sf::Vector2f(0, 0));
this->setPoint(1, sf::Vector2f(50, -50));
this->setPoint(2, sf::Vector2f(50, 50));


this->setFillColor(sf::Color(ObjectGroup::red_right));
this->setPosition(400, 300);
}
*/
