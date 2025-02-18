#include "LevelScene.hpp"
#include "Projectile.hpp"

#include <iostream>

LevelScene::LevelScene(Game* game) {
	this->game = game;
	objects.push_back(new Player(this));
	objects.push_back(new Ennemy(this));
}

LevelScene::~LevelScene() {
	for (GameObject* go : objects) {
		delete go;
	}
}

void LevelScene::spawnEnnemy() {
	Ennemy* ennemy = nullptr;

	for (GameObject* go : objects) {
		if ((ennemy = dynamic_cast<Ennemy*>(go))) {
			break;
		}
	}

	if (!ennemy) {
		ennemy = new Ennemy(this);
		ennemy->init();
		objects.push_back(ennemy);
	}
}

void LevelScene::destroyProjectiles() {
	for (std::vector<GameObject*>::iterator it = objects.begin();
		it != objects.end();
	) {
		if (it != objects.end()) {
			Projectile* projectile = dynamic_cast<Projectile*>(*it);

			if (projectile && projectile->getLifespan() <= 0) {
				it = objects.erase(it);
			} else {
				++it;
			}
		}
	}
}

void LevelScene::destroyEnnemies() {
	for (std::vector<GameObject*>::iterator it = objects.begin();
		it != objects.end();
	) {
		if (it != objects.end()) {
			Ennemy* ennemy = dynamic_cast<Ennemy*>(*it);

			if (ennemy && ennemy->getHealth() <= 0) {
				it = objects.erase(it);
			} else {
				++it;
			}
		}
	}
}

void LevelScene::init() {
	for (GameObject* go : objects) {
		go->init();
	}
}

void LevelScene::update(float dt) {
	Scene::update(dt);
	spawnEnnemy();
	destroyProjectiles();
	destroyEnnemies();
}
