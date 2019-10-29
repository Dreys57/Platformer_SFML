#include "Wall.h"
#include "globals.h"
#include <iostream>



Wall::Wall(sf::Vector2f position, sf::Vector2f size) : position_(position), size_(size)
{
	if (!wallTexture_.loadFromFile("data/BigMurTerre.png"))
	{
		std::cerr << "[Error]\n";
	}
	wallSprite_.setTexture(wallTexture_);

	gameObjectType_ = GameObjectType::PLATFORM;
}

void Wall::Init(b2World& world)
{
	wallSprite_.setPosition(position_);
	wallSprite_.setOrigin(size_ / 2.0f);

	b2BodyDef bodyDef;
	bodyDef.position = pixel2meter(position_);
	wallBody_ = world.CreateBody(&bodyDef);

	b2PolygonShape shape;
	shape.SetAsBox(pixel2meter(size_.x / 2.0f), pixel2meter(size_.y) / 2.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.friction = 0.0f;
	fixtureDef.userData = this;
	wallBody_->CreateFixture(&fixtureDef);
}

void Wall::Draw(sf::RenderWindow& window)
{
	window.draw(wallSprite_);
}
