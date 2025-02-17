#pragma once

#include <vector>

#include "GameObject.hpp"

class Game;

class Scene {
protected:
	std::vector<GameObject*> objects;
	Game* game;
public:
	std::vector<GameObject*> getObjects();
	template <typename T>
	T* getObject() {
		for (GameObject* go : objects) {
			if (!go) continue;

			T* castedGo = dynamic_cast<T*>(go);
			if (castedGo) {
				return castedGo;
			}
		}

		return nullptr;
	}
	virtual void init() = 0;
	virtual void update(float dt);
	void addObject(GameObject* go);
};
