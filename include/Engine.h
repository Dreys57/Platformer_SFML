#pragma once
#include <Box2D/Box2D.h>
#include "Player.h"


class Engine;

class PlatformContactListener : public b2ContactListener
{
public:
	PlatformContactListener(Engine* engine);

	void BeginContact(b2Contact* contact) override;

	void EndContact(b2Contact* contact) override;
private:
	Engine* engine_ = nullptr;
};

class Engine
{
public:
	Engine();

	void OnContactEnter(b2Fixture* c1, b2Fixture* c2);
	void OnContactExit(b2Fixture* c1, b2Fixture* c2);
	void Loop();
private:
	PlayerCharacter playerCharacter_;
	PlatformContactListener platformListener_;
};