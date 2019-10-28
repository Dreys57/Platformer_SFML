#include "Player.h"
#include "globals.h"
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
	playerPosition_ = meter2pixel(playerBody_->GetPosition());
	playerSprite_.setPosition(playerPosition_);
	
	window.draw(playerSprite_);
}

void PlayerCharacter::Init(b2World& world)
{
	
	playerSprite_.setOrigin(playerSize_/2.0f);
	
	b2BodyDef bodyDef;
	bodyDef.position = pixel2meter(playerPosition_);
	bodyDef.type = b2_dynamicBody;
	bodyDef.fixedRotation = true;
	playerBody_ = world.CreateBody(&bodyDef);

	b2PolygonShape shape;
	shape.SetAsBox(pixel2meter(playerSize_.x) / 2.0f, pixel2meter(playerSize_.y) / 2.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;

	playerBody_->CreateFixture(&fixtureDef);
}

void PlayerCharacter::Update(float dt)
{
	float move = 0.0f;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		move -= 1.0f;
		playerSprite_.setScale(sf::Vector2f(-1, 1));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		move += 1.0f;
		playerSprite_.setScale(sf::Vector2f(1, 1));
	}

	const float deltaVx = move * pixel2meter(playerSpeed_) - playerBody_->GetLinearVelocity().x;
	const float fx = movementFactor_ * playerBody_->GetMass() * deltaVx / dt;

	playerBody_->ApplyForce(b2Vec2(fx, 0), playerBody_->GetWorldCenter(), true);
}
