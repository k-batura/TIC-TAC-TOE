// Kartikeya_Batura_TIC-TAC-TOE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <array>
#include <stdlib.h>

using namespace std;

int main()
{	
	bool again = true;

	while (again)
	{
		LOOP:
		bool found = false;
		int x1, y1, x2, y2, x3, y3, mode, ran1 = 0, ran2 = 0;
		int const NUM_ROWS = 3;
		int const NUM_COLS = 3;
		array<array<char, NUM_COLS>, NUM_ROWS> chars{ { { '\0', '\0', '\0' },{ '\0', '\0', '\0' },{ '\0', '\0', '\0' } } };
		string q = "";
		
		cout << "\n\nHow many users are playing? (1 or 2)\n";
		cin >> mode;
		cin.ignore();
		
		if (mode == 1)
		{
			while (true)
			{
				for (int x = 0; x < 3; x++) //PRINT GRID
				{
					cout << "\n|  ";
					for (int y = 0; y < 3; y++)
					{
						cout << chars[x][y] << " |  ";
					}
					cout << "\n----------------\n";
				}


				cout << "\n\nPlayer 1, enter the y-coordinate of your X\n"; //GETTING PLAYER 1's X-COORDINATE
				cin >> x3;
				cin.ignore();

				if (x3 == -1) //EXITING IF X-COORDINATE = -1
					break;
				else if (x3 < 0 || x3 > (NUM_ROWS - 1)) //MAKING SURE PLAYER 1'S X-COORDINATE IS NOT OUT OF BOUNDS
					cout << "Invlaid value for a y-coordinate";
				else
				{
					cout << "\n\nPlayer 1, enter the x-coordinate of your X\n";  //GETTING PLAYER 1's y-COORDINATE
					cin >> y3;
					cin.ignore();

					if (y3 == -1) //EXITING IF y-COORDINATE = -1
						break;
					else if (y3 < 0 || y3 > (NUM_COLS - 1))	//MAKING SURE PLAYER 1'S Y-COORDINATE IS NOT OUT OF BOUNDS
						cout << "\n\nInvlaid value for a x-coordinate";
					else
					{
						found = false;

						for (int x = 0; x < NUM_ROWS; x++)
						{
							for (int y = 0; y < NUM_COLS; y++)
							{
								if (chars[x3][y3] == 'O' || chars[x3][y3] == 'X')	//MAKING SURE THAT THERE ISN'T AN 'O' OR 'X' IN PLAYER 1'S SELECTED LOCATION
								{
									cout << "You cannot place an X here!";
									found = true;
									break;
								}
							}
							if (found)
								break;
								
						}
						if (!found)	//IF ALL THE REQUIREMENTS ARE MET, ENTERING THE 'X' INTO THE GRID AND CLEARING
						{
							chars[x3][y3] = 'X';
							system("CLS");
						}
					}
				}

				ran1 == x3;
				ran2 == y3;

				while (chars[ran1][ran2] == 'X' || chars[ran1][ran2] == 'O') //--IMP-- The program tends to take some time figuring out a location where another 'O' or a 'X' ins't present
				{
					if (chars[0][0] != '\0' && chars[0][1] != '\0' && chars[0][2] != '\0' && chars[1][0] != '\0' && chars[1][1] != '\0' && chars[1][2] != '\0' && chars[2][0] != '\0' && chars[2][1] != '\0' && chars[2][2] != '\0')
					{
						cout << "\n\nDRAW!\n\n\n";
						cout << "\n\nDo you want to play agian ? (yes/no)\n";
						getline(cin, q, '\n');

						if (q == "yes")
						{
							again == true;
							goto LOOP;

						}
						else if (q == "no")
						{
							cout << "\n\n\n<PRESS ENTER>";
							cin.clear();
							cin.ignore(32767, '\n');
							return 0;
						}
					}
					else
					{
						srand(time(NULL));
						ran1 = rand() % 3;
						ran2 = rand() % 3;
					}
					
				}

				chars[ran1][ran2] = 'O';

				//CHECKING IF PLAYER 1 WON
				if (chars[0][0] == 'X' && chars[0][1] == 'X' && chars[0][2] == 'X')
				{
					cout << "\nPlayer 1 WON!!!";
					break;
				}
				else if (chars[1][0] == 'X' && chars[1][1] == 'X' && chars[1][2] == 'X')
				{
					cout << "\nPlayer 1 WON!!!";
					break;
				}
				else if (chars[2][0] == 'X' && chars[2][1] == 'X' && chars[2][2] == 'X')
				{
					cout << "\nPlayer 1 WON!!!";
					break;
				}
				else if (chars[0][0] == 'X' && chars[1][0] == 'X' && chars[2][0] == 'X')
				{
					cout << "\nPlayer 1 WON!!!";
					break;
				}
				else if (chars[0][1] == 'X' && chars[1][1] == 'X' && chars[2][1] == 'X')
				{
					cout << "\nPlayer 1 WON!!!";
					break;
				}
				else if (chars[0][2] == 'X' && chars[1][2] == 'X' && chars[2][2] == 'X')
				{
					cout << "\nPlayer 1 WON!!!";
					break;
				}
				else if (chars[0][0] == 'X' && chars[1][1] == 'X' && chars[2][2] == 'X')
				{
					cout << "\nPlayer 1 WON!!!";
					break;
				}
				else if (chars[0][2] == 'X' && chars[1][1] == 'X' && chars[2][0] == 'X')
				{
					cout << "\nPlayer 1 WON!!!";
					break;
				}


				//CHECKING IF COMPUTER WON
				if (chars[0][0] == 'O' && chars[0][1] == 'O' && chars[0][2] == 'O')
				{
					cout << "\nYOU LOST!";
					break;
				}
				else if (chars[1][0] == 'O' && chars[1][1] == 'O' && chars[1][2] == 'O')
				{
					cout << "\nYOU LOST!";
					break;
				}
				else if (chars[2][0] == 'O' && chars[2][1] == 'O' && chars[2][2] == 'O')
				{
					cout << "\nYOU LOST!";
					break;
				}
				else if (chars[0][0] == 'O' && chars[1][0] == 'O' && chars[2][0] == 'O')
				{
					cout << "\nYOU LOST!";
					break;
				}
				else if (chars[0][1] == 'O' && chars[1][1] == 'O' && chars[2][1] == 'O')
				{
					cout << "\nYOU LOST!";
					break;
				}
				else if (chars[0][2] == 'O' && chars[1][2] == 'O' && chars[2][2] == 'O')
				{
					cout << "\nYOU LOST!";
					break;
				}
				else if (chars[0][0] == 'O' && chars[1][1] == 'O' && chars[2][2] == 'O')
				{
					cout << "\nYOU LOST!";
					break;
				}
				else if (chars[0][2] == 'O' && chars[1][1] == 'O' && chars[2][0] == 'O')
				{
					cout << "\nYOU LOST!";
					break;
				}
			}

			cout << "\n\nDo you want to play agian ? (yes/no)\n";
			getline(cin, q, '\n');

			if (q == "yes")
			{
				again == true;
			}
			else if (q == "no")
			{
				break;
			}

		}

		else if (mode == 2)
		{
			while (true)
			{
				cout << "\n\n";

				for (int x = 0; x < 3; x++) //PRINT GRID
				{
					cout << "\n|  ";
					for (int y = 0; y < 3; y++)
					{
						cout << chars[x][y] << " |  ";
					}
					cout << "\n----------------\n";
				}


				cout << "\n\nPlayer 1, enter the y-coordinate of your X\n"; //GETTING PLAYER 1's X-COORDINATE
				cin >> x1;
				cin.ignore();

				if (x1 == -1) //EXITING IF X-COORDINATE = -1
					break;
				else if (x1 < 0 || x1 > NUM_ROWS) //MAKING SURE PLAYER 1'S X-COORDINATE IS NOT OUT OF BOUNDS
					cout << "Invlaid value for a y-coordinate";
				else
				{
					cout << "\n\nPlayer 1, enter the x-coordinate of your X\n";  //GETTING PLAYER 1's y-COORDINATE
					cin >> y1;
					cin.ignore();

					if (y1 == -1) //EXITING IF y-COORDINATE = -1
						break;
					else if (y1 < 0 || y1 >(NUM_COLS - 1))	//MAKING SURE PLAYER 1'S Y-COORDINATE IS NOT OUT OF BOUNDS
						cout << "Invlaid value for a x-coordinate";
					else
					{
						found = false;

						for (int x = 0; x < NUM_ROWS; x++)
						{
							for (int y = 0; y < NUM_COLS; y++)
							{
								if (chars[x1][y1] == 'O')	//MAKING SURE THAT THERE ISN'T AN 'O' IN PLAYER 1'S SELECTED LOCATION
								{
									cout << "You cannot place an X here!";
									found = true;
									break;
								}
							}
							if (found)
								break;
						}
						if (!found)	//IF ALL THE REQUIREMENTS ARE MET, ENTERING THE 'X' INTO THE GRID AND CLEARING
						{
							chars[x1][y1] = 'X';
							system("CLS");
						}
					}
				}

				for (int x = 0; x < 3; x++) //PRINT GRID
				{
					cout << "\n|  ";
					for (int y = 0; y < 3; y++)
					{
						cout << chars[x][y] << " |  ";
					}
					cout << "\n----------------\n";
				}

				cout << "\n\nPlayer 2, enter the y-coordinate of your O\n"; //GETTING PLAYER 2's X-COORDINATE
				cin >> x2;
				cin.ignore();

				if (x2 == -1) //EXITING IF X-COORDINATE = -1
					break;

				else if (x2 < 0 || x2 > NUM_ROWS) //MAKING SURE PLAYER 2'S X-COORDINATE IS NOT OUT OF BOUNDS
					cout << "Invlaid value for a y-coordinate";

				else
				{
					cout << "\n\nPlayer 2, enter the x-coordinate of your O\n";  //GETTING PLAYER 2's y-COORDINATE
					cin >> y2;
					cin.ignore();

					if (y2 == -1) //EXITING IF Y-COORDINATE = -1
						break;

					else if (y2 < 0 || y2 >(NUM_COLS - 1))	//MAKING SURE PLAYER 2'S Y-COORDINATE IS NOT OUT OF BOUNDS
						cout << "Invlaid value for a x-coordinate";

					else
					{
						found = false;

						for (int x = 0; x < NUM_ROWS; x++)
						{
							for (int y = 0; y < NUM_COLS; y++)
							{
								if (chars[x2][y2] == 'O')	//MAKING SURE THAT THERE ISN'T AN 'X' IN PLAYER 2'S SELECTED LOCATION
								{
									cout << "You cannot place an O here!";
									found = true;
									break;
								}
							}
							if (found)
								break;
						}
						if (!found)	//IF ALL THE REQUIREMENTS ARE MET, ENTERING THE 'O' INTO THE GRID AND CLEARING
						{
							chars[x2][y2] = 'O';
							system("CLS");
						}
					}

					//Checking for Winner (placed here instead of after input of coordinates of player 1 and 2 b/c question says so)

					//CHECKING IF PLAYER 1 WON
					if (chars[0][0] == 'X' && chars[0][1] == 'X' && chars[0][2] == 'X')
					{
						cout << "\nPlayer 1 WON!!!";
						break;
					}
					else if (chars[1][0] == 'X' && chars[1][1] == 'X' && chars[1][2] == 'X')
					{
						cout << "\nPlayer 1 WON!!!";
						break;
					}
					else if (chars[2][0] == 'X' && chars[2][1] == 'X' && chars[2][2] == 'X')
					{
						cout << "\nPlayer 1 WON!!!";
						break;
					}
					else if (chars[0][0] == 'X' && chars[1][0] == 'X' && chars[2][0] == 'X')
					{
						cout << "\nPlayer 1 WON!!!";
						break;
					}
					else if (chars[0][1] == 'X' && chars[1][1] == 'X' && chars[2][1] == 'X')
					{
						cout << "\nPlayer 1 WON!!!";
						break;
					}
					else if (chars[0][2] == 'X' && chars[1][2] == 'X' && chars[2][2] == 'X')
					{
						cout << "\nPlayer 1 WON!!!";
						break;
					}
					else if (chars[0][0] == 'X' && chars[1][1] == 'X' && chars[2][2] == 'X')
					{
						cout << "\nPlayer 1 WON!!!";
						break;
					}
					else if (chars[0][2] == 'X' && chars[1][1] == 'X' && chars[2][0] == 'X')
					{
						cout << "\nPlayer 1 WON!!!";
						break;
					}


					//CHECKING IF PLAYER 2 WON
					if (chars[0][0] == 'O' && chars[0][1] == 'O' && chars[0][2] == 'O')
					{
						cout << "\nPLAYER 2 WON!!!";
						break;
					}
					else if (chars[1][0] == 'O' && chars[1][1] == 'O' && chars[1][2] == 'O')
					{
						cout << "\nPLAYER 2 WON!!!";
						break;
					}
					else if (chars[2][0] == 'O' && chars[2][1] == 'O' && chars[2][2] == 'O')
					{
						cout << "\nPLAYER 2 WON!!!";
						break;
					}
					else if (chars[0][0] == 'O' && chars[1][0] == 'O' && chars[2][0] == 'O')
					{
						cout << "\nPLAYER 2 WON!!!";
						break;
					}
					else if (chars[0][1] == 'O' && chars[1][1] == 'O' && chars[2][1] == 'O')
					{
						cout << "\nPLAYER 2 WON!!!";
						break;
					}
					else if (chars[0][2] == 'O' && chars[1][2] == 'O' && chars[2][2] == 'O')
					{
						cout << "\nPLAYER 2 WON!!!";
						break;
					}
					else if (chars[0][0] == 'O' && chars[1][1] == 'O' && chars[2][2] == 'O')
					{
						cout << "\nPLAYER 2 WON!!!";
						break;
					}
					else if (chars[0][2] == 'O' && chars[1][1] == 'O' && chars[2][0] == 'O')
					{
						cout << "\nPLAYER 2 WON!!!";
						break;
					}

					if (chars[0][0] != '\0' && chars[0][1] != '\0' && chars[0][2] != '\0' && chars[1][0] != '\0' && chars[1][1] != '\0' && chars[1][2] != '\0' && chars[2][0] != '\0' && chars[2][1] != '\0' && chars[2][2] != '\0')
					{
						cout << "\n\nDRAW!\n\n\n";
						cout << "\n\nDo you want to play agian ? (yes/no)\n";
						getline(cin, q, '\n');

						if (q == "yes")
						{
							again == true;
							goto LOOP;

						}
						else if (q == "no")
						{
							cout << "\n\n\n<PRESS ENTER>";
							cin.clear();
							cin.ignore(32767, '\n');
							return 0;
						}
					}
				}
			}

			cout << "\n\nDo you want to play agian ? (yes/no)\n";
			getline(cin, q, '\n');

			if (q == "yes")
			{
				again == true;
			}
			else if (q == "no")
			{
				break;
			}
		}

	}
	
	cout << "\n\n\n<PRESS ENTER>";
	cin.clear();
	cin.ignore(32767, '\n');

	return 0;
}