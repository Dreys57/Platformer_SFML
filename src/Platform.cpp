#include "Platform.h"
#include "globals.h"
#include <iostream>



Platform::Platform(sf::Vector2f position, sf::Vector2f size) : position_(position), size_(size)
{
	if (!platformTexture_.loadFromFile("data/BigPlateforme.png"))
	{
		std::cerr << "[Error]\n";
	}
	platformSprite_.setTexture(platformTexture_);

	gameObjectType_ = GameObjectType::PLATFORM;
}

void Platform::Init(b2World& world)
{
	platformSprite_.setPosition(position_);
	platformSprite_.setOrigin(size_ / 2.0f);

	b2BodyDef bodyDef;
	bodyDef.position = pixel2meter(position_);
	platformBody_ = world.CreateBody(&bodyDef);

	b2PolygonShape shape;
	shape.SetAsBox(pixel2meter(size_.x / 2.0f), pixel2meter(size_.y) / 2.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.friction = 0.0f;
	fixtureDef.userData = this;
	platformBody_->CreateFixture(&fixtureDef);
}

void Platform::Draw(sf::RenderWindow& window)
{
	window.draw(platformSprite_);
}