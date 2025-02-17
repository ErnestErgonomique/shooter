#pragma once

#include "GameWindow.hpp"
#include "LevelScene.hpp"

class Game {
private:
	Scene* currentScene;
	sf::Clock clock;
	float dt;
public:
	Game();
	~Game();
	void init();
	void run();
	void render();
};
