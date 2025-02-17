#pragma once

#include "Ennemy.hpp"
#include "Player.hpp"
#include "Scene.hpp"

class LevelScene : public Scene {
public:
	LevelScene(Game* game);
	~LevelScene();
	void spawnEnnemy();
	void destroyProjectiles();
	void destroyEnnemies();
	void init() override;
	void update(float dt) override;
};
