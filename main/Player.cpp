#include "stdafx.h"
#include "Player.h"

// INIT TEXTURES
void Player::initTextures()
{
}

// INIT SPRITE
void Player::initSprite()
{
}

// CONSTURCTORS / DESTRUCTORS
Player::Player()
{
	this->initTextures();
	this->initSprite();
}

Player::~Player()
{
}

// Functions

// UPDATE
void Player::update()
{
}

// RENDER
void Player::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
