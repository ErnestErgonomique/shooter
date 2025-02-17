#pragma once

#include "GameObject.hpp"

class Ennemy : public GameObject {
private:
	float speed;
	int health;
public:
	Ennemy(Scene* scene);
	~Ennemy();
	int getHealth();
	void getHit();
	void init() override;
	void update(float dt) override;
};
