// CREATOR: MYLES BUSIG
// NO TOUCHY!!!

#include "kit.h"

// Weather or not currently in debugging state
bool Debug = false;

// Weather or not the game is currently running (NOT PAUSED, RUNNING)
bool Running = false;

int FPS = 60;
Uint32 frameStart;

// Window where the game takes place
SDL_Window * Window;
// Renderer to display the objects
SDL_Renderer * Renderer;

int main(int argc, char * argv[])
{
	cout << "SDL Game, v0.1" << endl;
	cout << "Created by Myles Busig" << endl;
	cout << endl;

	// Initalize game
	Initalize("SDL Game, v0.1");

	// Update game
	while (Running)
	{
		frameStart = SDL_GetTicks();

		HandleEvents();
		Update();

		if (1000 > SDL_GetTicks() - frameStart)
			SDL_Delay(1000 - (SDL_GetTicks() - frameStart));
	}
	
	// Destroy the renderer
	SDL_DestroyRenderer(Renderer);
	// Destroy the window
	SDL_DestroyWindow(Window);
	// Quit the game
	SDL_Quit();

	return 0;
}

// Function used to initalize the game
void Initalize(const char * gameName, bool fullscreen, int w, int h, int r, int g, int b, int a)
{
	if (KEYISDOWN(VK_S) && KEYISDOWN(VK_D) && KEYISDOWN(VK_L))
		Debug = true;

	if (Debug)
		cout << "Initalizing game \"" << gameName << "\"..." << endl;

	// Number of errors encountered while initalizing game
	int initErrors = 0;

	// Print debug stuff
	if (Debug)
	{
		cout << endl;
		cout << "----- WINDOW DEBUG -----" << endl;
		cout << "Gamename: " << gameName << endl;
		cout << "Fullscreen: " << fullscreen << endl;
		cout << "w: " << w << endl;
		cout << "h: " << h << endl;
		cout << "r: " << r << endl;
		cout << "g: " << g << endl;
		cout << "b: " << b << endl;
		cout << "a: " << a << endl;
		cout << "------------------------" << endl;
		cout << endl;
	}

	// Set flags (fullscreen/not fullscreen)
	int flags = 0;
	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;
	
	// Create window
	Window = SDL_CreateWindow(gameName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, flags);
	if (Window == NULL)
	{
		// Add window creation error
		++initErrors;
		if (Debug)
			cout << "ERROR CREATING WINDOW FOR GAME \"" << gameName << "\"!" << endl;
	}
	else
	{
		// Create renderer if window exists
		Renderer = SDL_CreateRenderer(Window, -1, 0);
		if (Renderer == NULL)
		{
			// Add renderer creation error
			++initErrors;
			if (Debug)
				cout << "ERROR CREATING RENDERER FOR GAME \"" << gameName << "\"!" << endl;
		}
		else
		{
			// Set renderer draw color if the renderer exists
			Running = true;
			SDL_SetRenderDrawColor(Renderer, r, g, b, a);
		}
	}

	Entity * player = CreateEntity("player", "player");

	if (Debug)
		cout << "Finished initalizing game \"" << gameName << "\" with '" << initErrors << "' error(s)" << endl;
}

// Function used to update the game (called every frame)
void Update()
{
	// Update objects
	
	for (Entity entity : Entities)
		entity.Update();

	Render();
}

// Function used to render the game (called every frame after the objects have been updated)
void Render()
{
	// Clear the renderer
	SDL_RenderClear(Renderer);

	// Render objects

	// Present the renderer (actually display the objects)
	SDL_RenderPresent(Renderer);
}

void HandleEvents()
{
	// Handle events
	SDL_Event events;
	while (SDL_PollEvent(&events))
	{
		switch (events.type)
		{
		default:
			break;
		}
	}
}