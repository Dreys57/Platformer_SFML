#pragma once
#include "SFML/Graphics.hpp"
#include <Box2D/Box2D.h>
#include "globals.h"

class PlayerCharacter : public GameObject
{
public:

	PlayerCharacter();

	void Draw(sf::RenderWindow& window);

	void Init(b2World& world);

	void Update(float dt);

	void OnContactBegin();
	void OnContactEnd();

private:

	sf::Texture playerTexture_;
	sf::Sprite playerSprite_;
	sf::Vector2f playerPosition_ = sf::Vector2f(16.0f, 324);
	sf::Vector2f playerSize_ = sf::Vector2f(32.0f, 38.0f);
	b2Body* playerBody_ = nullptr;
	const float playerSpeed_ = 120.0f;
	const float movementFactor_ = 0.7f;
	const float jumpVelocity_ = -5.0f;
	bool previousJumpButton_ = false;
	int contactNb_ = 0;
	
};

