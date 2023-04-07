#include "raylib.h"
#include <iostream>
#include <string>
#include "Ball.h"
#include "Paddle.h"
#include "TextPoint.h"

using std::to_string;
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
TextPoint playerPointText = TextPoint(100, 100, to_string(PlayerPoints), 30, LIGHTGRAY);
TextPoint AIpointText = TextPoint(screenWidth - 100, 100, to_string(AIpoints), 30, LIGHTGRAY);
int result = 0;
TextPoint outcomeText = TextPoint(screenWidth / 2 - 50, screenHeight / 3, "", 40, LIGHTGRAY);
void Restarted();


int main(int argc, char* argv[])
{
   
    InitWindow(screenWidth, screenHeight, "Pong");
    SetTargetFPS(60);
    paddleR = Paddle(screenWidth - 30, 200, 32, 128, 2, false);

    // Main game loop
    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_R)) {
            Restarted();
        }

        Update();
        Draw();
    }

    CloseWindow();
    return 0;
}

void Update()
{
    if (result == 0) {
        ball.Update();


        paddleL.Update();
        paddleR.Update();
        RectangleI ballRect = ball.GetRect();
        RectangleI paddleLRect = paddleL.GetRect();
        RectangleI paddleRRect = paddleR.GetRect();
        bool collidingL = Collisions::AABBCollision(ballRect, paddleLRect);
        if (collidingL) {
            ball.HorizontalBounce(paddleLRect.x + paddleLRect.width);
            cout << "collision" << endl;
        }
        bool collidingR = Collisions::AABBCollision(ballRect, paddleRRect);
        if (collidingR) {
            ball.HorizontalBounce(paddleRRect.x - paddleRRect.width);
            cout << "collision" << endl;
        }

        paddleR.UpdateAI(ballRect.y);

        //points
        if (ball.GetX() < 0) {
            ++AIpoints;
            cout << AIpoints << endl;
            ball.SetX(screenWidth / 2);
            ball.HorizontalBounce(screenWidth / 2);
            AIpointText.SetTextPoint(to_string(AIpoints));
            //defeat
            if (AIpoints >= 7) {
                result = 2;
                outcomeText.SetTextPoint("Defeat");
            }

        }
        else if (ball.GetX() > screenWidth) {
            cout << "lost" << endl;
            ++PlayerPoints;
            cout << PlayerPoints << endl;
            ball.SetX(screenWidth / 2);
            ball.HorizontalBounce(screenWidth / 2);
            playerPointText.SetTextPoint(to_string(PlayerPoints));
            //victory
            if (PlayerPoints >= 7) {
                result = 1;
                outcomeText.SetTextPoint("Victory");
            }
            
        }
    }
}





void Draw()
{
    BeginDrawing();
    ClearBackground(BLACK);
    playerPointText.Draw();
    AIpointText.Draw();
    outcomeText.Draw();
    paddleL.Draw();
    paddleR.Draw();
    ball.Draw();

    EndDrawing();

}

void Restarted() {
    PlayerPoints = 0;
    AIpoints = 0;
    
    result = 0;
    
    outcomeText.SetTextPoint("");
    playerPointText.SetTextPoint("0");
    AIpointText.SetTextPoint("0");
    
    ball.SetX(screenWidth / 2);
    
}
    