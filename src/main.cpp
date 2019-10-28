#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <globals.h>
#include <iostream>
#include "Player.h"
#include "Platform.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 647), "Platformer");
	window.setVerticalSyncEnabled(true);

	b2World world(b2Vec2(0.0f, 9.81f));

	PlayerCharacter player = PlayerCharacter();
	
	Platform platform = Platform(sf::Vector2f(37.5f, 550), sf::Vector2f(75, 78));
	Platform platform2 = Platform(sf::Vector2f(112.5f, 550), sf::Vector2f(75, 78));
	Platform platform3 = Platform(sf::Vector2f(187.5f, 550), sf::Vector2f(75, 78));

	
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	platform.Init(world);
	platform2.Init(world);
	platform3.Init(world);
	player.Init(world);

	if(!backgroundTexture.loadFromFile("data/background.png"))
	{
		std::cerr << "[Error]\n";
	}
	backgroundSprite.setTexture(backgroundTexture);

	sf::Clock clock;
	
	while(window.isOpen())
	{

		sf::Time deltaTime = clock.restart();
		
		sf::Event event;
		
		while(window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}

		player.Update(deltaTime.asSeconds());
		world.Step(deltaTime.asSeconds(), velocityIterations, positionIterations);
		
		window.clear();


		window.draw(backgroundSprite);
		platform.Draw(window);
		platform2.Draw(window);
		platform3.Draw(window);
		player.Draw(window);
	
		window.display();
	}




	
	system("pause");
	return 0;
}