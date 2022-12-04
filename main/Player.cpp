#include "stdafx.h"
#include "Player.h"

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

	this->currentFrame = sf::IntRect(9, 7, 26, 43);
	this->sprite.setTextureRect(this->currentFrame);

	this->sprite.setScale(sf::Vector2f(3, 3));
}

// CONSTURCTORS / DESTRUCTORS
Player::Player()
{
	this->initTexture();
	this->initSprite();
}

Player::~Player()
{
}

// Functions

void Player::updateMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) // Left
	{
		this->sprite.move(-5.f, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) // Right
	{
		this->sprite.move(5.f, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) // Up
	{
		this->sprite.move(0, -5.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) // Down
	{
		this->sprite.move(0, 5.f);
	}
}

// UPDATE
void Player::update()
{
	this->updateMovement();
}

// RENDER
void Player::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
