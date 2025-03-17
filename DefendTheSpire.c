/* Todo list

* set up
- [X]read the red blob games articels
- [X]make a grid/ tile map

* pathfinding
- [X]chouse algorithm(Breadth-first search)
- [ ]implement it

* creeps
- [X]creeps can spawn and move in the grid
- [ ]creeps follow the pathfinding
- [ ]more than one kind?

* tiles
- [X]wall tiels
- [ ]Spire/goal tile

* towers? (idk if i will get to this)
- fill out later

*/

#include <stdbool.h>
#include "raylib.h"

#include "Queue.c"

int main(void)
{
    const int screenWidth = 900;
    const int screenHeight = 900;
    
    int GirdSize = 20;
    
    Tile grid[GirdSize][GirdSize];
    
    for(int i = 0; i < GirdSize; i++){
        for(int j = 0; j < GirdSize; j++){
            grid[i][j].x = (j * 30);
            grid[i][j].y = (i * 30);
            grid[i][j].width = 30;
            grid[i][j].height = 30;
            grid[i][j].reached = false;
            grid[i][j].IsWall = false;
        }
    }
    
    GridPos circelPos = {1, 1};
    GridPos bfsPos = {18, 18};
    
    Vector2 circel = { grid[circelPos.y][circelPos.x].x, grid[circelPos.y][circelPos.x].y};
    
    Queue queue;
    
    InitWindow(screenWidth, screenHeight, "Defend the spire");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    
    initializeQueue(&queue);
        
    enqueue(&queue, grid[bfsPos.y][bfsPos.x].x, grid[bfsPos.y][bfsPos.x].y);
    grid[bfsPos.y][bfsPos.x].reached = true;
    
    //grid[bfsPos.y][bfsPos.x]
    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if(!grid[bfsPos.y+1][bfsPos.x].reached){
            enqueue(&queue, grid[bfsPos.y+1][bfsPos.x].x, grid[bfsPos.y+1][bfsPos.x].y);
            grid[bfsPos.y+1][bfsPos.x].reached = true;
        }
        
        if(!grid[bfsPos.y-1][bfsPos.x].reached){
            enqueue(&queue, grid[bfsPos.y-1][bfsPos.x].x, grid[bfsPos.y+1][bfsPos.x].y);
            grid[bfsPos.y-1][bfsPos.x].reached = true;
        }
        
        if(!grid[bfsPos.y][bfsPos.x+1].reached){
            enqueue(&queue, grid[bfsPos.y][bfsPos.x+1].x, grid[bfsPos.y+1][bfsPos.x].y);
            grid[bfsPos.y][bfsPos.x+1].reached = true;
        }
        
        if(!grid[bfsPos.y][bfsPos.x-1].reached){
            enqueue(&queue, grid[bfsPos.y][bfsPos.x-1].x, grid[bfsPos.y+1][bfsPos.x].y);
            grid[bfsPos.y][bfsPos.x-1].reached = true;
        }    
        //dequeue(&queue);
        
        //bfsPos.x = peek_x(&queue);
        //bfsPos.y = peek_y(&queue);
        
        if (IsKeyPressed(KEY_D) && circelPos.x != GirdSize - 1 && grid[circelPos.y][circelPos.x + 1].IsWall != true){
            circelPos.x++;
            circel.x = grid[circelPos.y][circelPos.x].x;
        }
        else if (IsKeyPressed(KEY_A) && circelPos.x != 0 && grid[circelPos.y][circelPos.x - 1].IsWall != true){
            circelPos.x--;
            circel.x = grid[circelPos.y][circelPos.x].x;
        }
        else if (IsKeyPressed(KEY_W) && circelPos.y != 0 && grid[circelPos.y - 1][circelPos.x].IsWall != true){
            circelPos.y--;
            circel.y = grid[circelPos.y][circelPos.x].y;
        }
        else if (IsKeyPressed(KEY_S) && circelPos.y != GirdSize - 1 && grid[circelPos.y + 1][circelPos.x].IsWall != true){
            circelPos.y++;
            circel.y = grid[circelPos.y][circelPos.x].y;
        }
        
        Vector2 mouse = GetMousePosition();
        for(int i = 0; i < GirdSize; i++){
            for(int j = 0; j < GirdSize; j++){
                if(CheckCollisionPointRec(mouse, (Rectangle){grid[i][j].x, grid[i][j].y, grid[i][j].width, grid[i][j].height})){
                    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
                        grid[i][j].IsWall = true;
                    }
                    else if(IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)){
                        grid[i][j].IsWall = false;
                    }
                }
            }
        }
        
        BeginDrawing();

            ClearBackground(RAYWHITE);
            
            for(int i = 0; i < GirdSize; i++){
                for(int j = 0; j < GirdSize; j++){
                    DrawRectangle(grid[i][j].x, grid[i][j].y, grid[i][j].width, grid[i][j].height,grid[i][j].IsWall ? BROWN : GRAY);
                    DrawRectangleLines(grid[i][j].x, grid[i][j].y, grid[i][j].width, grid[i][j].height, grid[i][j].reached ? BLACK : WHITE);
                }
            }
            DrawCircle(circel.x + 15, circel.y + 15, 10, RED);

        EndDrawing();
    }
    
   CloseWindow();
   
    return 0;
}