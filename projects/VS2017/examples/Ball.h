#pragma once
#include "raylib.h"
#include "Ball.h"


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



};






