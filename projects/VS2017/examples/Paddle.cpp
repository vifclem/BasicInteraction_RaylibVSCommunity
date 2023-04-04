#include "Paddle.h"
#include "Ball.h"
#include "raylib.h"
#include "Rectangle.h"




Paddle::Paddle(int Px, int Py, int PsizeX, int PsizeY, int Pspeedy, bool Pleft) {

    x = Px;
    y = Py;
    sizeX = PsizeX;
    sizeY = PsizeY;
    speedy = Pspeedy;
    left = Pleft;
}

Paddle::Paddle() {
    x = 0;
    y = 200;
    sizeX = 32;
    sizeY = 128;
    speedy = 5;
    left = true;

}

Paddle::~Paddle() {

}

RectangleI Paddle::GetRect() {
    return RectangleI{ x, y, sizeX, sizeY };
}

void Paddle::MoveUp() {
    y -= speedy;
    if (y < 0) {
        y = 0;
    }
}

void Paddle::MoveDown() {
    int screenHeight = GetScreenHeight();
    y += speedy;
    if (y > screenHeight - sizeY) {
        y = screenHeight - sizeY;
    }
}

void Paddle::UpdateAI(int ballY) {
    if (ballY < y + sizeY / 4) {
        MoveUp();
    }
    if (ballY > y + 3 * sizeY / 4) {
        MoveDown();
    }
}



void Paddle::Update() {

    if (IsKeyDown(KEY_W)) {
        MoveUp();
    }
    if (IsKeyDown(KEY_S)) {
        MoveDown();
    }

}

void Paddle::Draw() {
    DrawRectangle(x, y, sizeX, sizeY, RED);


}