#pragma once
#include "Box2D/Box2D.h"
#include "SFML/Graphics.hpp"
#include "globals.h"

class Wall : public GameObject
{
public:

	Wall();
	Wall(sf::Vector2f position, sf::Vector2f size);

	void Init(b2World& world);

	void Draw(sf::RenderWindow& window);

private:

	sf::Texture wallTexture_;
	sf::Sprite wallSprite_;
	b2Body* wallBody_ = nullptr;
	sf::Vector2f position_;
	sf::Vector2f size_;

};

