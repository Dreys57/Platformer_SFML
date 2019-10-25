#pragma once
#include "SFML/Graphics.hpp"
class PlayerCharacter
{
public:

	PlayerCharacter();

	void Draw(sf::RenderWindow& window);

	void Init();

private:

	sf::Texture playerTexture_;
	sf::Sprite playerSprite_;
	sf::Vector2f playerPosition_ = sf::Vector2f(400, 324);
	
};

