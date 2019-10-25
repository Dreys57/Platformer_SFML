#include "Platform.h"
#include <iostream>

Platform::Platform()
{
}

Platform::Platform(sf::Vector2f position, sf::Vector2f size): position_(position), size_(size)
{
	if(!platformTexture_.loadFromFile("data/plateformeSprite.png"))
	{
		std::cerr << "[Error]\n";
	}
	platformSprite_.setTexture(platformTexture_);
}

void Platform::Init()
{
	platformSprite_.setPosition(position_);
	platformSprite_.setOrigin(size_ / 2.0f);
	
}

void Platform::Draw(sf::RenderWindow& window) 
{
	window.draw(platformSprite_);
}