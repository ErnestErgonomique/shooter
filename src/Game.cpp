#include "Game.hpp"

Game::Game() {
	currentScene = new LevelScene(this);
}

Game::~Game() {
	delete(currentScene);
}

void Game::init() {
	GameWindow::init();
	GameWindow::window.setVerticalSyncEnabled(true);
	currentScene->init();
	// Create a switch scene method
}

void Game::run() {
	while (GameWindow::window.isOpen()) {
		sf::Event event;
		float dt;

		while (GameWindow::window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				GameWindow::window.close();
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			GameWindow::window.close();
		}

		// Better put it in a GameWindow method
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::F11)) {
			// If full screen then make the game windowed and vice versa
			if (GameWindow::fullScreen) {
				GameWindow::fullScreen = false;
				GameWindow::window.close();
				GameWindow::window.create(sf::VideoMode(
					GameWindow::WINDOW_WIDTH,
					GameWindow::WINDOW_HEIGHT
				), "Shooter");
				GameWindow::window.setFramerateLimit(144);
			} else {
				GameWindow::fullScreen = true;
				GameWindow::window.close();
				GameWindow::window.create(sf::VideoMode(
					GameWindow::WINDOW_WIDTH,
					GameWindow::WINDOW_HEIGHT
				), "Shooter", sf::Style::Fullscreen);
				GameWindow::window.setFramerateLimit(144);
			}
		}

		dt = clock.restart().asSeconds();

		currentScene->update(dt);
		render();
	}
}

void Game::render() {
	GameWindow::window.clear(sf::Color::Black);
	for (GameObject* go : currentScene->getObjects()) {
		GameWindow::window.draw(*go->getSprite());
	}
	GameWindow::window.display();
}
