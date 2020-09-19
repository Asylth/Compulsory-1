#include <iostream>

int wincheck(); //checks for victory conditoins
void playermove(char, char); //makes the player moves happen

char tictacarray[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
bool run = true; //runs the game if true
char player1move;
char player2move;
char continuegame; //continue game (Y/N)
int wincon = 0; //stores which victory if any has been achived

//X = player 1, O = player2
//draw is a  thng

int main()
{
	std::cout << "******** Welcome to Tic Tac Toe! ********";
	std::cout << std::endl;
	std::cout << "|   " << tictacarray[0] << "   |   " << tictacarray[1] << "   |   " << tictacarray[2] << "   |" << std::endl;
	std::cout << "|   " << tictacarray[3] << "   |   " << tictacarray[4] << "   |   " << tictacarray[5] << "   |" << std::endl;
	std::cout << "|   " << tictacarray[6] << "   |   " << tictacarray[7] << "   |   " << tictacarray[8] << "   |" << std::endl;
	std::cout << std::endl;

	while (run == true) { //prints the current state of the game and calls the functions for chaning the game
		std::cout << "Player 1 - Write a number from 1 to 9: ";
		std::cin >> player1move; //sets player input as char.
		playermove(player1move, '0'); //calls playermove function with char 1-9 as input.

		//prints current state of the game
		std::cout << "|   " << tictacarray[0] << "   |   " << tictacarray[1] << "   |   " << tictacarray[2] << "   |" << std::endl;
		std::cout << "|   " << tictacarray[3] << "   |   " << tictacarray[4] << "   |   " << tictacarray[5] << "   |" << std::endl;
		std::cout << "|   " << tictacarray[6] << "   |   " << tictacarray[7] << "   |   " << tictacarray[8] << "   |" << std::endl;
		wincheck(); //checks if someone has won

		if (wincon == 0) { //makes it so that player 2 does not get a turn after player 1 has already won
			std::cout << "Player 2 - Write a number from 1 to 9: ";
			std::cin >> player2move;
			playermove('0', player2move);

			//prints current state of the game
			std::cout << "|   " << tictacarray[0] << "   |   " << tictacarray[1] << "   |   " << tictacarray[2] << "   |" << std::endl;
			std::cout << "|   " << tictacarray[3] << "   |   " << tictacarray[4] << "   |   " << tictacarray[5] << "   |" << std::endl;
			std::cout << "|   " << tictacarray[6] << "   |   " << tictacarray[7] << "   |   " << tictacarray[8] << "   |" << std::endl;
			wincheck(); //checks if someone has won
		}
	}

}

//changes the game acording to the player inputs
void playermove(char player1move, char player2move) {

	switch (player1move) { //changes the value of the array at the possition the player requested for player 1
	case '1':
		tictacarray[0] = 'X';
		break;
	case '2':
		tictacarray[1] = 'X';
		break;
	case '3':
		tictacarray[2] = 'X';
		break;
	case '4':
		tictacarray[3] = 'X';
		break;
	case '5':
		tictacarray[4] = 'X';
		break;
	case '6':
		tictacarray[5] = 'X';
		break;
	case '7':
		tictacarray[6] = 'X';
		break;
	case '8':
		tictacarray[7] = 'X';
		break;
	case '9':
		tictacarray[8] = 'X';
		break;
	}

	switch (player2move) { //changes the value of the array at the possition the player requested for player 1
	case '1':
		tictacarray[0] = 'O';
		break;
	case '2':
		tictacarray[1] = 'O';
		break;
	case '3':
		tictacarray[2] = 'O';
		break;
	case '4':
		tictacarray[3] = 'O';
		break;
	case '5':
		tictacarray[4] = 'O';
		break;
	case '6':
		tictacarray[5] = 'O';
		break;
	case '7':
		tictacarray[6] = 'O';
		break;
	case '8':
		tictacarray[7] = 'O';
		break;
	case '9':
		tictacarray[8] = 'O';
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
			wincon = 0;
			tictacarray[0] = { '1' };
			tictacarray[1] = { '2' };
			tictacarray[2] = { '3' };
			tictacarray[3] = { '4' };
			tictacarray[4] = { '5' };
			tictacarray[5] = { '6' };
			tictacarray[6] = { '7' };
			tictacarray[7] = { '8' };
			tictacarray[8] = { '9' };
			main();
			break;
		case 'N':case 'n': //if no then stops the program
			run = false;
			break;
		}
	}
	return wincon; //0 = no win, 1 = player1win, 2 = player2win, 3 = draw
}