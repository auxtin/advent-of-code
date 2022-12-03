#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <unordered_set>
#include <vector>
using namespace std;

int main(int argc, char **pArgv)
{
    /*
        set1 - holdsthe unique chars from the first half
        finalset - holds the final set of cjars
    */
    unordered_set<char> set1;
    vector<char> final;
    ifstream inp("../src/input.txt");
    // ifstream inp("../src/example-input.txt");
    if (inp.is_open())
    {
        string currline;
        while (getline(inp, currline))
        {
            // cout << currline << endl;
            // cout << "----------\n";
            int mid = currline.size() / 2;
            for (int i = 0; i < mid; ++i)
            {
                // cout << currline[i];
                set1.insert(currline[i]);
            }
            // cout << " | ";
            char dup;
            for (int i = mid; i < currline.size(); ++i)
            {
                // cout << currline[i];
                if (set1.find(currline[i]) != set1.end())
                {
                    // cout << "The character is: " << currline[i] << endl;
                    // finalset.insert(currline[i]);
                    dup = currline[i];
                }
            }
            final.push_back(dup);
            // cout << "\n";
            set1.clear();
        }
        inp.close();
    }
    else
    {
        cout << "Couldn't open file\n";
    }
    // sum up point values
    int res = 0;
    for (char c : final)
    {
        // if (islower(c))
        // {
        //     cout << (c - 'a' + 1) << ",";
        // }
        // else
        // {
        //     cout << (c - 'A' + 27) << ",";
        // }
        if (islower(c))
        {
            res += (c - 'a' + 1);
        }
        else
        {
            res += (c - 'A' + 27);
        }
    }

    cout << "The answer for part 1 is: " << res << endl;
    return 0;
}