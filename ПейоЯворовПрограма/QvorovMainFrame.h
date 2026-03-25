#include "raylib.h"
#include "Button.h"

class QvorovMainFrame
{
	Image backgroundImage;
	Texture2D backgroundTexture;
	Image peioImage;
	Texture2D peioTexture;

	Rectangle optionsBox;
	Rectangle peioMessageBox;

	bool start;
	float startTime;
	Font textFont;
	float howBlack;
	bool peioTalking;
	bool showInterviewOptions;
	std::string peioMessage;

	// Stages
	bool firstOptionSelected;
	bool secondOptionSelected;

	// First option buttons
	Button helloPeioButton;

	// Second option buttons
	Button biographyButton;
	Button howPeioFeelsButton;



	public:
		QvorovMainFrame();

		void runVisuals();

		void runMath();
};