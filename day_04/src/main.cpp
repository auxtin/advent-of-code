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
            ((num1 >= num3 && num1 <= num4) || (num2 >= num3 && num2 <= num4)) ||
            ((num3 >= num1 && num3 <= num2) || (num4 >= num1 && num4 <= num2)))
        {
            cout << num1 << "," << num2 << "," << num3 << "," << num4 << "\n";
            count++;
        }
    }

    cout << "The answer to problem 2 is: " << count << endl;
}

int main(int argc, char **pArgv)
{
    // problem1();
    problem2();
    return 0;
}