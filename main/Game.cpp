#include "stdafx.h"

#include "Game.h"


// INIT VARIABLES
void Game::initVariables()
{
	this->isEndgame = false;
}

// INIT WINDOW
void Game::initWindow()
{
	// Size of the window
	this->videomode = sf::VideoMode(800, 600);
	
	// Name, style of the window
	this->window = new sf::RenderWindow(this->videomode, "Game4", sf::Style::Titlebar | sf::Style::Close);
	
	// Framerate
	this->window->setFramerateLimit(60);
	
	// Vertical sync
	this->window->setVerticalSyncEnabled(false);
}

void Game::initPlayer()
{

}


// Constructor
Game::Game()
{

	this->initVariables();
	this->initWindow();
}

// Destructor
Game::~Game()
{
	delete this->window;
}

// Functions
// Run functon
void Game::run()
{
	while (this->window->isOpen())
	{
		this->update();
		this->render();
	}
}

// UPDATE
// Poll events
void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed: // If clicked on X button
			this->window->close();
			break;
		case sf::Event::KeyPressed: // If pressed key ESCAPE
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
		}
	}
}

void Game::updatePlayer()
{
	this->player.update();
}

// UPDATE
void Game::update()
{
	this->pollEvents();

	if (!this->isEndgame)
	{
		// UPDATE EVERYTHING HERE:
		// ========================================

		this->updatePlayer();



		// ========================================
	}
}

void Game::renderPlayer()
{
	this->player.render(this->window);
}

// RENDER
void Game::render()
{
	// Clear old frame
	this->window->clear();

	// DRAW EVERYTHING HERE:
	// ========================================

	this->renderPlayer();




	// ========================================

	// Show everything
	this->window->display();
}
