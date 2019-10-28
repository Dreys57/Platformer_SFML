#include "globals.h"

float pixel2meter(float pixel)
{
	return pixel/pixelPerMeter;
}

float meter2pixel(float meter)
{
	return meter * pixelPerMeter;
}

b2Vec2 pixel2meter(sf::Vector2f pixels)
{
	return b2Vec2(pixel2meter(pixels.x), pixel2meter(pixels.y));
}

sf::Vector2f meter2pixel(b2Vec2 meters)
{
	return sf::Vector2f(meter2pixel(meters.x), meter2pixel(meters.y));
}
