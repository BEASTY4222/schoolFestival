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
		
		int codepoints[1024];
		int count = 0;

		// ASCII printable (space 0x20 .. tilde 0x7E)
		for (int i = 0x20; i <= 0x7E; i++) codepoints[count++] = i;

		// Cyrillic block U+0400 .. U+04FF
		for (int i = 0x0400; i <= 0x04FF; i++) codepoints[count++] = i;

		// Add extra punctuation you might need
		int extras[] = { 0x00AB, 0x00BB, 0x2013, 0x2014, 0x2026, 0x2018, 0x2019 };
		for (int i = 0; i < sizeof(extras) / sizeof(extras[0]); i++) codepoints[count++] = extras[i];

		this->textFont = LoadFontEx("resources/Fonts/2596-font.ttf", 32, codepoints, count);

	}

	Button() {
		this->textFont = GetFontDefault();
		this->buttonText = "...";
		this->currentbuttonColor = GRAY;
		this->normalTextColor = WHITE;
		this->hoverTextColor = BLACK;
	
	};

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
	void run(bool& peioTalking, std::string& message) {
		if (CheckCollisionPointRec(GetMousePosition(), box)) {
			normalTextColor = hoverTextColor;
			currentbuttonColor = WHITE;

			if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
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

	void changeCords(Rectangle box) {
		this->box = box;
	}

	bool operator==(const Button& other) const {
		return this->buttonText == other.buttonText;
	}
};