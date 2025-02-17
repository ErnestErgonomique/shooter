#include "utility.hpp"

sf::Vector2f normalize(sf::Vector2f vector) {
	float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
	if (length) {
		return vector / length;
	}
	
	return sf::Vector2f(0.0f, 0.0f);
}
