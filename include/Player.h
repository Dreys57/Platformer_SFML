#pragma once
#include "SFML/Graphics.hpp"
class PlayerCharacter
{
public:

	PlayerCharacter();

	void Draw(sf::RenderWindow& window);
	

private:

	sf::Texture playerTexture_;
	sf::Sprite playerSprite_;
	
};

