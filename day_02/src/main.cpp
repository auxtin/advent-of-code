#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <unordered_map>
using namespace std;

/*
    1: win
    0: draw
    -1: lose
*/
int roundWon(char &p1, char &p2)
{
    // rock, paper, scissors
    // A,B,C
    // X,Y,Z
    int res;
    if ((p2 == 'X' && p1 == 'A') ||
        (p2 == 'Y' && p1 == 'B') ||
        (p2 == 'Z' && p1 == 'C'))
    {
        res = 0;
    }
    else if ((p2 == 'X' && p1 == 'C') ||
             (p2 == 'Y' && p1 == 'A') ||
             (p2 == 'Z' && p1 == 'B'))
    {
        res = 1;
    }
    else
    {
        res = -1;
    }
    return res;
}

char counter(char c)
{
    if (c == 'A')
    {
        return 'Y';
    }
    else if (c == 'B')
    {
        return 'X';
    }
    return 'Z';
}

unordered_map<char, int> points_hm = {
    // what you chose
    {'X', 1},
    {'Y', 2},
    {'Z', 3},
    // outcome
    {'D', 3},
    {'L', 0},
    {'W', 6}};
unordered_map<char, int> points_hm_pt2 = {
    // lose, draw, win
    {'X', 0},
    {'Y', 3},
    {'Z', 6},
    // outcome
    {'D', 3},
    {'L', 0},
    {'W', 6}};

int main(int argc, char **pArgv)
{
    int total = 0, total_p2 = 0;
    // ifstream inp("../src/input.txt");
    ifstream inp("../src/example-input.txt");
    if (inp.is_open())
    {
        string currline;
        int round = 1, outcome;
        while (getline(inp, currline))
        {
            char opp = currline[0], me = currline[2];
            cout << "Round " << round++ << ": ";
            outcome = roundWon(opp, me);

            if (outcome == 1)
            {
                total += points_hm[me] + 6;
            }
            else if (outcome == 0)
            {
                total += points_hm[me] + 3;
            }
            else
            {
                total += points_hm[me];
            }
            cout << points_hm[me] << endl;
        }
        inp.close();
    }
    else
    {
        cout << "Couldn't open file\n";
    }

    cout << "Part 1 - Score for current strategy: " << total << endl;
    return 0;
}