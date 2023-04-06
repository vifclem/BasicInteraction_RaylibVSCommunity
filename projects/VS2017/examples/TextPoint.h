#pragma once
#ifndef INC_01_PONG_TEXT_H
#define INC_01_PONG_TEXT_H

#include <raylib.h>
#include <string>

using std::string;

class TextPoint
{
public:
	TextPoint() = delete;
	TextPoint(int xP, int yP, string text, int fontSizeP, Color colorP);
	~TextPoint();

	void Draw();
	void SetTextPoint(string textP);

private:

	int x;
	int y;
	string text;
	int fontSize;
	Color color;
};

#endif;

