#include "stdafx.h"

/*
	Main game class. Something like a wrapper for
	whole game or Game engine.
*/


#include "Player.h"

class Game
{
private:
	// Window
	sf::VideoMode videomode;
	sf::RenderWindow* window;
	sf::Event ev;

	// Member variables
	bool isEndgame;

	// Player
	Player player;
	
	// INIT functions
	void initVariables();
	void initWindow();
	void initPlayer();

public:
	// Constructors / Destructors
	Game();
	~Game();

	// Funcitons
	void run();

	void pollEvents();


	// UPDATE
	void updatePlayer();
	void update();
	
	// RENDER
	void renderPlayer();
	void render();
};

