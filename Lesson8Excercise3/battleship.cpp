#include <iostream>
#include <stdlib.h>


using namespace std;

void printTheBoard (int limit, char arr[10][10]){
	//print the numbers up
	cout << "  " ;
	for(int i = 0; i < limit; i ++){
		cout << i << ' ';
	}
	cout << endl;
	int lineNumber = 0;
	for (int i = 0; i < limit; i++){
		//first print the line number, then print the contents
		// of the array
		cout << lineNumber << ' ';
		for (int j = 0; j < limit; j++){
			cout << arr[i][j] << ' ';
		}
		lineNumber++;
		cout << endl << endl;
	}

	cout << endl << endl;
}

int main(){
	//game variables
	int difficulty, guesses, shipSize, shipLocationX, shipLocationY, shipHits, boardLimit;

	//user input variables
	int xattack, yattack;

	//the logical game board
	bool board [10][10];
	 //the user game board
	char printBoard [10][10];

	//output
	cout << "Welcome to the battleship game" << endl;
	cout << "State how hard you want your game to be: " << endl;
	cout << "Enter 1 for easy mode ( 5 x 5 board with big ship and 10 guesses). " << endl;
	cout << "Enter 2 for medium mode (7 x 7 board with medium ship with 5 guesses)." << endl;
	cout << "Enter 3 for hard mode ( 10 x 10 mode with small ship with 3 guesses)." << endl;
	cin >> difficulty;
	system("cls");



	//fill the board with only false statements
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			board[i][j] = false;
			printBoard[i][j] = 'o';
		}
	}


	//initialize game variables depending on the difficulty
	switch (difficulty){
		case 1:
			guesses = 10;
			shipSize = shipHits = 4;
			shipLocationX = shipLocationY = 0;
			boardLimit = 5;
			break;
		case 2:
			guesses = 5;
			shipSize = shipHits = 3;
			shipLocationX = shipLocationY = 4;
			boardLimit = 7;
			break;
		case 3:
			guesses = 3;
			shipSize = shipHits = 2;
			shipLocationX = 7;
			shipLocationY = 3;
			boardLimit = 10;
			break;
	}
	// print the board for the first time
	printTheBoard(boardLimit, printBoard);
	
	// print the ship on the board
	for(int i = shipLocationY; i < (shipSize + shipLocationY) ; i++){
		board[shipLocationX][i] = true;
	}

	// game loop
	while (guesses != 0){
		cout << "Write your x & y coordinate where you want to attack" << endl;
		cin >> xattack;
		cin >> yattack;
	
		system("cls");
		if(board[xattack][yattack] == true){
			board[xattack][yattack] = false; //state the variable to false so you cant hit it again
			printBoard[xattack][yattack] = 'X'; // tell the user they already hit that place
			shipHits--; // decrease the number of hits needed to sink the ship
			printTheBoard(boardLimit, printBoard); // re-print the board with the new values
			if(shipHits == 0){
				cout << "You sunk the ship! \n";
				break;
			}else {
				cout << "Hit! you still need " << shipHits << " hits to sink the ship. \n";
				cout << "And you have " << guesses << " guesses left \n";
			}
		}else {
			printBoard[xattack][yattack] = '.';
			printTheBoard(boardLimit, printBoard);
			guesses --;
			cout << "Miss!\n";
			cout << "You have " << guesses << " guesses left \n";
		}

		
	}

	cout << "Game over!" << endl;

	int exit;
	cout << "Press any number to exit: ";
	cin >> exit;

	return 0;
}