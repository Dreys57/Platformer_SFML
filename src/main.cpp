#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <globals.h>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 647), "Platformer");
	window.setVerticalSyncEnabled(true);

	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	if(!backgroundTexture.loadFromFile("data/background.png"))
	{
		std::cerr << "[Error]\n";
	}
	backgroundSprite.setTexture(backgroundTexture);

	while(window.isOpen())
	{
		
		sf::Event event;
		
		while(window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}

		window.clear(sf::Color::White);

		window.draw(backgroundSprite);
	
		window.display();
	}




	
	system("pause");
	return 0;
}