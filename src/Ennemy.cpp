#include "Ennemy.hpp"
#include "Player.hpp"
#include "Projectile.hpp"
#include "Scene.hpp"

Ennemy::Ennemy(Scene* scene): health(3) {
	int startPosition = rand() % 4;
	this->scene = scene;
	hitbox = new sf::RectangleShape(sf::Vector2f(100.0f, 100.0f));
	hitbox->setOrigin(
		hitbox->getSize().x / 2,
		hitbox->getSize().y / 2
	);
	switch (startPosition) {
		case 0:
			hitbox->setPosition(
				GameWindow::WINDOW_WIDTH / 4,
				GameWindow::WINDOW_HEIGHT / 4
			);
			break;
		case 1:
			hitbox->setPosition(
				GameWindow::WINDOW_WIDTH / 4 * 3,
				GameWindow::WINDOW_HEIGHT / 4
			);
			break;
		case 2:
			hitbox->setPosition(
				GameWindow::WINDOW_WIDTH / 4,
				GameWindow::WINDOW_HEIGHT / 4 * 3
			);
			break;
		case 3:
			hitbox->setPosition(
				GameWindow::WINDOW_WIDTH / 4 * 3,
				GameWindow::WINDOW_HEIGHT / 4 * 3
			);
			break;
		default:
			hitbox->setPosition(
				GameWindow::WINDOW_WIDTH / 4,
				GameWindow::WINDOW_HEIGHT / 4
			);
			break;
	}
}

Ennemy::~Ennemy() {
	delete hitbox;
}

int Ennemy::getHealth() {
	return health;
}

void Ennemy::getHit() {
	health--;
	switch (health) {
		case 3:
			hitbox->setFillColor(sf::Color(255, 255, 0));
			break;
		case 2:
			hitbox->setFillColor(sf::Color(255, 89, 0));
			break;
		case 1:
			hitbox->setFillColor(sf::Color(255, 0, 0));
			break;
		default:
			hitbox->setFillColor(sf::Color(0, 0, 0));
			break;
	}
}

void Ennemy::init() {
	hitbox->setFillColor(sf::Color(255, 165, 0));
	speed = 500.0f;
}

void Ennemy::update(float dt) {
	sf::Vector2f direction = normalize(sf::Vector2f(
		scene->getObject<Player>()->getSprite()->getPosition() -
		hitbox->getPosition()
	));

	if (hitbox->getGlobalBounds().intersects(
		scene->getObject<Player>()->getSprite()->getGlobalBounds()
	)) {
		direction = {0.0f, 0.0f};
	}
	
	hitbox->move(direction * speed * dt);
}
