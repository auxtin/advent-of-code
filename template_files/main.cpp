#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char **pArgv)
{
    ifstream inp("../src/input.txt");
    if (inp.is_open())
    {
        string currline;
        while (getline(inp, currline))
        {
            cout << currline << "\n";
        }
        inp.close();
    }
    else
    {
        cout << "Couldn't open file\n";
    }

    return 0;
}