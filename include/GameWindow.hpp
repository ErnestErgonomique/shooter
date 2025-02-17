#pragma once

#include <SFML/Graphics.hpp>

class GameWindow {
public:
	// Dimensions
	static const int WINDOW_WIDTH = 1920;
	static const int WINDOW_HEIGHT = 1080;

	static sf::RenderWindow window;
	static sf::View view;
	static bool fullScreen;

	static void init();
};
