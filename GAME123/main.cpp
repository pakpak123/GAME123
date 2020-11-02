#include <iostream>
#include "game.h"

int main()
{
	//Init Game engine
	game game;

	//Game loop
	while (game.running())
	{
		//Update
		game.update();
		//Render
		game.render();
	}
	//End of Application
	return 0;
}





