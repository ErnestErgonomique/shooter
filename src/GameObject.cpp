#include "GameObject.hpp"
#include "Scene.hpp"

Scene* GameObject::getScene() {
	return scene;
}

sf::RectangleShape* GameObject::getSprite() {
	return hitbox;
}


