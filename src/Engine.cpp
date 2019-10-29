#include "engine.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <Box2D/Box2D.h>
#include <iostream>
#include "globals.h"
#include "Player.h"
#include "Platform.h"


Engine::Engine() : platformListener_(this)
{
}

void Engine::OnContactEnter(b2Fixture* c1, b2Fixture* c2)
{
	GameObject* g1 = (GameObject*)(c1->GetUserData());
	GameObject* g2 = (GameObject*)(c2->GetUserData());
	if (g1->GetGameObjectType() == GameObjectType::PLAYER_CHARACTER ||
		g2->GetGameObjectType() == GameObjectType::PLATFORM)
	{

		playerCharacter_.OnContactBegin();
	}
}

void Engine::OnContactExit(b2Fixture* c1, b2Fixture* c2)
{
	GameObject* g1 = (GameObject*)(c1->GetUserData());
	GameObject* g2 = (GameObject*)(c2->GetUserData());
	if (g1->GetGameObjectType() == GameObjectType::PLAYER_CHARACTER ||
		g2->GetGameObjectType() == GameObjectType::PLATFORM)
	{

		playerCharacter_.OnContactEnd();
	}
}

void Engine::Loop()
{

	sf::RenderWindow window(sf::VideoMode(800, 647), "Platformer");
	window.setVerticalSyncEnabled(true);

	b2World world(b2Vec2(0.0f, 9.81f));
	world.SetContactListener(&platformListener_);

	Platform platform = Platform(sf::Vector2f(150.0f, 550), sf::Vector2f(300, 78));
	/*Platform platform2 = Platform(sf::Vector2f(112.5f, 550), sf::Vector2f(75, 78));
	Platform platform3 = Platform(sf::Vector2f(187.5f, 550), sf::Vector2f(75, 78));
	Platform platform4 = Platform(sf::Vector2f(262.5f, 550), sf::Vector2f(75, 78));*/


	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;


	/*platform2.Init(world);
	platform3.Init(world);
	platform4.Init(world);*/
	playerCharacter_.Init(world);
	platform.Init(world);

	if (!backgroundTexture.loadFromFile("data/background.png"))
	{
		std::cerr << "[Error]\n";
	}
	backgroundSprite.setTexture(backgroundTexture);

	sf::Clock clock;

	while (window.isOpen())
	{

		sf::Time deltaTime = clock.restart();

		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}

		playerCharacter_.Update(deltaTime.asSeconds());
		world.Step(deltaTime.asSeconds(), velocityIterations, positionIterations);

		window.clear();


		window.draw(backgroundSprite);
		platform.Draw(window);
		/*platform2.Draw(window);
		platform3.Draw(window);
		platform4.Draw(window);*/
		playerCharacter_.Draw(window);

		window.display();
	}

}


PlatformContactListener::PlatformContactListener(Engine* engine) : engine_(engine)
{
}

void PlatformContactListener::BeginContact(b2Contact* contact)
{
	engine_->OnContactEnter(contact->GetFixtureA(), contact->GetFixtureB());
}

void PlatformContactListener::EndContact(b2Contact* contact)
{
	engine_->OnContactExit(contact->GetFixtureA(), contact->GetFixtureB());
}
