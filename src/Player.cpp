#include "Player.hpp"
#include "Projectile.hpp"
#include "Scene.hpp"

Player::Player(Scene* scene): shootCooldown(0) {
	this->scene = scene;
	hitbox = new sf::RectangleShape(sf::Vector2f(100.0f, 100.0f));
}

Player::~Player() {
	delete(hitbox);
}

void Player::shoot() {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !shootCooldown) {
		shootCooldown = 25;
		scene->addObject(new Projectile(scene));

	}
	if (shootCooldown > 0) shootCooldown--;
}

void Player::init() {
	hitbox->setOrigin(
		hitbox->getSize().x / 2,
		hitbox->getSize().y / 2
	);
	hitbox->setPosition(
		GameWindow::WINDOW_WIDTH / 2,
		GameWindow::WINDOW_HEIGHT / 2
	);
	hitbox->setFillColor(sf::Color(160, 0, 255));
	speed = 1000.0f;
}

void Player::update(float dt) {
	// Movement
	sf::Vector2f direction;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) direction.y -= 1.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) direction.y += 1.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) direction.x -= 1.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) direction.x += 1.0f;
	direction = normalize(direction);
	hitbox->move(direction * speed * dt);

	shoot();
}
