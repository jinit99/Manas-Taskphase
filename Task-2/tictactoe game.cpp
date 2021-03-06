#include <iostream>
#include <string>
#include <stdlib.h>
#include <regex>

using namespace std;
// check if no
bool isNumber(std::string x)
{
	std::regex e ("^-?\\d+");
	return std::regex_match (x,e);
}

char board[] =
{
	'-',    '-',    '-',
	'-',    '-',    '-',
	'-',    '-',    '-',
};

int playerMove = 0;

void UpdateBoard()
{
    //board setup
	cout << endl;
	cout <<"Tic Tac Toe" << endl;
	cout << "-------"  << "\t\t-------" << endl;
	cout << "|" << board[1] << "|" << board[2] << "|" << board[3] << "|" << "\t\t|1|2|3|" << endl;
	cout << "-------"  << "\t\t-------" << endl;
	cout << "|" << board[4] << "|" << board[5] << "|" << board[6] << "|" << "\t\t|4|5|6|" << endl;
	cout << "-------"  << "\t\t-------" << endl;
	cout << "|" << board[7] << "|" << board[8] << "|" << board[9] << "|" << "\t\t|7|8|9|" << endl;
	cout << "-------"  << "\t\t-------" << endl;
	cout << endl;
}

bool validatePlayerMove(int move)
{
	return board[move] == '-' && move > 0 && move < 10;
}
// check in vertical horizontal and diagonal direction
bool checkVertical()
{
	bool firstRow = board[1] == board[2] && board[2] == board[3] && board[1] != '-';
	bool secondRow = board[4] == board[5] && board[5] == board[6] && board[4] != '-';
	bool thirdRow = board[7] == board[8] && board[8] == board[9] && board[7] != '-';
	return firstRow || secondRow || thirdRow;
}

bool checkHorizontal()
{
	bool firstColumn = board[1] == board[4] && board[4] == board[7] && board[1] != '-';
	bool secondColumn = board[2] == board[5] && board[5] == board[8] && board[2] != '-';
	bool thirdColumn = board[3] == board[6] && board[6] == board[9] && board[3] != '-';
	return firstColumn || secondColumn || thirdColumn;
}
bool checkDiagonal()
{
	bool firstDiagonal = board[1] == board[5] && board[5] == board[9] && board[1] != '-';
	bool secondDiagonal = board[3] == board[5] && board[5] == board[7] && board[3] != '-';
	return firstDiagonal || secondDiagonal;
}

bool boardIsFilled()//if board is filled
{
	return board[1] != '-' && board[2] != '-' && board[3] != '-' && board[4] != '-' && board[5] != '-' && board[6] != '-' && board[7] != '-' && board[8] != '-' && board[9] != '-';
}

char getWinner(char winnerType)//to get the winner
{
	switch(winnerType// check for cases like v, h, d
	{
		case 'V':{
			bool firstRow = board[1] == board[2] && board[2] == board[3] && board[1] != '-';
			bool secondRow = board[4] == board[5] && board[5] == board[6] && board[4] != '-';
			bool thirdRow = board[7] == board[8] && board[8] == board[9] && board[7] != '-';

			if(firstRow)
			{
				return board[1];
			}else if(secondRow)
			{
				return board[4];
			}else if(thirdRow)
			{
				return board[7];
			}
			break;
		}

		case 'H':{
			bool firstColumn = board[1] == board[4] && board[4] == board[7] && board[1] != '-';
			bool secondColumn = board[2] == board[5] && board[5] == board[8] && board[2] != '-';
			bool thirdColumn = board[3] == board[6] && board[6] == board[9] && board[3] != '-';

			if(firstColumn)
			{
				return board[1];
			}else if(secondColumn)
			{
				return board[2];
			}else if(thirdColumn)
			{
				return board[3];
			}
			break;
		}

		case 'D':{
			bool firstDiagonal = board[1] == board[5] && board[5] == board[9] && board[1] != '-';
			bool secondDiagonal = board[3] == board[5] && board[5] == board[7] && board[3] != '-';

			if(firstDiagonal)
			{
				return board[1];
			}else if(secondDiagonal)
			{
				return board[3];
			}
			break;
		}
	}
}

char checkWinner()
{
	if(checkVertical())
	{
		return 'V';
	}
	else if(checkHorizontal())
	{
		return 'H';
	}
	else if(checkDiagonal())
	{
		return 'D';
	}
	else
	{
		return 'N';
	}
}

int main()
{
	system("title Tic-Tac-Toe");
	system("cls");

	bool gameOver = false;
	string input;
	char currentPlayer = 'X';
	while(!gameOver)
	{
		UpdateBoard();
		cout << "Input: ";
		cin >> input;
		if (input == "q")
		{
			gameOver = true;
			cout <<"Ending Game..."<< endl;
		}else if (input == "h")
		{
			cout << endl;
			cout << "h - for help" << endl;
			cout << "q - to quit" << endl;
			cout << "c - to clear" << endl;
		}else if (input == "c")
		{
			system("cls");
		}else{
			if(!isNumber(input))
			{
				cout <<"Not a valid input `" << input << "`" << endl;
			}else{
				playerMove = stoi(input);
				if (!validatePlayerMove(playerMove))
				{
					cout << "Not a valid playerMove `" << playerMove << "`" << endl;
				}else{
					board[playerMove] = currentPlayer;
					switch(currentPlayer)
					{
						case 'X': {
							currentPlayer = 'O';
							break;
						}

						case 'O': {
							currentPlayer = 'X';
							break;
						}
					}
				}
			}
		}
		char winnerType = checkWinner();
		if (winnerType != 'N')
		{
			char winner = getWinner(winnerType);
			cout << winner << " is the winner!!!!" << endl;
			exit(0);
		}else{
			if(boardIsFilled())
			{
				cout << "Tie!!" << endl;
				exit(0);
			}
		}
	}
	//Return 0
	return 0;
}
