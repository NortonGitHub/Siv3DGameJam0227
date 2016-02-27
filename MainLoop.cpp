#include "MainLoop.h"
#include "Title.h"
#include "Game.h"

MainLoop::MainLoop()
{
#if 0
	_nowScene = new Title();
#endif
	_nowScene = new Game();
}


MainLoop::~MainLoop()
{
}


void MainLoop::Main() {
	_nowScene = _nowScene->update();

	CheckSceneChanged();

	_nowScene->draw();

	_beforeScene = _nowScene;
}

void MainLoop::CheckSceneChanged()
{
	if (_beforeScene != _nowScene) {
	}
}
