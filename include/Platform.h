#pragma once
#include "SFML/Graphics.hpp"
class Platform
{
public:

	Platform();
	Platform(sf::Vector2f position, sf::Vector2f size);

	void Init();

	void Draw(sf::RenderWindow& window);

private:

	sf::Texture platformTexture_;
	sf::Sprite platformSprite_;
	sf::Vector2f position_;
	sf::Vector2f size_;
	
};

