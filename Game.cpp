#include "Game.h"
#include "Collision.h"

Game::Game()
{
	
	enclosures.insert(std::map<std::string, Enclosure*>::value_type("Up", new Enclosure(0, 0, 640, 30, Palette::Aqua)));			//Uppper
	enclosures.insert(std::map<std::string, Enclosure*>::value_type("Bottom", new Enclosure(0, 450, 640, 30, Palette::Aqua)));		//Bottom
	enclosures.insert(std::map<std::string, Enclosure*>::value_type("Left", new Enclosure(0, 0, 30, 480, Palette::Aqua)));			//left
	enclosures.insert(std::map<std::string, Enclosure*>::value_type("Right", new Enclosure(610, 0, 30, 480, Palette::Aqua)));		//right
	enclosures.insert(std::map<std::string, Enclosure*>::value_type("UL", new Enclosure(0, 0, 30, 30, Palette::Aquamarine)));		//Upper-left corner
	enclosures.insert(std::map<std::string, Enclosure*>::value_type("UR", new Enclosure(610, 0, 30, 30, Palette::Aquamarine)));		//Upper-right corner
	enclosures.insert(std::map<std::string, Enclosure*>::value_type("BL", new Enclosure(0, 450, 30, 30, Palette::Aquamarine)));		//Bottom-left corner
	enclosures.insert(std::map<std::string, Enclosure*>::value_type("BR", new Enclosure(610, 450, 30, 30, Palette::Aquamarine)));	//Bottom-right corner
#if 1
	for (int i = 0; i < 2; i++) {
		player[i].initPlayer(i + 1);
	}
#endif
}


Game::~Game()
{
}

SceneBase* Game::update()
{
	Collision c;
	Ellipse vir_pl[2];

	for (int i = 0; i < 2; i++) {
		vir_pl[i] = player[i].Body;
		vir_pl[i].x += player[i].getAccelerationX();
		vir_pl[i].y += player[i].getAccelerationY();

		for (std::map<std::string, Enclosure*>::iterator it = enclosures.begin(); it != enclosures.end(); it++) {
			it->second->update();
			if (c.isCollisionDetection(vir_pl[i], it->second->wall)) {
				player[i].Body.setPos(c.findAdjustmentCoord(it->first, it->second->wall, player[i].getWidthRadius() / 2, player[i].getHeightRadius() / 2));
				player[i].setAcceleration(player[i].getAccelerationX()*-1, player[i].getAccelerationY()*-1);
			}
		}
	}
#if 1
	if (c.isCollisionDetectionWithOpp(vir_pl[0], vir_pl[1])) {
		player[0].setAcceleration(player[1].getAccelerationX()*-1, player[1].getAccelerationY()*-1);
		player[1].setAcceleration(player[0].getAccelerationX()*-1, player[0].getAccelerationY()*-1);
	}
#endif
	for (int i = 0; i < 2; i++) {
		player[i].update();
	}
	return this;
}

void Game::draw()
{
	for (int i = 0; i < 2;i++)
		player[i].draw();

	for (std::map<std::string, Enclosure*>::iterator it = enclosures.begin(); it != enclosures.end(); it++) {
		it->second->draw();
	}
}