#include "Game.h"
#include "Collision.h"

Game::Game()
{
	enclosures.reserve(8);
	enclosures.push_back(new Enclosure(0, 0, 640, 30, Palette::Aqua));		//Uppper
	enclosures.push_back(new Enclosure(0, 450, 640, 30, Palette::Aqua));	//Bottom
	enclosures.push_back(new Enclosure(0, 0, 30, 480, Palette::Aqua));	//left
	enclosures.push_back(new Enclosure(610, 0, 30, 480, Palette::Aqua));	//right
	enclosures.push_back(new Enclosure(0, 0, 30, 30, Palette::Aquamarine));		//Upper-left corner
	enclosures.push_back(new Enclosure(610, 0, 30, 30, Palette::Aquamarine));	//Upper-right corner
	enclosures.push_back(new Enclosure(0, 450, 30, 30, Palette::Aquamarine));	//Bottom-left corner
	enclosures.push_back(new Enclosure(610, 450, 30, 30, Palette::Aquamarine));	//Bottom-right corner


}


Game::~Game()
{
}

SceneBase* Game::update()
{
	Collision c;
	player.update();
	for (Enclosure* e : enclosures) {
		e->update();
	}

	return this;
}

void Game::draw()
{
	player.draw();
	for (Enclosure* e : enclosures) {
		e->draw();
	}
}
