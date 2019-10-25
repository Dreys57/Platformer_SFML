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

	playerSprite_.setPosition(playerPosition_);
	window.draw(playerSprite_);
}

void PlayerCharacter::Init()
{
	playerSprite_.setOrigin(playerPosition_);
}
