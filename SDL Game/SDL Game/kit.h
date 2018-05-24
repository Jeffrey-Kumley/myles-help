// CREATOR: MYLES BUSIG
// NO TOUCHY!!!

#pragma once

// "std" namespace
using namespace std;

// External files
#include "SDL.h"
#include "SDL_image.h"
#include "WindowsPlus.h"
#include <iostream>

// Function declorations
extern void Initalize(const char * gameName = "Unknown Game, v0.0", bool fullscreen = false, int w = 600, int h = 400, int r = 200, int g = 200, int b = 200, int a = 255);
extern void Update();
extern void Render();
extern void HandleEvents();

extern bool Debug;

#include "transform.h"
#include "player.h"

#include "entity_handler.h"

extern Entity Entities[1000];

extern Entity * CreateEntity(const char * name, const char * entityFrame = "none");