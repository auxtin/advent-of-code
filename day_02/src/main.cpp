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

char win(char c)
{
    // opp chooses rock, you choose paper
    if (c == 'A')
    {
        return 'Y';
    }
    // opp chooses paper, you choose scissors
    else if (c == 'B')
    {
        return 'Z';
    }
    // you go rock
    return 'X';
}

char lose(char c)
{
    // opp chooses rock, you scissors
    if (c == 'A')
    {
        return 'Z';
    }
    // opp chooses paper, you choose rock
    else if (c == 'B')
    {
        return 'X';
    }
    // you go paper
    return 'Y';
}
char draw(char c)
{
    // both go rock
    if (c == 'A')
    {
        return 'X';
    }
    // both go paper
    else if (c == 'B')
    {
        return 'Y';
    }
    // both go scissors
    return 'Z';
}

/*
    X - lose
    Y - draw
    Z - win
*/
string decision(char c)
{
    if (c == 'X')
    {
        return "lose";
    }
    else if (c == 'Y')
    {
        return "draw";
    }
    else
    {
        return "win";
    }
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

int main(int argc, char **pArgv)
{
    int total = 0, total_p2 = 0;
    ifstream inp("../src/input.txt");
    // ifstream inp("../src/example-input.txt");
    if (inp.is_open())
    {
        string currline;
        int round = 1, outcome;
        while (getline(inp, currline))
        {
            char opp = currline[0], me = currline[2];
            // cout << "Round " << round++ << ": ";
            outcome = roundWon(opp, me);
            if (outcome == 1)
            {
                total += points_hm[me] + 6;
            }
            else if (outcome == 0)
            {
                total += points_hm[me] + 3;
            }
            else if (outcome == -1)
            {
                total += points_hm[me];
            }
            // cout << points_hm[me] << endl;
            // cout << "You need to " << decision(me) << ". Choosing " << endl;
            if (decision(me) == "lose")
            {
                // cout << lose(opp) << endl;
                total_p2 += points_hm[lose(opp)] + 0;
                // cout << points_hm[lose(opp)] << " + "
                //  << "0" << endl;
            }
            else if (decision(me) == "draw")
            {
                // cout << draw(opp) << endl;
                total_p2 += points_hm[draw(opp)] + 3;
                // cout << points_hm[draw(opp)] << " + "
                //      << "3" << endl;
            }
            else if (decision(me) == "win")
            {
                // cout << win(opp) << endl;
                total_p2 += points_hm[win(opp)] + 6;
                // cout << points_hm[win(opp)] << " + "
                //      << "6" << endl;
            }
        }
        inp.close();
    }
    else
    {
        cout << "Couldn't open file\n";
    }
    cout << "Part 1 - Score for current strategy: " << total << endl;
    cout << "Part 2 - Score for ACTUAL strategy: " << total_p2 << endl;
    return 0;
}