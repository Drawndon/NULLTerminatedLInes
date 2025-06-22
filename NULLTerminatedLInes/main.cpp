#include <iostream>
#include <Windows.h>
using namespace std;

int StringLength(char *s);	//возвращает длину строки
void ToUpper(char *s);		//переводит строку в верхний регистр
void ToLower(char *s);		//переводит строку в нижний регистр

void shrink(char *s);		//Удаляет лишние пробелы из предложения
						//Хорошо      живет     на     свете      Винни      Пух
						//Хорошо живет на свете Винни Пух

bool is_palindrome(char *s);	//Проверяет, является ли строка палиндромом

bool is_int_number(char *s);	//Проверяет, является ли строка целым десятичным числом
void to_int_number(char *s);//Если строка является целым десятичным числом, возвращает ее числовое значение
bool is_bin_number(char *s);	//Проверяет, является ли строка двоичным числом
void bin_to_dec(char *s);	//Если строка является двоичным числом, возвращает ее десятичное значение
bool is_hex_number(char *s);	//Проверяет, является ли строка шестнадцатеричным числом
void hex_to_dec(char *s);	//Если строка является шестнадцатеричным числом, возвращает ее десятичное значение


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
	cout << "Длина строки: " << StringLength(str) << endl;
}

int StringLength(char* s)
{
	int i = 0;
	while (*(s + i) != '\0') i++;
	return i;
}

void ToUpper(char* s)
{
	int i = 0;
	while (*(s + i) != '\0')
	{
		i++;
	}
}