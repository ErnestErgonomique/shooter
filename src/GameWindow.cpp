#include "GameWindow.hpp"

sf::RenderWindow GameWindow::window;
sf::View GameWindow::view(
	sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1920.0f, 1080.0f)
);
bool GameWindow::fullScreen = true;

void GameWindow::init() {
	GameWindow::window.create(sf::VideoMode(
		GameWindow::WINDOW_WIDTH,
		GameWindow::WINDOW_HEIGHT
	), "Shooter", sf::Style::Fullscreen);
	// GameWindow::window.setView(GameWindow::view);
}
