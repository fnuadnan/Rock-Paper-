#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

char Group_Strategy(int round, char prevAns, char outcome) { // If you win then you choose what the opponent just played, If you lost then you choose what neither of you played, 
    if (round == 1 || outcome == 'T') { //If you Tie or it is the first round then you randomize and try again
        int num1 = (rand() % 3) + 1;

        if (num1 == 1) return 'R';
        if (num1 == 2) return 'P';
        if (num1 == 3) return 'S';
    }
    else
    {
        if (outcome == 'L') {// chooses what neither of them played
            if (prevAns == 'R') return 'P';
            if (prevAns == 'P') return 'S';
            if (prevAns == 'S') return 'R';
        }

        if (outcome == 'W') {
            if (prevAns == 'R') return 'S'; //chooses what the opponent just played
            if (prevAns == 'P') return 'R';
            if (prevAns == 'S') return 'P';
        }
    }
}

char BigBadEvilCode(char prev1, char prev2) { 
//Delete existing code in this funciton and Insert New Code
    if (prev1 == prev2) 
    {
        if (prev2 == 'R')
        {
            return 'P';
        }
        if (prev2 == 'P')
        {
            return 'S';
        }
        if (prev2 == 'S')
        {
            return 'R';
        }
    }
    else
    {
        if((prev1 == 'R' && prev2 == 'S')||prev1 == 'S' && prev2 == 'R'))
        {
            return 'P'
        }
        if((prev1 == 'R' && prev2 == 'P')||prev1 == 'P' && prev2 == 'R'))
        {
            return 'S'
        }
        if((prev1 == 'P' && prev2 == 'S')||prev1 == 'S' && prev2 == 'P'))
        {
            return 'R'
        }
        
    }
   
}

void PrintResults(int P1win, int P2win, int rounds) {  // prints results
    int tied = rounds - (P1win + P2win);
    double WinP = ((double)P1win / (double)rounds) * 100.0;
    double LoseP = (double)((double)P2win / (double)rounds) * 100.0;
    double TieP = ((double)tied / (double)rounds) * 100.0;

    cout << "Rounds Played: " << rounds << endl;
    cout << "Win:  " << P1win << " (" << WinP << "%)" << endl;
    cout << "Tie:  " << tied << " (" << TieP << "%)" << endl;
    cout << "Lose: " << P2win << " (" << LoseP << "%)" << endl;
    cout << endl;
}

int main()
{
    char prevAnswer1 = ' ';
    char prevAnswer2 = ' ';
    char prevAnswer3 = 'y';
    char outcome = ' ', player2, player1;
    int rounds, print, P1win = 0, P2win = 0;

    cout << "How many rounds of Rock, Paper, Scissors would you like to play?" << endl;
    cin >> rounds;

    cout << "After how many rounds would you want the results to be printed" << endl;
    cin >> print;

    for (int i = 1; i <= rounds; i++) {

        player2 = BigBadEvilCode(prevAnswer2, prevAnswer3);
        player1 = Group_Strategy(i, prevAnswer1, outcome);

        cout << player2 << endl;
        cout << player1 << endl;

        if (player1 == 'R' && player2 == 'P') {  // compares the answers of the two players
            outcome = 'L'; // adjust outcome for Player 1 strategy
            P2win++;  // increments 1 for the player that wins
        }
        else if (player1 == 'R' && player2 == 'S') {
            outcome = 'W';
            P1win++;
        }
        else if (player1 == 'P' && player2 == 'S') {
            outcome = 'L';
            P2win++;
        }
        else if (player1 == 'P' && player2 == 'R') {
            outcome = 'W';
            P1win++;
        }
        else if (player1 == 'S' && player2 == 'R') {
            outcome = 'L';
            P2win++;
        }
        else if (player1 == 'S' && player2 == 'P') {
            outcome = 'W';
            P1win++;
        }
        else {
            outcome = 'T';
        }

        if (i % print == 0) { 
            PrintResults(P1win, P2win, i);
        }

        prevAnswer1 = player2;

        if (rounds % i == 0) {
            prevAnswer2 = player1;
        }
        else {
            prevAnswer3 = player1;
        }
        

        if (i == rounds) {
            int tied = rounds - (P1win + P2win);
            double TieP = ((double)tied / (double)rounds) * 100.0;

            double WinP, LoseP;
            string winner, loser;

            if (P1win >= P2win) {
                WinP = ((double)P1win / (double)rounds) * 100.0;
                LoseP = (double)((double)P2win / (double)rounds) * 100.0;
                winner = "Player 1";
                loser = "Player 2";
            }
            else if (P2win > P1win) {
                WinP = ((double)P2win / (double)rounds) * 100.0;
                LoseP = (double)((double)P1win / (double)rounds) * 100.0;
                winner = "Player 2";
                loser = "Player 1";
            }

            cout << "Final Resuls" << endl << endl;
            cout << "Winning Algorithm: " << winner << endl;
            cout << "Win Percentage:    " << "(" << WinP << "%)" << endl;
            cout << "Tie Percentage:    " << "(" << TieP << "%)" << endl << endl;

            cout << "Losing Algorithm: " << loser << endl;
            cout << "Win Percentage:    " << "(" << LoseP << "%)" << endl;
            cout << "Tie Percentage:    " << "(" << TieP << "%)" << endl << endl;

        }

    }
}
