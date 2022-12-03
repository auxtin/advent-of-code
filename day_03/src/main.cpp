#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <unordered_set>
#include <vector>
using namespace std;

void problem1()
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
}

void problem2()
{
    vector<char> badges;
    unordered_set<char> set1_pt2, set2_pt2;
    ifstream inp("../src/input.txt");
    // ifstream inp("../src/example-input.txt");
    if (inp.is_open())
    {
        int elf = 1;
        char badge;
        string currline;
        while (getline(inp, currline))
        {
            // cout << currline << endl;
            for (int i = 0; i < currline.size(); ++i)
            {

                if (elf == 1)
                {
                    set1_pt2.insert(currline[i]);
                }
                else if (elf == 2)
                {
                    set2_pt2.insert(currline[i]);
                }
                else if (elf == 3)
                {
                    // cout << "---------";
                    if ((set1_pt2.find(currline[i]) != set1_pt2.end()) and
                        set2_pt2.find(currline[i]) != set2_pt2.end())
                    {
                        badges.push_back(currline[i]);
                        elf = 0;
                        set1_pt2.clear();
                        set2_pt2.clear();
                    }
                }
            }
            elf++;
        }
        inp.close();
    }
    else
    {
        cout << "Couldn't open file\n";
    }
    // sum up point values
    int res = 0;
    for (char c : badges)
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

    cout << "The answer for part 2 is: " << res << endl;
}

int main(int argc, char **pArgv)
{
    problem1();
    problem2();
    return 0;
}