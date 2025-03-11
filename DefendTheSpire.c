/* Todo list

* set up
- read the red blob games articels
- make a grid/ tile map

* pathfinding
- chouse algorithm(Breadth-first search)
- implement it

* creeps
- creeps can spawn and move in the grid
- creeps follow the pathfinding
- more than one kind?

* tiles
- difrent tiels?

* towers? (idk if i will get to this)
-fill out later

*/

#include "raylib.h"

int main(void)
{
    const int screenWidth = 900;
    const int screenHeight = 900;
    
    Rectangle grid[50][50];
    
    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 50; j++){
            grid[i][j].x = j * 10;
            grid[i][j].y = i * 10;
            grid[i][j].width = 20;
            grid[i][j].height = 20;
        }
    }
    
    
    
    InitWindow(screenWidth, screenHeight, "Defend the spire");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        
        BeginDrawing();

            ClearBackground(RAYWHITE);
            
            for(int i = 0; i < 50; i++){
                for(int j = 0; j < 50; j++){
                    DrawRectangle(grid[i][j].x, grid[i][j].y, grid[i][j].width, grid[i][j].height, BLACK);
                }
            }

        EndDrawing();
    }

   CloseWindow();

    return 0;
}