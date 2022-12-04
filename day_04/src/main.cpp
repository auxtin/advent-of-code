#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

void problem1()
{
    /*
        set1 - holdsthe unique chars from the first half
        finalset - holds the final set of cjars
    */
    vector<int> res;
    int count = 0;
    ifstream inp("../src/input.txt");
    // ifstream inp("../src/example-input.txt");
    if (inp.is_open())
    {
        string currline, curr;
        int i = 0;
        while (getline(inp, currline))
        {
            // cout << currline << endl;
            stringstream ss(currline);
            replace(currline.begin(), currline.end(), '-', ',');
            size_t pos = 0;
            std::string token;
            while ((pos = currline.find(",")) != std::string::npos)
            {
                token = currline.substr(0, pos);
                // std::cout << token << std::endl;
                res.push_back(stoi(token));
                currline.erase(0, pos + 1);
            }
            // while (getline(ss, curr, ','))
            // {

            //     res.push_back(stoi(curr));
            // }
        }

        inp.close();
    }
    else
    {
        cout << "Couldn't open file\n";
    }
    cout << endl
         << res.size() << endl;
    for (int i = 0; i < res.size(); i = i + 4)
    {
        int num1 = res[i],
            num2 = res[i + 1],
            num3 = res[i + 2],
            num4 = res[i + 3];
        if (
            ((num1 >= num3 && num1 <= num4) && (num2 >= num3 && num2 <= num4)) ||
            ((num3 >= num1 && num3 <= num2) && (num4 >= num1 && num4 <= num2)))
        {
            cout << num1 << "," << num2 << "," << num3 << "," << num4 << "\n";
            count++;
        }
    }

    cout << "The answer to problem 1 is: " << count << endl;
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
    return 0;
}