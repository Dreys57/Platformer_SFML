#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>
#include <globals.h>
#include <iostream>
#include "Player.h"
#include "Platform.h"
#include "Engine.h"

int main()
{
	
	Engine engine;

	engine.Loop();

	
	system("pause");
	return 0;
}