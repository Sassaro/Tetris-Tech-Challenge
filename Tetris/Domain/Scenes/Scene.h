#pragma once
#ifndef __SCENE_H__
#define __SCENE_H__

class Scene {

public:

	Scene();

	~Scene();

	void startScene();

	virtual void runScene() = 0;

	virtual void checkInput() = 0;
};

#endif // !__ISCENE_H__
