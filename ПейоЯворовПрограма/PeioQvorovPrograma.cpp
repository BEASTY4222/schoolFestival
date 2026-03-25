#include <iostream>
#include "raylib.h"

#include "QvorovMainFrame.h"

int main()
{
    // Initialize window
    InitWindow(950, 750, "Пейо Яворов");

    QvorovMainFrame mainFrame;

    // Main game loop
    while (!WindowShouldClose()) {

		mainFrame.runMath();

        BeginDrawing();
        ClearBackground({ 230, 200, 170, 255 });
        
		mainFrame.runVisuals();


        EndDrawing();
    }

    // Cleanup
    CloseWindow();

    return 0;
}
