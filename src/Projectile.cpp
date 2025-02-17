#include "Ennemy.hpp"
#include "Player.hpp"
#include "Projectile.hpp"
#include "Scene.hpp"

Projectile::Projectile(Scene* scene): lifespan(144) {
	this->scene = scene;
	speed = 2000.0f;
	direction = normalize(sf::Vector2f(
		static_cast<sf::Vector2f>(sf::Mouse::getPosition(GameWindow::window)) -
		scene->getObject<Player>()->getSprite()->getPosition()
	));
	hitbox = new sf::RectangleShape(sf::Vector2f(30.0f, 30.0f));
	hitbox->setOrigin(hitbox->getSize() / 2.0f);
	hitbox->setPosition(scene->getObject<Player>()->getSprite()->getPosition());
	hitbox->setFillColor(sf::Color::White);
}

Projectile::~Projectile() {
	delete hitbox;
	delete scene;
}

int Projectile::getLifespan() {
	return lifespan;
}

void Projectile::destroy() {

}

void Projectile::init() {

}

void Projectile::update(float dt) {
	lifespan--;
	
	int steps = std::ceil(speed * dt / 100.0f);
	sf::Vector2f stepMovement = (direction * speed * dt) / (float)steps;

	for (int i = 0; i < steps; i++) {
		hitbox->move(stepMovement);

		for (GameObject* go : scene->getObjects()) {
			Ennemy* ennemy = dynamic_cast<Ennemy*>(go);

			if (ennemy) {
				if (hitbox->getGlobalBounds().intersects(
					ennemy->getSprite()->getGlobalBounds()
				)) {
					lifespan = 0;
					ennemy->getHit();
					return;
				}
			}
		}
	}
}
