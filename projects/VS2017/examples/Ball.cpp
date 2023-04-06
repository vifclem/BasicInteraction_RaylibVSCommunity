#include "Ball.h"
#include "raylib.h"
#include "Rectangle.h"



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
    size = 30;
    speedx = 5;
    speedy = 5;


}

Ball::~Ball() {

}

RectangleI Ball::GetRect() {
    return RectangleI{ x, y, size, size };
}




void Ball::Update() {
    x += speedx;
    y += speedy;
   /* if (x > GetScreenWidth() - size) {
        speedx = -speedx;
        HorizontalBounce(GetScreenWidth() - size);
    }
    if (x < 0) {
        speedx = -speedx;
        HorizontalBounce(0);
    }*/



    if (y > GetScreenHeight() - size) {
        //speedy = -speedy;
        VerticalBounce(GetScreenHeight() - size);
    }
    if (y < 0) {
        //speedy = -speedy;
        VerticalBounce(0);
    }
}


int Ball::GetX() const {
    return x;
}

void Ball::SetX(int xPos) {
    x = xPos;
}

int Ball::GetWidth() const {
    return size;
}

void Ball::HorizontalBounce(int newX) {
    speedx = -speedx;
    x = newX;
}
void Ball::VerticalBounce(int newY) {
    speedy = -speedy;
    y = newY;
}

void Ball::Draw() {

    DrawRectangle(x, y, size, size, DARKGREEN);


}