#include <iostream>

using namespace std;

char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

// set player names
void setPlayerNames(string &pX, string &pO)
{
    cout << "Enter name of Player-X : ";
    getline(cin, pX);

    cout << "Enter name of Player-O : ";
    getline(cin, pO);
}

// check if the position is already filled with either 'X' or 'O'
bool isPositionAlreadyFilled(int posNum)
{
    if (board[posNum - 1] == 'X' || board[posNum - 1] == 'O')
        return true;
    return false;
}

// check if the position entered is valid or not
bool isValidPosition(int posNum)
{
    if (posNum == 1 || posNum == 2 || posNum == 3 || posNum == 4 || posNum == 5 || posNum == 6 || posNum == 7 || posNum == 8 || posNum == 9)
    {
        if (!isPositionAlreadyFilled(posNum))
            return true;
    }

    return false;
}

// display board after every move
void displayBoard()
{
    cout << "________________" << '\n';
    cout << board[0] << "   |  " << board[1] << "   |  " << board[2] << '\n';
    cout << "____|______|____" << '\n';
    cout << board[3] << "   |  " << board[4] << "   |  " << board[5] << '\n';
    cout << "____|______|____" << '\n';
    cout << board[6] << "   |  " << board[7] << "   |  " << board[8] << '\n';
    cout << "____|______|____" << '\n';
}

// check if there's a potential winner
bool isWinner()
{
    // row winner
    if ((board[0] == 'X' && board[1] == 'X' && board[2] == 'X') || (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') || (board[6] == 'X' && board[7] == 'X' && board[8] == 'X'))
    {
        return true;
    }
    else if ((board[0] == 'O' && board[1] == 'O' && board[2] == 'O') || (board[3] == 'O' && board[4] == 'O' && board[5] == 'O') || (board[6] == 'O' && board[7] == 'O' && board[8] == 'O'))
    {
        return true;
    }

    // column winner
    else if ((board[0] == 'X' && board[3] == 'X' && board[6] == 'X') || (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') || (board[2] == 'X' && board[5] == 'X' && board[8] == 'X'))
    {
        return true;
    }
    else if ((board[0] == 'O' && board[3] == 'O' && board[6] == 'O') || (board[1] == 'O' && board[4] == 'O' && board[7] == 'O') || (board[2] == 'O' && board[5] == 'O' && board[8] == 'O'))
    {
        return true;
    }

    // diagonal winner
    else if ((board[0] == 'X' && board[4] == 'X' && board[8] == 'X') || (board[2] == 'X' && board[4] == 'X' && board[6] == 'X'))
    {
        return true;
    }
    else if ((board[0] == 'O' && board[4] == 'O' && board[8] == 'O') || (board[2] == 'O' && board[4] == 'O' && board[6] == 'O'))
    {
        return true;
    }

    return false;
}

// check if the game ties
bool isTie()
{
    for (int i = 0; i < 9; ++i)
    {
        if (board[i] != 'X' && board[i] != 'O')
            return false;
    }

    return true;
}

char takeCurrentPlayerPositionNumber(char &currPlayer)
{
    char winner = ' ';

    cout << '\n'
         << "Player-" << currPlayer << "'s turn." << '\n';
    cout << "Enter position number(1 - 9) : ";

    int positionNumber{};
    cin >> positionNumber;

    if (!isValidPosition(positionNumber))
    {
        cout << "\n\n"
             << "The position entered is invalid. Please enter a valid position."
             << "\n\n";
        displayBoard();
        takeCurrentPlayerPositionNumber(currPlayer);
    }
    else
    {
        // 1. update Board
        board[positionNumber - 1] = currPlayer;

        // 2. display current board
        cout << '\n';
        displayBoard();

        // 3. check if there's a winner or a tie
        if (!isWinner())
        {
            // 4. if not a winner or a tie and game not over then continue
            if (!isTie())
            {
                currPlayer == 'X' ? currPlayer = 'O' : currPlayer = 'X';
                takeCurrentPlayerPositionNumber(currPlayer);
            }
            else
                currPlayer = ' ';
        }

        return currPlayer;
    }
}

int main()
{
    std::cout << "**************************** TIC - TAC - TOE ****************************"
              << "\n\n";

    // Display starting board
    displayBoard();

    cout << "\n\n";

    // Ask usernames of player-X and player-O
    string playerNameX{}, playerNameO{};
    setPlayerNames(playerNameX, playerNameO);

    cout << "\n"
         << "The Game Begins. " << playerNameX << " will have to move first." << '\n';
    cout << "Please choose a number between 1-9 for your position as displayed in the board."
         << "\n\n";

    char currentPlayer{'X'};

    char result = takeCurrentPlayerPositionNumber(currentPlayer);

    if (result == 'X')
    {
        cout << "\n\n"
             << "The winner is Player - X : " << playerNameX << "\n\n";
    }
    else if (result == 'O')
    {
        cout << "\n\n"
             << "The winner is Player - O : " << playerNameO << "\n\n";
    }
    else
    {
        cout << "\n\n"
             << "The game TIED. No one wins."
             << "\n\n";
    }

    return 0;
}