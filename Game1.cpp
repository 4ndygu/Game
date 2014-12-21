#include <iostream> 
#include <ctime>

using namespace std;

const int rows = 10;
const int columns = 10;
int matrix[rows][columns];
int maxships = 10;

void Clear() {	// Set all positions to initial 0
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			matrix[i][j] = 0;
		}
	}
}

void Show() {	// Display matrix
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void SetShips() {	// Randomly place ships on matrix
	int ships = 0;
	while (ships < maxships) {
		int x = rand() % rows;
		int y = rand() % columns;
		if (matrix[x][y] != 1) {
			matrix[x][y] = 1;
		}
		ships++;
	}
}

bool Attack(int x, int y) {	// Change attacked ship position value and return boolean
	if (matrix[x][y] == 1) {
		matrix[x][y] = 2;
		return true;
	}
	return false;
}

int ShipsLeft() {	// For calculating number of ships remaining
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
	Clear();
	SetShips();
	int pos1, pos2;
	char prompt;
	while (1) {
		cout << "Please input position x and y: ";
		cin >> pos1 >> pos2;
		if (Attack(pos1, pos2)) {
			cout << "You got me!" << endl;
		}
		else {
			cout << "Sorry, there are no ships there." << endl;
		}
		cout << "Number of ships left: " << ShipsLeft() << endl;
		if (ShipsLeft() == 0) {
			cout << "Hooray! You sunk all the ships!" << endl;
			break;
		}
		cout << "Do you want to surrender? (y/n): ";
		cin >> prompt;
		cout << endl;
		if (prompt == 'y') {
			break;
		}
	}
	Show();
	return 0;
}