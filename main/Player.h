#pragma once
// Precompiled headers
#include "stdafx.h"

class Player
{

private:
	sf::Sprite sprite;
	sf::Texture textureSheet;

	// Animation

	// Movement

	// Core

	// Init functions
	void initTextures();
	void initSprite();

public:
	Player();
	virtual ~Player();

	// Functions
	void update();
	void render(sf::RenderTarget* target);
};

