#pragma once

#include "GameObject.hpp"

class Player : public GameObject {
private:
	float speed;
	float shootCooldown;
public:
	Player(Scene* scene);
	~Player();
	void shoot(float dt);
	void init() override;
	void update(float dt) override;
};
