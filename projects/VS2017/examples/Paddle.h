#pragma once
#include "raylib.h"
#include "Ball.h"
#include "Rectangle.h"

class Paddle
{
private:
	int x;
	int y;
	int sizeX;
	int sizeY;
	int speedy;
	bool left;


public:
	//Constructeur
	Paddle(int Px, int Py, int PsizeX, int PsizeY, int Pspeedy, bool Pleft);
	Paddle();
	~Paddle();


	//other
	void Update();
	void Draw();
	RectangleI GetRect();
	void MoveUp();
	void MoveDown();
	void UpdateAI(int ballY);

};

