#pragma once

#include "GameObject.hpp"

class Player : public GameObject {
private:
	float speed;
	int shootCooldown;
public:
	Player(Scene* scene);
	~Player();
	void shoot();
	void init() override;
	void update(float dt) override;
};
