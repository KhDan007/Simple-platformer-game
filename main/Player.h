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
	bool animationSwitch;

	bool isFlipped;
	

	// Movement
	float movementSpeed;
	float scaleSize;

	// Physics
	sf::Vector2f velocity;
	float velocityMax;
	float velocityMin;
	float acceleration;
	float drag;
	float gravity;
	float velocityMaxY;

	// Init functions
	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimations();
	void initPhysics();

public:
	Player();
	virtual ~Player();

	// Accessors
	const bool& getAnimSwitch();

	// Functions
	void resetAnimTimer();

	void move(const float dir_x, const float dir_y);


	void updatePhysics();
	void updateMovement();
	void updateAnimations();
	void update();


	void render(sf::RenderTarget* target);
};

