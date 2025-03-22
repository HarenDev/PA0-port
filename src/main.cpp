/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

by Jeffery Myers is marked with CC0 1.0. To view a copy of this license, visit https://creativecommons.org/publicdomain/zero/1.0/

*/

#include "Program.hpp"

#include "resource_dir.h"	// utility header for SearchAndSetResourceDir

int main ()
{
	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	// Create the window and OpenGL context & tell the window to use vsync and work on high DPI displays
	raylib::Window window(1024, 724, "Hello Students", FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	//Can't load sound without this method
    InitAudioDevice();

	// Create program
	Program program;

	// Initialize program
	program.Init();
	
	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		
		//Update program logic before we draw
		program.Update();

		// drawing
		BeginDrawing();

		program.Draw();
		
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
	}

	// cleanup
	// unload our program resources
	program.Unload();

	CloseAudioDevice();

	// destroy the window and cleanup the OpenGL context
	window.Close();
	return 0;
}
