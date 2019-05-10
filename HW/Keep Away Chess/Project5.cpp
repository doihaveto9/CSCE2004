//---------------------------------------------------
// Purpose: To implement the game "keep away chess"
//          using 2D arrays and functions.
// 
// Authors: Caleb Board - remainder of program
//          John Gauch - print_board function
//---------------------------------------------------

#include <iostream>
using namespace std;

// Program constants
const int ROWS = 8;
const int COLS = 8;

//---------------------------------------------------
// Print the 2D game board 
//---------------------------------------------------
void print_board(char board[ROWS][COLS])
{
   // Print values
   cout << "     ";
   for (int col = 0; col < COLS; col++)
      cout << col << "   ";
   cout << endl;

   // Print line
   cout << "   +";
   for (int col = 0; col < COLS; col++)
      cout << "---+";
   cout << "\n";

   // Print board
   for (int row = 0; row < ROWS; row++)
   {
      // Print values
      cout << " " << row << " | ";
      for (int col = 0; col < COLS; col++)
         cout << board[row][col] << " | ";
      cout << endl;

      // Print line
      cout << "   +";
      for (int col = 0; col < COLS; col++)
         cout << "---+";
      cout << "\n";
   }
}

//---------------------------------------------------
// Main program
//---------------------------------------------------
int main()
{
   int Win = 0;
   char Mode = ' ';
   int turn_num = 0;

   // Define game board
   char board[ROWS][COLS];
   for (int row = 0; row < ROWS; row++)
      for (int col = 0; col < COLS; col++)
         board[row][col] = ' ';

   // Print game board
   print_board(board);

   // ADD CODE HERE
   int turns = 0;

   cout << "Will you play with Rooks or Queens? Type R for Rooks or Q for Queens: ";
   cin >> Mode;
   cout << endl;
   Mode = toupper(Mode);

   while (Mode != 'R' && Mode != 'Q')
	{
   		cout << "That is an invalid game mode, please try again " << endl;
   		cin >> Mode;
   		Mode = toupper(Mode);
	}

   if (Mode == 'R')
{
   while (Win != 1)
{
	turns = turns + 1;
	int row;
	int col;

   if (turns % 2 == 1)
   {
	cout << "Player 1's Turn" << endl;
	cout << "In what row will you place your rook? ";
	cin >> row;
	cout << "In what column will you place your rook? ";
	cin >> col;

        while (row < 0 || row > 7 || col < 0 || col > 7)
        {
             	cout << "Than is an invalid location. Please try again." << endl;
             	cout << "In what row will you place your rook? ";
	     	cin >> row;
	     	cout << "In what column will you place your rook? ";
	     	cin >> col;
	}
	
	board[row][col] = 'R';
        print_board(board);
   }
   else if (turns % 2 == 0)
   {
	cout << "Player 2's Turn" << endl;
	cout << "In what row will you place your rook? ";
	cin >> row;
	cout << "In what column will you place your rook? ";
	cin >> col;
        
	while (row < 0 || row > 7 || col < 0 || col > 7)
        {
             	cout << "Than is an invalid location. Please try again." << endl;
             	cout << "In what row will you place your rook? ";
	     	cin >> row;
	     	cout << "In what column will you place your rook? ";
	     	cin >> col;
	}
	
	board[row][col] = 'R';
        print_board(board);
   }
   for (int checkrowplus = row + 1; checkrowplus <= ROWS; checkrowplus++)
   {
	if (board[checkrowplus][col] == 'R')
		Win = 1;
   }
   for (int checkrowminus = row - 1; checkrowminus >= 0; checkrowminus--)
   {
	if (board[checkrowminus][col] == 'R')
		Win = 1;
   }
   for (int checkcolplus = col + 1; checkcolplus <= COLS; checkcolplus++)
   {
	if (board[row][checkcolplus] == 'R')
		Win = 1;
   }
   for (int checkcolminus = col - 1; checkcolminus >= 0; checkcolminus--)
   {
	if (board[row][checkcolminus] == 'R')	
        	Win = 1;
   }
}
}
   if (Mode == 'Q')
{
   while (Win != 1)
{
	turns = turns + 1;
	int row;
	int col;

   if (turns % 2 == 1)
   {
	cout << "Player 1's Turn" << endl;
	cout << "In what row will you place your queen? ";
	cin >> row;
	cout << "In what column will you place your queen? ";
	cin >> col;
        
	while (row < 0 || row > 7 || col < 0 || col > 7)
        {
		cout << "Than is an invalid location. Please try again." << endl;
		cout << "In what row will you place your queen? ";
		cin >> row;
		cout << "In what column will you place your queen? ";
		cin >> col;
	}
	
	board[row][col] = 'Q';
        print_board(board);
   }
   else
   {
	cout << "Player 2's Turn" << endl;
	cout << "In what row will you place your queen? ";
	cin >> row;
	cout << "In what column will you place your queen? ";
	cin >> col;

        while (row < 0 || row > 7 || col < 0 || col > 7)
        {
             	cout << "Than is an invalid location. Please try again." << endl;
             	cout << "In what row will you place your queen? ";
	     	cin >> row;
	     	cout << "In what column will you place your queen? ";
	     	cin >> col;
	}
	
	board[row][col] = 'Q';
        print_board(board);
   }
   for (int checkrowplus = row + 1; checkrowplus <= ROWS; checkrowplus++)
   {
	if (board[checkrowplus][col] == 'Q')
		Win = 1;
   }
   for (int checkrowminus = row - 1; checkrowminus >= 0; checkrowminus--)
   {
	if (board[checkrowminus][col] == 'Q')
		Win = 1;
   }
   for (int checkcolplus = col + 1; checkcolplus <= COLS; checkcolplus++)
   {
	if (board[row][checkcolplus] == 'Q')
		Win = 1;
   }
   for (int checkcolminus = col - 1; checkcolminus >= 0; checkcolminus--)
   {
	if (board[row][checkcolminus] == 'Q')
		Win = 1;
   }
   for (int checkdiagonal = 1; checkdiagonal <= 8; checkdiagonal++)
   {
   	if (board[row + checkdiagonal][col + checkdiagonal] == 'Q')
   		Win = 1;
   	if (board[row - checkdiagonal][col + checkdiagonal] == 'Q')
   		Win = 1;
   	if (board[row + checkdiagonal][col - checkdiagonal] == 'Q')
   		Win = 1;
   	if (board[row - checkdiagonal][col - checkdiagonal] == 'Q')
   		Win = 1;
   }
}
}
   if (turns % 2 == 1)
	cout << "Player 2 Wins!!!" << endl;
   else
	cout << "Player 1 Wins!!!" << endl;

   return 0;
}
