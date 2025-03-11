/* Todo list

* set up
- read the red blob games articels. done
- make a grid/ tile map. done

* pathfinding
- chouse algorithm(Breadth-first search). done
- implement it.

* creeps
- creeps can spawn and move in the grid.
- creeps follow the pathfinding.
- more than one kind?.

* tiles
- difrent tiels?.

* towers? (idk if i will get to this)
-fill out later

*/

#include "raylib.h"

int main(void)
{
    const int screenWidth = 900;
    const int screenHeight = 900;
    
    int GirdSize = 20;
    
    Rectangle grid[GirdSize][GirdSize];
    
    for(int i = 0; i < GirdSize; i++){
        for(int j = 0; j < GirdSize; j++){
            grid[i][j].x = (j * 30);
            grid[i][j].y = (i * 30);
            grid[i][j].width = 30;
            grid[i][j].height = 30;
        }
    }
    
    int circel_X = 1;
    int circel_Y = 1;
    
    Vector2 circel = { grid[circel_Y][circel_X].x, grid[circel_Y][circel_X].y};
    
    InitWindow(screenWidth, screenHeight, "Defend the spire");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if (IsKeyPressed(KEY_D) && circel_X != GirdSize - 1){
            circel_X++;
            circel.x = grid[circel_Y][circel_X].x;
        }
        else if (IsKeyPressed(KEY_A) && circel_X != 0){
            circel_X--;
            circel.x = grid[circel_Y][circel_X].x;
        }
        else if (IsKeyPressed(KEY_W) && circel_Y != 0){
            circel_Y--;
            circel.y = grid[circel_Y][circel_X].y;
        }
        else if (IsKeyPressed(KEY_S) && circel_Y != GirdSize - 1){
            circel_Y++;
            circel.y = grid[circel_Y][circel_X].y;
        }
        
        BeginDrawing();

            ClearBackground(RAYWHITE);
            
            for(int i = 0; i < GirdSize; i++){
                for(int j = 0; j < GirdSize; j++){
                    DrawRectangle(grid[i][j].x, grid[i][j].y, grid[i][j].width, grid[i][j].height, GRAY);
                    DrawRectangleLines(grid[i][j].x, grid[i][j].y, grid[i][j].width, grid[i][j].height, WHITE);
                }
            }
            
            DrawCircle(circel.x + 15, circel.y + 15, 10, RED);

        EndDrawing();
    }
    
   CloseWindow();
   
    return 0;
}