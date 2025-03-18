/* Todo list

* set up
- [X]read the red blob games articels
- [X]make a grid/ tile map

* pathfinding
- [X]chouse algorithm(Breadth-first search)
- [X]implement it

* creeps
- [X]creeps can spawn and move in the grid
- [X]creeps follow the pathfinding
- [X]creeps go around obstecels
- [ ]more than one kind?

* tiles
- [X]wall tiels
- [X]Spire/goal tile

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
    GridPos bfsPos = {10, 10};
    
    Vector2 circel = { grid[circelPos.y][circelPos.x].x, grid[circelPos.y][circelPos.x].y};
    
    Queue queue;
    
    InitWindow(screenWidth, screenHeight, "Defend the spire");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    
    initializeQueue(&queue);
        
    enqueue(&queue, grid[bfsPos.y][bfsPos.x].x, grid[bfsPos.y][bfsPos.x].y);
    grid[bfsPos.y][bfsPos.x].reached = true;
    grid[bfsPos.y][bfsPos.x].direction = 0;
    
    bool isDone = false;
    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if(!isDone && IsKeyDown(KEY_SPACE)){
            if(bfsPos.x <= 19 && bfsPos.x >= 0 && bfsPos.y <= 19 && bfsPos.y >= 0){
                
                if(grid[bfsPos.y+1][bfsPos.x].reached == false && grid[bfsPos.y+1][bfsPos.x].IsWall == false){
                    enqueue(&queue, bfsPos.x, bfsPos.y+1);
                    grid[bfsPos.y+1][bfsPos.x].reached = true;
                    grid[bfsPos.y+1][bfsPos.x].direction = 2;
                }
        
                if(grid[bfsPos.y-1][bfsPos.x].reached == false && grid[bfsPos.y-1][bfsPos.x].IsWall == false){
                    enqueue(&queue, bfsPos.x, bfsPos.y-1);
                    grid[bfsPos.y-1][bfsPos.x].reached = true;
                    grid[bfsPos.y-1][bfsPos.x].direction = 1;
                }
        
                if(grid[bfsPos.y][bfsPos.x+1].reached == false && grid[bfsPos.y][bfsPos.x+1].IsWall == false){
                    enqueue(&queue, bfsPos.x+1, bfsPos.y);
                    grid[bfsPos.y][bfsPos.x+1].reached = true;
                    grid[bfsPos.y][bfsPos.x+1].direction = 3;
                }
        
                if(grid[bfsPos.y][bfsPos.x-1].reached == false && grid[bfsPos.y][bfsPos.x-1].IsWall == false){
                    enqueue(&queue, bfsPos.x-1, bfsPos.y);
                    grid[bfsPos.y][bfsPos.x-1].reached = true;
                    grid[bfsPos.y][bfsPos.x-1].direction = 4;
                }
            }
            dequeue(&queue);
            
            isDone = peek(&queue, &bfsPos);
        }
        
        if(isDone){
            if(grid[circelPos.y][circelPos.x].IsWall == true){
                //do a reset if you need to avoid clotions
            }
            else if(grid[circelPos.y][circelPos.x].direction == 4 && grid[circelPos.y][circelPos.x+1].IsWall == false){
                circelPos.x++;
                circel.x = grid[circelPos.y][circelPos.x].x;
            }
            else if(grid[circelPos.y][circelPos.x].direction == 3 && grid[circelPos.y][circelPos.x-1].IsWall == false){
                circelPos.x--;
                circel.x = grid[circelPos.y][circelPos.x].x;
            }
            else if(grid[circelPos.y][circelPos.x].direction == 2 && grid[circelPos.y-1][circelPos.x].IsWall == false){
                circelPos.y--;
                circel.y = grid[circelPos.y][circelPos.x].y;
            }
            else if(grid[circelPos.y][circelPos.x].direction == 1 && grid[circelPos.y+1][circelPos.x].IsWall == false){
                circelPos.y++;
                circel.y = grid[circelPos.y][circelPos.x].y;
            }
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
            
            DrawText("Hold [Space] to generate pathfinding", 10, 700, 30, BLACK);
            DrawText("Press [Left mouse button] to place a wall", 10, 740, 30, BLACK);
            DrawText("Press [Right mouse button] to remove a wall", 10, 780, 30, BLACK);

        EndDrawing();
    }
    
   CloseWindow();
   
    return 0;
}