#include "GameObject.hpp"

class Projectile : public GameObject {
private:
	int lifespan;
	sf::Vector2f direction;
	float speed;
public:
	Projectile(Scene* scene);
	~Projectile();
	int getLifespan();
	void destroy();
	void init() override;
	void update(float dt) override;
};
