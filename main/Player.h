#include "stdafx.h"

#include <iostream>

class Player
{

private:
	sf::Sprite sprite;
	sf::Texture textureSheet;

	// Animation
	sf::IntRect currentFrame;


	// Movement

	// Core

	// Init functions
	void initTexture();
	void initSprite();

public:
	Player();
	virtual ~Player();

	// Functions
	void updateMovement();
	void update();
	void render(sf::RenderTarget* target);
};

