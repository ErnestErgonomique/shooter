#include "Game.hpp"
#include "Scene.hpp"

std::vector<GameObject*> Scene::getObjects() {
	return objects;
}

void Scene::addObject(GameObject* go) {
	objects.push_back(go);
}

void Scene::update(float dt) {
	for (GameObject* go : objects) {
		go->update(dt);
	}
}
