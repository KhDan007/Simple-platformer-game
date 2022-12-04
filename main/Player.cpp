#include "stdafx.h"
#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 2.f;
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
	this->isFlipped = false;
	this->scaleSize = 5.f;
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

	this->sprite.setScale(scaleSize, scaleSize);

	this->sprite.setPosition(sf::Vector2f(100, 200));
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

void Player::updatePhysics()
{

}

// UPDATE
void Player::updateMovement()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // Left
	{
		this->sprite.move(-movementSpeed, 0);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // Right
	{
		this->sprite.move(movementSpeed, 0);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_RIGHT;
	}

	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) // Up
	//{
	//	this->sprite.move(0, -movementSpeed);
	//	this->moving = true;
	//}
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) // Down
	//{
	//	this->sprite.move(0, movementSpeed);
	//	this->moving = true;
	//}
}

void Player::updateAnimations()
{
	switch (this->animState)
	{
	case PLAYER_ANIMATION_STATES::IDLE:
		if (this->animationTimer.getElapsedTime().asMilliseconds() >= 200)
		{
			this->currentFrame.top = 0.f;
			this->currentFrame.left += 40.f;
			if (this->currentFrame.left >= 160.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
		break;

	case PLAYER_ANIMATION_STATES::MOVING_RIGHT:
		if (this->isFlipped == true)
		{
			this->sprite.setScale(scaleSize, scaleSize);
			this->sprite.move(-this->sprite.getGlobalBounds().width, 0);
			this->isFlipped = false;
		}

		if (this->animationTimer.getElapsedTime().asMilliseconds() >= 100)
		{
			this->currentFrame.top = 50.f;
			this->currentFrame.left += 40.f;
			if (this->currentFrame.left >= 360.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
		break;

	case PLAYER_ANIMATION_STATES::MOVING_LEFT:
		if (this->isFlipped == false)
		{
			this->sprite.setScale(-scaleSize, scaleSize);
			this->sprite.move(this->sprite.getGlobalBounds().width, 0);
			this->isFlipped = true;
		}

		if (this->animationTimer.getElapsedTime().asMilliseconds() >= 100)
		{
			this->currentFrame.top = 50.f;
			this->currentFrame.left += 40.f;
			if (this->currentFrame.left >= 360.f)
				this->currentFrame.left = 0;

			this->animationTimer.restart();
			this->sprite.setTextureRect(this->currentFrame);
		}
		break;
				

	default:
		this->animationTimer.restart();
		break;
	}

	if (this->animationTimer.getElapsedTime().asMilliseconds() >= 200)
	{
		this->animationTimer.restart();
		this->sprite.setTextureRect(this->currentFrame);
	}
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
