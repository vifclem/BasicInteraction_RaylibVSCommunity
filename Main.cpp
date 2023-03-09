#include "raylib.h"
#include <iostream>
#include <string>
#include "Ball.h"

using namespace std;

void Update();
void Draw();
//std::string text = "Hello player ! ";
int screenWidth = 800;
int screenHeight = 450;

int main(int argc, char* argv[])
{
    
    InitWindow(screenWidth, screenHeight, "Pong");
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose())
    {
        Update();
        Draw();
    }

    CloseWindow();
    return 0;
}

void Update()
{
       
    }

    void Draw()
    {
        BeginDrawing();
        ClearBackground(BLACK);
        //DrawText(text.c_str(), 280, 190, 20, GREEN);
        DrawRectangle(25, screenHeight / 2, 20, 130, ORANGE);
        DrawRectangle(760, screenHeight / 2, 20, 130, ORANGE);
        //Ball.Draw();
        EndDrawing();

    }

   
    