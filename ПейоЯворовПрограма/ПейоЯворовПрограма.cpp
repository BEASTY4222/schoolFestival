#include <iostream>
#include <raylib.h>

#include "ЯворовMainFrame.h"

int main()
{
    // Initialize window
    InitWindow(800, 600, "White Screen");

    // Main game loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground({ 230, 200, 170, 255 });
        



        EndDrawing();
    }

    // Cleanup
    CloseWindow();

    return 0;
}
