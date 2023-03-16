#include "raylib.h"
#include <iostream>
#include <string>
#include "Ball.h"
#include "Paddle.h"

using namespace std;

void Update();
void Draw();
int screenWidth = 800;
int screenHeight = 450;
Ball ball;
Paddle paddleL;
Paddle paddleR;

int main(int argc, char* argv[])
{
    
    InitWindow(screenWidth, screenHeight, "Pong");
    SetTargetFPS(60);
    paddleR = Paddle(screenWidth - 30, 200, 128, 32, 5, false);
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
    ball.Update();
    paddleL.Update();
    paddleR.Update();
}

    void Draw()
    {
        BeginDrawing();
        ClearBackground(BLACK);
        paddleL.Draw();
        paddleR.Draw();
        ball.Draw();
        EndDrawing();

    }

   
    