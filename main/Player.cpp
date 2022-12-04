#include "stdafx.h"
#include "Player.h"

void Player::initVariables()
{
	this->moving = false;
	this->movementSpeed = 2.f;
}

// INIT TEXTURES
void Player::initTexture()
{
	
	if (!this->textureSheet.loadFromFile("Textures/player_sheet.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURES::Couldn't load textures\n";
	}
}

// INIT SPRITE
void Player::initSprite()
{
	this->sprite.setTexture(this->textureSheet);

	this->currentFrame = sf::IntRect(0, 0, 40, 50);
	this->sprite.setTextureRect(this->currentFrame);

	this->sprite.setScale(5,5);
}

void Player::initAnimations()
{
	this->animationTimer.restart();
}

// CONSTURCTORS / DESTRUCTORS
Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
}

Player::~Player()
{
}

// Functions

// UPDATE
void Player::updateMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // Left
	{
		this->sprite.move(-movementSpeed, 0);
		this->moving = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // Right
	{
		this->sprite.move(movementSpeed, 0);
		this->moving = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) // Up
	{
		this->sprite.move(0, -movementSpeed);
		this->moving = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) // Down
	{
		this->sprite.move(0, movementSpeed);
		this->moving = true;
	}
}

void Player::updateAnimations()
{
	if (this->animationTimer.getElapsedTime().asMilliseconds() >= 200)
	{
		if (this->moving == false) // IDLE Animation
		{
			this->currentFrame.left += 40.f;
			if (this->currentFrame.left >= 160)
				this->currentFrame.left = 0;
		}


		this->animationTimer.restart();
		this->sprite.setTextureRect(this->currentFrame);
	}

	this->moving = false;
}

void Player::update()
{
	this->updateAnimations();
	this->updateMovement();
}

// RENDER
void Player::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
