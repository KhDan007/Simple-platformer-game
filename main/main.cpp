// Precompiled headers
#include "stdafx.h"

// Import Game class
#include "Game.h"

// MAIN FUNCTION
int main()
{
	// INIT SEED
	srand(static_cast<unsigned>(time(0)));

	// Creating game object
	Game game;

	// Run the game
	game.run();


	// End of application
	return 0;
}