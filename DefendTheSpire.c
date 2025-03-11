/* Todo list

* set up
- read the red blob games articels
- make a grid/ tile map

* pathfinding
- chouse algorithm
- implement it

* creeps
- creeps can spawn and move in the grid
- creeps follow the pathfinding
- more than one kind?

* towers? (idk if i will get to this)
-fill out later

*/

#include "raylib.h"

int main(void)
{
    const int screenWidth = 900;
    const int screenHeight = 900;
    
    InitWindow(screenWidth, screenHeight, "Defend the spire");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        
        BeginDrawing();

            ClearBackground(RAYWHITE);

        EndDrawing();
    }

   CloseWindow();

    return 0;
}