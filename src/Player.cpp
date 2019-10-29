#include "Player.h"
#include "globals.h"
#include <iostream>


PlayerCharacter::PlayerCharacter()
{
	if (!playerTexture_.loadFromFile("data/personnage.png"))
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

	playerSprite_.setOrigin(playerSize_ / 2.0f);

	b2BodyDef bodyDef;
	bodyDef.position = pixel2meter(playerPosition_);
	bodyDef.type = b2_dynamicBody;
	bodyDef.fixedRotation = true;
	playerBody_ = world.CreateBody(&bodyDef);

	b2PolygonShape shape;
	shape.SetAsBox(pixel2meter(playerSize_.x) / 2.0f, pixel2meter(playerSize_.y) / 2.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.friction = 0.0f;
	fixtureDef.userData = this;

	playerBody_->CreateFixture(&fixtureDef);
}

void PlayerCharacter::Update(float dt)
{
	float jump = playerBody_->GetLinearVelocity().y;
	bool jumpButton = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

	if (jumpButton && !previousJumpButton_ && contactNb_ > 0)
	{
		jump = jumpVelocity_;
	}


	float move = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
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

	const float deltaVy = jump - playerBody_->GetLinearVelocity().y;
	const float fy = playerBody_->GetMass() * deltaVy / dt;

	playerBody_->ApplyForce(b2Vec2(fx, fy), playerBody_->GetWorldCenter(), true);

	previousJumpButton_ = jumpButton;

	if(playerBody_->GetPosition().y > 7)
	{
		playerBody_->SetTransform(b2Vec2(pixel2meter(16.0f), pixel2meter(324)), 0);
	}


}

void PlayerCharacter::OnContactBegin()
{
	contactNb_++;
}

void PlayerCharacter::OnContactEnd()
{
	contactNb_--;
}

bool PlayerCharacter::hasWon()
{
	return playerBody_->GetPosition().x > pixel2meter(800);
}
