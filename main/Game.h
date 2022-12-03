#pragma once

/*
	Main game class. Something like a wrapper for
	whole game or Game engine.
*/

// Precompiled headers
#include "stdafx.h"

class Game
{
private:
	// Window
	sf::VideoMode videomode;
	sf::RenderWindow* window;
	sf::Event ev;

	// Member variables
	bool isEndgame;

	
	// INIT functions
	void initVariables();
	void initWindow();

public:
	// Constructors / Destructors
	Game();
	~Game();

	// Funcitons
	void run();

	void pollEvents();


	// UPDATE
	void update();
	
	// RENDER
	void render();
};

