#include "Constants.h"
#include "graphics.h"
#include "Image.h"
#include "Grid.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int page = 0;
	int x, y;
	int sadX, sadY;
	double bias;
	double redResidents;
	double greenResidents;
	bool done = false;
	bool paused = true;
	bool gameOver = false;
	char keyInput = NULL;
	vector<Person*> sadResidents;


	cout << "Enter the level of bias (0.0 - 1.00): " << endl;
	do{
		cin >> bias;
		if (bias < 0 || bias > 1)
			cout << "Enter the level of bias (0.0 - 1.00): " << endl;
	} while (bias < 0 || bias > 1);

	do{
		cout << "You will now enter the proportion of residents.  This will represent how many" << endl;
		cout << "households are composed of each type of resident.  The sum of the proportions" << endl;
		cout << "does not need to be 100%. There can be empty households." << endl;

		cout << "Enter the proportion of red residents (0.0 - 1.00): " << endl;
		cin >> redResidents;
		cout << "Enter the proportion of green residents (0.0 - 1.00): " << endl;
		cin >> greenResidents;
		if (redResidents + greenResidents < 0 || redResidents + greenResidents > 1)
			cout << "The sum of the proportions must be less than or equal to 1: " << endl;
	} while (redResidents + greenResidents < 0 || redResidents + greenResidents > 1);



	initwindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Segregation Project");
	Grid grid(GRID_X_POSITION, GRID_Y_POSITION, redResidents, greenResidents, bias);
	grid.checkResidentSimilarity();


	while (!done)
	{
		if (!paused && !gameOver)
		{

			grid.getSadResidents(sadResidents);
			if (!sadResidents.empty())
			{
				grid.removeResident(sadResidents.back()->getGridX(), sadResidents.back()->getGridY());
				grid.getRandomEmptyResidence(x, y);
				grid.placeResident(x, y);
				sadResidents.pop_back();
			}

			grid.checkResidentSimilarity();
		}
		grid.draw();

		while (kbhit())
		{
			keyInput = getch();
		}

		switch (keyInput)
		{
		case ESC:
			done = true;
			break;
		case 's':
			paused = false;
			break;
		case 'p':
			paused = true;
			break;
		}

		if (grid.getSadCount() == 0)
		{
			gameOver = true;
		}

		setvisualpage(page);
		page = !page;
		setactivepage(page);
		delay(FRAME_DELAY);
		cleardevice();
		keyInput = NULL;
	}

	return 0;
}