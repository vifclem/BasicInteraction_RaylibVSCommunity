#pragma once
#include "raylib.h"
#include "Ball.h"
#include "Rectangle.h"


class Ball
{
private:
	int x;
	int y;
	int size;
	int speedx;
	int speedy;


public:
	//Constructeur
	Ball(int x, int y, int size, int speedx, int speedy);
	Ball();
	~Ball();



	//other
	void Update();
	void Draw();
	void HorizontalBounce(int newX);
	void VerticalBounce(int newY);
	RectangleI GetRect();
	int GetX() const;
	void SetX(int xPos);
	int GetWidth() const;




};






