#include <iostream>
#include <cstdlib> // for random
#include <ctime> // for getting local time for seed value

int wincheck(); //checks for victory conditoins
void playermove(char, char); //makes the player moves happen
void playerinput(); //takes player input
void apeia(); //AI for singleplayer
void printstatus(); //prints current state of the game
bool ispossible(char, char); //checks wether a move is possible or not

//char tictacarray[2][9]{
//	{'1', '2', '3', '4', '5', '6', '7', '8', '9'},
//	{'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y'}
//};
char tictacarray[9]{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char allowed[9]{'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y', 'y'};
bool run = true; //runs the game if true
int runtime = 0;
char player1move;
char player2move;
char continuegame; //continue game (Y/N)
int wincon = 0; //stores which victory if any has been 
bool ai = false; //turn of or on ai
char sorm; //holds the choise for singleplayer or multiplayer


//X = player 1, O = player2
//draw is a  thng

int main() {
	std::cout << "******** Welcome to Tic Tac Toe! ********"; //on run title
	std::cout << std::endl;
	printstatus();

	std::cout << "Do you want to play multiplayer or singleplayer? \n";
	std::cout << "Type 'M' for multiplayer and 'S' for singleplayer: ";
	std::cin >> sorm;
	std::cout << std::endl;


	switch (sorm) { //takes playerinput and turns ai on or off acordingly
	case 'M':case 'm':
		ai = false;
			break;
	case 'S':case 's':
		ai = true;
		break;
	}

	while (run == true) {
		runtime++;
		printstatus();
		playerinput(); //gets player inputs
		wincheck(); //checks if someone has won
	}
}

void printstatus() {
	//prints current state of the game
	std::cout << allowed[0] << allowed[1] << allowed[2] << allowed[3] << allowed[4] << allowed[5] << allowed[6] << allowed[7] << allowed[8] << std::endl; //this is for debugging
	std::cout << "|   " << tictacarray[0] << "   |   " << tictacarray[1] << "   |   " << tictacarray[2] << "   |" << std::endl;
	std::cout << "|   " << tictacarray[3] << "   |   " << tictacarray[4] << "   |   " << tictacarray[5] << "   |" << std::endl;
	std::cout << "|   " << tictacarray[6] << "   |   " << tictacarray[7] << "   |   " << tictacarray[8] << "   |" << std::endl;
	std::cout << std::endl;
}


void playerinput() {

	if (runtime % 2 != 0) { //runs on uneven numbers of runtime
		if (wincon == 0) {
			std::cout << "Player 1 - Write a number from 1 to 9: ";
			std::cin >> player1move; //sets player input as char.
			playermove(player1move, '0'); //calls playermove function with char 1-9 as input.
		}
	}
	else if (runtime % 2 == 0 && ai == false) { // runs on even numbers of runtime
		if (wincon == 0) { //makes it so that player 2 does not get a turn after player 1 has already won
			std::cout << "Player 2 - Write a number from 1 to 9: ";
			std::cin >> player2move;
			playermove('0', player2move);
		}
	}
	//else if (runtime % 2 == 0 && ai == true) {
	//	for (bool succes = false; succes == false;) {
	//		std::srand(948438);
	//		player2move= std::rand() % 57 + 49; //limits random numbers from '1' - '9'
	//	}
	//	playermove('0', player2move);
	//}
}

//changes the game acording to the player inputs
void playermove(char player1move, char player2move) {

	switch (ispossible(player1move, player2move)) {
	case true:
		if (runtime % 2 != 0){
			tictacarray[player1move - 49] = 'X';
			allowed[player1move - 49] = 'n';
		}
		else if (runtime % 2 == 0) {
			tictacarray[player2move - 49] = 'O';
			allowed[player2move - 49] = 'n';
		}
		break;
	case false:
		std::cout << "Invalid move! try again \n";
		runtime - 1; //turns back the turn to the player who input the invalid move instead of moving on to the other player
		break;
	}
}


//checks for a win condition
int wincheck() {

//player 1 victory check for:
	//example: if array pos 0, 1 and 3 are all X then player 1 victory is true.
	if (tictacarray[0] == 'X' && tictacarray[1] == 'X' && tictacarray[2] == 'X') { //vertical row 1
		wincon = 1;
	}
	else if (tictacarray[3] == 'X' && tictacarray[4] == 'X' && tictacarray[5] == 'X') { //verticl row 2
		wincon = 1;
	}
	else if (tictacarray[6] == 'X' && tictacarray[7] == 'X' && tictacarray[8] == 'X') { //vertical row 3
		wincon = 1;
	}
	else if (tictacarray[0] == 'X' && tictacarray[3] == 'X' && tictacarray[6] == 'X') { //horizontal row 1
		wincon = 1;
	}
	else if (tictacarray[1] == 'X' && tictacarray[4] == 'X' && tictacarray[7] == 'X') { //horizontal row 2
		wincon = 1;
	}
	else if (tictacarray[2] == 'X' && tictacarray[5] == 'X' && tictacarray[8] == 'X') { //horizontal row 3
		wincon = 1;
	}
	else if (tictacarray[0] == 'X' && tictacarray[4] == 'X' && tictacarray[8] == 'X') { //diagonal top left to bottom right
		wincon = 1;
	}
	else if (tictacarray[2] == 'X' && tictacarray[4] == 'X' && tictacarray[6] == 'X') { //diganoal top right to bottom left
		wincon = 1;
	}


	//player 2 victory check for:
	//example: if array pos 0, 1 and 3 are all O then player 2 victory is true.
	if (tictacarray[0] == 'O' && tictacarray[1] == 'O' && tictacarray[2] == 'O') { //vertical row 1
		wincon = 2;
	}
	else if (tictacarray[3] == 'O' && tictacarray[4] == 'O' && tictacarray[5] == 'O') { //verticl row 2
		wincon = 2;
	}
	else if (tictacarray[6] == 'O' && tictacarray[7] == 'O' && tictacarray[8] == 'O') { //vertical row 3
		wincon = 2;
	}
	else if (tictacarray[0] == 'O' && tictacarray[3] == 'O' && tictacarray[6] == 'O') { //horizontal row 1
		wincon = 2;
	}
	else if (tictacarray[1] == 'O' && tictacarray[4] == 'O' && tictacarray[7] == 'O') { //horizontal row 2
		wincon = 2;
	}
	else if (tictacarray[2] == 'O' && tictacarray[5] == 'O' && tictacarray[8] == 'O') { //horizontal row 3
		wincon = 2;
	}
	else if (tictacarray[0] == 'O' && tictacarray[4] == 'O' && tictacarray[8] == 'O') { //diagonal top left to bottom right
		wincon = 2;
	}
	else if (tictacarray[2] == 'O' && tictacarray[4] == 'O' && tictacarray[6] == 'O') { //diganoal top right to bottom left
		wincon = 2;
	}


	//draw condition check
	//If all values in the array differ from the initialized values then the game must be in a draw
	if (tictacarray[0] != '1' && tictacarray[1] != '2' && tictacarray[2] != '3' && tictacarray[3] != '4' && tictacarray[4] != '5' && tictacarray[5] != '6' && tictacarray[6] != '7' && tictacarray[7] != '8' && tictacarray[8] != '9') {
		wincon = 3;
	}


	switch (wincon) { //prints win messages for each case 0,1,2 and 3. 0 = no win, 1 = player1win, 2 = player2win, 3 = draw
	case 0:
		break;
	case 1:
		std::cout << "Player 1 Won the game! \n";
		break;
	case 2:
		std::cout << "Player 2 Won the game! \n";
		break;
	case 3:
		std::cout << "Draw! No one wins \n";
		break;
	}

	
	//promts user(s) if they want to continue and if so resets the game
	if (wincon != 0) {
		std::cout << "Do you want to play again? (Y/N) \n";
		std::cin >> continuegame;

		switch (continuegame) {
		case 'Y':case 'y': //if yes then reset array and wincondition and starts the game over
			run = true;
			runtime = 0; //resets runtime
			wincon = 0; //resets wincondition
			//resets the array to initialized values
			for (int i = 0; i < sizeof(tictacarray); i++) {
				tictacarray[i] = 49 + i;
			}
			main();
			break;
		case 'N':case 'n': //if no then stops the program
			run = false;
			break;
		}
	}
	return wincon; //0 = no win, 1 = player1win, 2 = player2win, 3 = draw
}


bool ispossible(char p1move, char p2move) { //not working

	if (p1move > 48 || p1move < 50) { //takes only valid inputs: '1'-'9'
		//converts the characters to integers to check the allowed array
		switch (allowed[p1move - 48]) { //gets the possition in the array that equals the input char
		case 'y':
			return true;
			break;
		case 'n':
			return false;
			break;
		}
	}
	else if(p2move > 48 || p2move < 50) {
		switch (allowed[p2move - 48]) {
		case 'y':
			return true;
			break;
		case 'n':
			return false;
			break;
		}
	}
	else {
		return false;
	}
}