/* Todo list

* Game to take inspeation from
-blons

* Setup
-create cubs
-create a path the cubes could follow

* Pathfinding
-have cubes go from one side of the screan to the other
-make the cubes follw a path

* Polish
-health
-tower that attacks the cubes
-start screen
-gameover screen

*/

#include "raylib.h"

typedef struct Path{
    Vector2 StartPosition;
    Vector2 EndPosition;
}Path;

int main(void)
{
    const int screenWidth = 900;
    const int screenHeight = 900;
    
    int AmountOfCreeps = 1;
    
    Path path = {50, 300, 500, 300};
    
    Rectangle Creeps[AmountOfCreeps];
    
    for(int i = 0; i < AmountOfCreeps; i++){
        Creeps[i].x = path.StartPosition.x;
        Creeps[i].y = path.StartPosition.y - 10;
        Creeps[i].width = 20;
        Creeps[i].height = 20;
    }

    InitWindow(screenWidth, screenHeight, "Defend the spire");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if(Creeps[0].x < path.EndPosition.x - 10){
            Creeps[0].x++;
        }
        
        BeginDrawing();

            ClearBackground(RAYWHITE);
            
            DrawLine(path.StartPosition.x, path.StartPosition.y, path.EndPosition.x, path.EndPosition.y, BLACK);
            
            for(int i = 0; i < AmountOfCreeps; i++){
                DrawRectangle(Creeps[i].x, Creeps[i].y, Creeps[i].width, Creeps[i].height, RED);
            }

        EndDrawing();
    }

   CloseWindow();

    return 0;
}