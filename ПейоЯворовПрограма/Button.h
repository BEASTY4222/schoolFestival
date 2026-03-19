#include "raylib.h"
#include "string"

struct Button
{
	Rectangle box;
	std::string buttonText;
	Color buttonColor;
	std::string text;

	Button(Rectangle box, std::string buttonText, Color buttonColor, std::string text)
	{
		this->box = box;
		this->buttonText = buttonText;
		this->buttonColor = buttonColor;
		this->text = text;
	}

	Button()
	{
		this->box = { 0, 0, 0, 0 };
		this->buttonText = "";
		this->buttonColor = { 0, 0, 0, 255 };
		this->text = "";
	}



};