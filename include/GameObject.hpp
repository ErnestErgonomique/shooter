#pragma once

#include "GameWindow.hpp"
#include "utility.hpp"

class Scene;

class GameObject {
protected:
	Scene* scene = nullptr;
	sf::RectangleShape* hitbox;
public:
	virtual ~GameObject() = default;
	sf::RectangleShape* getSprite();
	Scene* getScene();
	virtual void init() = 0;
	virtual void update(float dt) = 0;
};
