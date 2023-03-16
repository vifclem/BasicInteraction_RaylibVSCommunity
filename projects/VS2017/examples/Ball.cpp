#include "Ball.h"
#include "raylib.h"




Ball::Ball(int x, int y, int size, int speedx, int speedy) {

    x = 100;
    y = 100;
    size = 32;
    speedx = 5;
    speedy = 5;

}

Ball::Ball() {
    x = 0;
    y = 0;
    size = 20;
    speedx = 5;
    speedy = 5;


}

Ball::~Ball() {

}


void Ball :: Update() {
    x += speedx;
    y += speedy;
    if (x > GetScreenWidth() - size) {
        speedx = -speedx;
    }
    if (x < 0 ) {
        speedx = -speedx;
    }
    if (y > GetScreenHeight() - size) {
        speedy = -speedy;
    }
    if (y < 0 ) {
        speedy = -speedy;
    }
}


void Ball::Draw() {

    //DrawRectangle(x, y, size,size, BLUE);
    DrawCircle(x, y, size, RED);

}