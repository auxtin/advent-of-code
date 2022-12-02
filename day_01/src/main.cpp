#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <queue>
using namespace std;

int main(int argc, char **pArgv)
{
    priority_queue<int> pq;
    ifstream inp("../src/input.txt");
    if (inp.is_open())
    {
        string currline;
        int currSum = 0, elf = 1;
        while (getline(inp, currline))
        {
            if (currline == "")
            {
                cout << "Elf #" << elf++ << " has " << currSum << " calories\n";
                pq.push(currSum);
                currSum = 0;
            }
            else
            {
                currSum += stoi(currline);
            }
        }
        inp.close();
    }
    else
    {
        cout << "Couldn't open file\n";
    }

    // debugging first answer works
    // while (!pq.empty())
    // {
    //     cout << pq.top() << endl;
    //     pq.pop();
    // }

    // return max calories held by an elf
    cout << "\nAnswer to part 1, the sum of the top elf's calories: " << pq.top() << "\n";
    int ans2 = 0, n = 3;
    while (n-- > 0)
    {
        ans2 += pq.top();
        pq.pop();
    }
    cout << "Answer to part 2, the sum of the top three elf's calories: " << ans2 << "\n";

    return 0;
}