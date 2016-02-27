#include "MainLoop.h"

MainLoop::MainLoop()
{
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
