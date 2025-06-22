#include <iostream>
#include <Windows.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 }; Для извращенцев
	//char str[] = "Hello"; // Так нормально
	const int SIZE = 20;
	char str[SIZE] = {};
	cout << "Введите строку: ";
	//cin >> str;
	SetConsoleCP(1251);
	cin.getline(str, SIZE);
	SetConsoleCP(866);
	cout << endl << str << endl;
}