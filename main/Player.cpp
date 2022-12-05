#include "stdafx.h"
#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 2.f;
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
	this->isFlipped = false;
	this->scaleSize = 3.f;
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

	this->sprite.setPosition(sf::Vector2f(100, -50));
}

void Player::initAnimations()
{
	this->animationTimer.restart();
	this->animationSwitch = true;
}

void Player::initPhysics()
{
	this->velocityMax = 6.f;
	this->velocityMin = 1.f;
	this->acceleration = 2.f;
	this->drag = 0.91f;
	this->gravity = 3.f;
	this->velocityMaxY = 5.f;
}

// CONSTURCTORS / DESTRUCTORS
Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
	this->initPhysics();
}

Player::~Player()
{
}

const bool& Player::getAnimSwitch()
{
	bool animSwitch = this->animationSwitch;

	if (this->animationSwitch)
		this->animationSwitch = false;

	return animSwitch;
}

const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const sf::Vector2f Player::getPosition() const
{
	return this->sprite.getPosition();
}

void Player::resetVelocityY()
{
	this->velocity.y = 0.f;
}

void Player::setPosition(const float x, const float y)
{
	this->sprite.setPosition(sf::Vector2f(x, y));
}

// Functions

void Player::resetAnimTimer()
{
	this->animationTimer.restart();
	this->animationSwitch = true;


}

void Player::move(const float dir_x, const float dir_y)
{
	// Acceleration
	this->velocity.x += dir_x * this->acceleration;

	// Limit velocity
	if (std::abs(this->velocity.x) > this->velocityMax)
	{
		this->velocity.x = this->velocityMax * ((this->velocity.x < 0.f) ? -1.f : 1.f);
	}
}

void Player::updatePhysics()
{
	// Gravity
	this->velocity.y += 1.0 * this->gravity;

	// Limit Gravity
	if (std::abs(this->velocity.y) > this->velocityMaxY)
	{
		this->velocity.y = this->velocityMaxY * ((this->velocity.y < 0.f) ? -1.f : 1.f);
	}

	// Decelration
	this->velocity *= this->drag;


	// Limit deceleration
	if (std::abs(this->velocity.x) < this->velocityMin)
	{
		this->velocity.x = 0.f;
	}
	if (std::abs(this->velocity.y) < this->velocityMin)
	{
		this->velocity.y = 0.f;
	}

	this->sprite.move(this->velocity);
}

// UPDATE
void Player::updateMovement()
{
	this->animState = PLAYER_ANIMATION_STATES::IDLE;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // Left
	{
		this->move(-1, 0);
		this->animState = PLAYER_ANIMATION_STATES::MOVING_LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // Right
	{
		this->move(1, 0);
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
		if (this->animationTimer.getElapsedTime().asMilliseconds() >= 200 || this->getAnimSwitch())
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
			this->sprite.setOrigin(0, 0);
			//this->sprite.move(-this->sprite.getGlobalBounds().width, 0 || this->getAnimSwitch());
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
			this->sprite.setOrigin(this->sprite.getGlobalBounds().width / scaleSize, 0);
			//this->sprite.move(this->sprite.getGlobalBounds().width, 0 || this->getAnimSwitch());
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
	this->updatePhysics();
}

// RENDER
void Player::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
