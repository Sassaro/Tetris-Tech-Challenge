#pragma once
#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "Scene.h"
#include "Board.h"

class GameScene : public Scene {

private:

public:

	GameScene();

	~GameScene();

	void runScene();

	void checkInput();

};
#endif // !__GAME_SCENE_H__