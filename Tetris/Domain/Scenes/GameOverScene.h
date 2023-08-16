#pragma once
#ifndef __GAME_OVER_SCENE_H__
#define __GAME_OVER_SCENE_H__

#include "Scene.h"

class GameOverScene : public Scene {

private:

public:

	GameOverScene::GameOverScene();

	GameOverScene::~GameOverScene();

	void runScene();

	void checkInput();
};

#endif // !__GAME_OVER_SCENE_H__
