#include "TextPoint.h"

TextPoint::TextPoint(int xP, int yP, string textP, int fontSizeP, Color colorP)
	: x(xP), y(yP), text(textP), fontSize(fontSizeP), color(colorP) {

}

TextPoint::~TextPoint() {

}

void TextPoint::SetTextPoint(string textP) {
	text = textP;
}

void TextPoint::Draw() {
	DrawText(text.c_str(), x, y, fontSize, color);
}
