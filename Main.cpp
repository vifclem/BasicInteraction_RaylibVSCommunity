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
int PlayerPoints = 0;
int AIpoints = 0;

int main(int argc, char* argv[])
{

    InitWindow(screenWidth, screenHeight, "Pong");
    SetTargetFPS(60);
    paddleR = Paddle(screenWidth - 30, 200, 32, 128, 5, false);
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
    //paddleR.Update();
    RectangleI ballRect = ball.GetRect();
    RectangleI paddleLRect = paddleL.GetRect();
    RectangleI paddleRRect = paddleR.GetRect();
    bool collidingL = Collisions::AABBCollision(ballRect, paddleLRect);
    if (collidingL) {
        ball.HorizontalBounce(paddleLRect.x + paddleLRect.width);
    }
    bool collidingR = Collisions::AABBCollision(ballRect, paddleRRect);
    if (collidingR) {
        ball.HorizontalBounce(paddleRRect.x - paddleRRect.width);
    }

    paddleR.UpdateAI(ballRect.y);

    //points
    if (ball.GetX() < 0) {
        ++AIpoints;
        ball.SetX(screenWidth / 2);
    }
    else if (ball.GetX() > screenWidth ) {
        ++PlayerPoints;
        ball.SetX(screenWidth / 2);
    }

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
    