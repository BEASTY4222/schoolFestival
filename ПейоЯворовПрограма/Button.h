#include "raylib.h"
#include "string"

struct Button
{
	Font textFont;
	Rectangle box;
	std::string buttonText;
	Color normalbuttonColor;
	Color currentbuttonColor;
	Color hoverTextColor;
	Color normalTextColor;
	std::string text;

	Button(Rectangle box, std::string buttonText, Color buttonColor, std::string text)
	{
		this->box = box;
		this->buttonText = buttonText;
		this->normalbuttonColor = buttonColor;
		this->currentbuttonColor = buttonColor;
		this->text = text;
		this->normalTextColor = WHITE;
		this->hoverTextColor = BLACK;

		// Create codepoint array for Cyrillic characters
		int codepoints[512];
		int count = 0;

		// Cyrillic basic range (А-Я, а-я) - U+0400 to U+04FF
		for (int i = 0x0400; i <= 0x04FF; i++) {
			codepoints[count++] = i;
		}

		this->textFont = LoadFontEx("resources/Fonts/2596-font.ttf", 32, codepoints, count);
	}

	Button()
	{
		this->box = { 0, 0, 0, 0 };
		this->buttonText = "";
		this->normalbuttonColor = { 0, 0, 0, 255 };
		this->text = "";
		this->textFont = GetFontDefault();
	}

	void draw(){
		DrawRectangleRec(box, currentbuttonColor);
		DrawRectangleLinesEx(box, 4, BLACK);
		DrawTextEx(textFont, buttonText.c_str(), { box.x + 45, box.y + 10 }, 20, 5, BLACK);
	}

	void run(bool &nextStage, bool &peioTalking, std::string &message){
		if (CheckCollisionPointRec(GetMousePosition(), box)) {
			normalTextColor = hoverTextColor;
			currentbuttonColor = WHITE;

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
				nextStage = true;
				message = text;
				peioTalking = true;

				this->reset();
			}
		}
		else {
			normalTextColor = WHITE;
			currentbuttonColor = normalbuttonColor;
		}
		
	}

	void reset() {
		this->box = { 0, 0, 0, 0 };
		this->buttonText = "";
		this->normalbuttonColor = { 0, 0, 0, 255 };
		this->textFont = GetFontDefault();
	}

	bool operator==(const Button& other) const {
		return this->box.x == other.box.x &&
			   this->box.y == other.box.y &&
			   this->box.width == other.box.width &&
			   this->box.height == other.box.height &&
			   this->buttonText == other.buttonText &&
			   this->normalbuttonColor.r == other.normalbuttonColor.r &&
			   this->normalbuttonColor.g == other.normalbuttonColor.g &&
			   this->normalbuttonColor.b == other.normalbuttonColor.b &&
			   this->normalbuttonColor.a == other.normalbuttonColor.a &&
			   this->text == other.text;
	}
};