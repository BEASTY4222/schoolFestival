#include "QvorovMainFrame.h"

QvorovMainFrame::QvorovMainFrame() :
	backgroundImage(LoadImage("resources/pics/peioKushtajpg.jpg")),
	backgroundTexture(LoadTextureFromImage(backgroundImage)),

	peioImage(LoadImage("resources/pics/peioQvorov.png")),
	peioTexture(LoadTextureFromImage(peioImage)),

	firstOptionSelected(false), secondOptionSelected(false),

	start(true), startTime(0.0f), howBlack(1.0f), peioTalking(false), showInterviewOptions(false), optionsIndex(0),
	optionsBox({ 465, 500, 475, 190 }),
	peioMessageBox({ 470, 50, 470, 250 }),


	helloPeioButton({ 470, 550, 470, 50 }, "Здравей,  Пейо  как  си?", GRAY,
		std::string("Здравейте  аз  се  чуства  разкошно,\nтова  ми  е  първото  интервю ")),

	biographyButton({ 470, 550, 100, 50 }, "Кой всъщнмост е Пейо Яворов?", GRAY,
		std::string("Кой съм аз? \n ") + "Поет, роден от мрака и светлината, от болката и копнежа. \n " +
		"Душа, разкъсвана между любовта, която изгаря, и свободата, която не чака. \n" +
		"Живях кратко, но в пламък – в стиховете, в борбата, в страстта.\n" +
		"Аз съм човекът, който търси невъзможното и плаща цената му. \n" +
		"Пламък съм – понякога светя, понякога изгарям, но никога не угасвам."),

	options{ { 470, 510, 470, 50 }, { 470, 570, 470, 50 }, { 470, 630, 470, 50 }, { 470, 690, 470, 50 } }

{
	int codepoints[512];
	int count = 0;

	for (int i = 0x0400; i <= 0x04FF; i++) {
		codepoints[count++] = i;
	}

	this->textFont = LoadFontEx("resources/Fonts/2596-font.ttf", 32, codepoints, count);
}

void QvorovMainFrame::runVisuals(){
	DrawTexture(backgroundTexture, 0, 0, WHITE);
	DrawTexture(peioTexture, 0, 270, WHITE);

	// Interview options box
	if (showInterviewOptions) {
		DrawRectangleRec(optionsBox, Fade(BLACK, 0.5f));
		
		// Options
		for (optionsIndex = 0;optionsIndex < 4;optionsIndex++) {
			if (optionsIndex <= availableOptions.size() - 1) {
				availableOptions.at(optionsIndex).draw();
			}
			else {
				DrawRectangleRec(options[optionsIndex], GRAY);
			}
		}
	}
	

	// Has to be active only when Peio is talking
	if (peioTalking) {
		DrawRectangleRec(peioMessageBox, Fade(BLACK, 0.5f));
		DrawTextEx(textFont, peioMessage.c_str(), { peioMessageBox.x + 20, peioMessageBox.y + 20 }, 20, 5, WHITE);
	}



	
	
	if (start) {
		DrawRectangle(0, 0, 950, 750, Fade(BLACK, howBlack));
		DrawTextEx(textFont, "Интервю с Пейо Яворов", { 310, 300 }, 40, 5, WHITE);

		startTime += GetFrameTime();
		if (startTime >= 2.5f) {
			howBlack -= 0.25f * GetFrameTime();
			if (howBlack <= 0.0f) {
				start = false;
				showInterviewOptions = true;
			}
		}
	}
}



void QvorovMainFrame::runMath() {
	if (!firstOptionSelected) {
		if (availableOptions.size() < 1) {
			availableOptions.push_back(helloPeioButton);
		}
		helloPeioButton.run(firstOptionSelected, peioTalking, peioMessage);
	}
	else if (firstOptionSelected && !secondOptionSelected) {
		// Remove the first option from available options, already selected
		std::vector<Button>::iterator it = std::find(availableOptions.begin(), availableOptions.end(), helloPeioButton);
		if (it != availableOptions.end()) {
			availableOptions.erase(it);
		}

		if (availableOptions.size() < 1) {
			availableOptions.push_back(biographyButton);
		}
		biographyButton.run(secondOptionSelected, peioTalking, peioMessage);
	}
}