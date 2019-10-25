#include "Player.h"
#include <iostream>

PlayerCharacter::PlayerCharacter()
{
	if(!playerTexture_.loadFromFile("data/personnage.png"))
	{
		std::cerr << "[Error]\n";
	}
	playerSprite_.setTexture(playerTexture_);
}

void PlayerCharacter::Draw(sf::RenderWindow& window)
{
	window.draw(playerSprite_);
}
