#include <iostream> 
#include <ctime>

using namespace std;

const int rows = 10;
const int columns = 10;
int matrix[rows][columns];
const int maxships = 10;

// Set all positions to initial 0
void Clear() {	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			matrix[i][j] = 0;
		}
	}
}

// Display matrix
void Show() {	

	// Print number guidelines (top)
	cout << "  ";
	for (int i = 0; i < columns; i++) {	
		cout << i << " ";
	}
	cout << "(x)";	// Indicates x-axis
	cout << endl << "  ";
	for (int i = 0; i < columns; i++) {	
		cout << "| ";
	}
	cout << endl;

	for (int i = 0; i < rows; i++) {
		cout << i << " ";	// Print number guidelines (left side)
		for (int j = 0; j < columns; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << "(y)" << endl;	// Indicates y-axis
}

// Randomly place ships on matrix
void SetShips() {	
	int ships = 0;
	while (ships < maxships) {
		int x = rand() % rows;
		int y = rand() % columns;
		if (matrix[y][x] != 1) {
			matrix[y][x] = 1;
			ships++;
		}
	}
}

// Change attacked ship position value and return boolean
bool Attack(int x, int y) {	
	if (matrix[y][x] == 1) {	// switch spot of x and y to accommodate matrix
		matrix[y][x] = 2;		// switch spot of x and y to accommodate matrix
		return true;
	}
	return false;
}

// For calculating number of ships remaining
int ShipsLeft() {	
	int c = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (matrix[i][j] == 1) {
				c++;
			}
		}
	}
	return c;
}

int main() {
	srand(time(0));

	// Initialize Game
	Clear();	
	cout << "Cleared board: " << endl;
	Show();
	SetShips();
	cout << "Ships are set: " << endl;
	Show();
	cout << "Number of Ships Left: " << ShipsLeft() << endl;

	int pos1, pos2;	// For user inputs of x and y
	char prompt;	// For user input of surrender

	while (1) {
		// Prompt user for x and y coordinates 
		cout << "Please input position x and y: ";
		cin >> pos1 >> pos2;
		if (cin.fail()) {	// If incorrect input format, exit game
			break;
		}

		bool checkAttack = Attack(pos1, pos2);
		// Attack successful
		if (checkAttack) {	
			cout << "You got me!" << endl;
		}
		// Attack not successful
		else {	
			cout << "Sorry, there are no ships there." << endl;
		}

		cout << "Number of ships left: " << ShipsLeft() << endl;
		if (ShipsLeft() == 0) {
			cout << "GAMEOVER: Hooray! You sunk all the ships!" << endl;
			break;
		}

		// Surrender prompt (y = exit, n = display board and continue)
		cout << "Do you want to surrender? (y/n): ";
		cin >> prompt;
		cout << endl;
		if (prompt == 'y') {
			break;
		}
		else if (prompt == 'n') {
			Show();
		}
	}
	Show();
	return 0;
}