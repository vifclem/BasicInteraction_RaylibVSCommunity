#include "Paddle.h"
#include "Ball.h"
#include "raylib.h"




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
    sizeX = 128;
    sizeY = 32;
    speedy = 5;
    left = true;

}

Paddle::~Paddle() {

}

void Paddle::Update() {
    
    if (left) {
        if (IsKeyDown(KEY_W)) {
            if (y > 4) {
                y -= speedy;
            }

        }
        if (IsKeyDown(KEY_S)) {
            if (y < GetScreenHeight() - 128) {
                y += speedy;
            }

        }
    }
    else {
        if (IsKeyDown(KEY_UP)) {
            if (y > 4) {
                y -= speedy;
            }

        }
        if (IsKeyDown(KEY_DOWN)) {
            if (y < GetScreenHeight() - 128) {
                y += speedy;
            }

        }
    }

}

void Paddle::Draw() {
    DrawRectangle(x, y , sizeY, sizeX, RED);
    DrawRectangle(x, y, sizeY, sizeX, RED);

}
