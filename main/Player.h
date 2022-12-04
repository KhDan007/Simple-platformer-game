#include "stdafx.h"

enum PLAYER_ANIMATION_STATES {IDLE = 0, MOVING_LEFT, MOVING_RIGHT, JUMPING, FALLING};

class Player
{

private:
	// Sprite
	sf::Sprite sprite;

	// Textures
	sf::Texture textureSheet;

	// Timer
	sf::Clock animationTimer;

	// Animation
	short animState;
	sf::IntRect currentFrame;

	bool isFlipped;
	

	// Movement
	float movementSpeed;
	float scaleSize;

	// Physics
	sf::Vector2f velocity;
	float acceleration;
	float deceleration;

	// Core

	// Init functions
	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimations();

public:
	Player();
	virtual ~Player();

	// Functions
	void updatePhysics();
	void updateMovement();
	void updateAnimations();
	void update();
	void render(sf::RenderTarget* target);
};

