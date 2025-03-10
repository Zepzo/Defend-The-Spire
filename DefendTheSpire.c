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

int main(void)
{
    const int screenWidth = 900;
    const int screenHeight = 900;
    
    int AmountOfCreeps = 5;
    
    Rectangle Creeps[AmountOfCreeps];
    
    for(int i = 0; i < AmountOfCreeps; i++){
        Creeps[i].x = 50;
        Creeps[i].y = 50;
        Creeps[i].width = 20;
        Creeps[i].height = 20;
    }

    InitWindow(screenWidth, screenHeight, "Defend the spire");

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        
        BeginDrawing();

            ClearBackground(RAYWHITE);
            
            for(int i = 0; i < AmountOfCreeps; i++){
                DrawRectangle(Creeps[i].x, Creeps[i].y, Creeps[i].width, Creeps[i].height, RED);
            }

        EndDrawing();
    }

   CloseWindow();        // Close window and OpenGL context

    return 0;
}