#include <iostream>
#include <Windows.h>
using namespace std;

void GetLine(char* s, int size);
int Power(int a, int b);

int StringLength(const char *s);	//возвращает длину строки
void ToUpper(char *s);		//переводит строку в верхний регистр
void ToLower(char *s);		//переводит строку в нижний регистр

void shrink(char *s);	//Выводит строку без лишних пробелов
						//Хорошо      живет     на     свете      Винни      Пух
						//Хорошо живет на свете Винни Пух

bool is_palindrome(char *s);	//Проверяет, является ли строка палиндромом

bool is_int_number(char *s);	//Проверяет, является ли строка целым десятичным числом
int to_int_number(char *s);//Если строка является целым десятичным числом, возвращает ее числовое значение
bool is_bin_number(char *s);	//Проверяет, является ли строка двоичным числом
int bin_to_dec(char *s);	//Если строка является двоичным числом, возвращает ее десятичное значение
bool is_hex_number(const char *s);	//Проверяет, является ли строка шестнадцатеричным числом
int hex_to_dec(const char *s);	//Если строка является шестнадцатеричным числом, возвращает ее десятичное значение

bool isIPaddress(const char *s);	//Проверяет, является ли строка IP-адресом
bool isMACaddress(const char *s);	//Проверяет, является ли строка MAC-адресом

#define SIZE 256

void main()
{
	setlocale(LC_ALL, "");
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 }; Для извращенцев
	//char str[] = "Hello"; // Так нормально

	char str[SIZE] = {};
/*	cout << "Введите строку: ";
	//cin >> str;
	GetLine(str, SIZE);
	cout << endl << str << endl;

	cout << "Длина строки: " << StringLength(str) << endl;
	
	ToUpper(str);
	cout << "Строка в верхнем регистре: " << str << endl;

	ToLower(str);
	cout << "Строка в нижнем регистре: " << str << endl;

	cout << "Введите строку с лишними пробелами, мы их удалим: ";
	GetLine(str, SIZE);

	cout << endl << "Удалили лишние пробелы:" << endl;
	shrink(str);

	cout << endl << "Введите строку, проверка на палиндром: ";
	GetLine(str, SIZE);

	cout << str << (is_palindrome(str) ? " Палиндром" : " Не палиндром") << endl;

	cout << endl << "Введите строку, для перевода в десятичное число если это возможно: ";
	GetLine(str, SIZE);

	cout << str << ": " << to_int_number(str) << endl;

	cout << endl << "Введите строку для перевода из двоичного формата в десятичный: ";
	GetLine(str, SIZE);

	cout << str << ": " << (is_bin_number(str) ? bin_to_dec(str) : -1) << endl;
	*/
	cout << endl << "Введите строку в шестнадцатиричном формате: "; GetLine(str, SIZE);
	cout << endl << str << ": " << hex_to_dec(str) << endl;
	cout << endl << "Введите IP адрес: "; GetLine(str, SIZE);
	
	cout << endl << str << (isIPaddress(str) ? " корректный" : " не корректный") << " IP адрес" << endl;

	cout << endl << "Введите MAC адрес: "; GetLine(str, SIZE);
	cout << endl << str << (isMACaddress(str) ? " корректный" : " не корректный") << " MAC адрес" << endl;



}

void GetLine(char* s, int size)
{
	SetConsoleCP(1251);
	cin.getline(s, size);
	SetConsoleCP(866);
}

int Power(int a, int b)
{
	int power;
	if (b == 0) power = 1;
	else power = a * Power(a, b - 1);
	return power;

}

int StringLength(const char* s)
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
		if (*(s + i) <= 'z' && *(s + i) >= 'a') *(s + i) = *(s + i) - 32;
		if (*(s + i) <= 'я' && *(s + i) >= 'а') *(s + i) = *(s + i) - 32;
		if (*(s + i) == 'ё') *(s + i) = 'Ё';
		i++;
	}
}

void ToLower(char* s)
{
	int i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) <= 'Z' && *(s + i) >= 'A') *(s + i) = *(s + i) + 32;
		if (*(s + i) <= 'Я' && *(s + i) >= 'А') *(s + i) = *(s + i) + 32;
		if (*(s + i) == 'Ё') *(s + i) = 'ё';
		i++;
	}
}

void shrink(char* s)	//Выводит строку без лишних пробелов
{
	while (*s != '\0')
	{

		if (*s != ' ')
		{
			cout << *s;
		}
		else if (*s == ' ')
		{
			while (*s == ' ')
			{
				s++;
			}
			cout << " ";
			s--;
		}
		s++;
	}

}

bool is_palindrome(char* s)	//Проверяет, является ли строка палиндромом
{
	bool flag = true;
	
	int len_s = StringLength(s);
		
	for (int i = 0; i < len_s / 2 + 1; i++)
	{
		if (*(s + i) != *(s + len_s - 1 - i))
		{
			flag = false;
			break;
		}
	}
	return flag;
}

bool is_int_number(char* s)	//Проверяет, является ли строка целым десятичным числом
{
	bool flag = true;
	int i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) < '0' || *(s + i) > '9')
		{
			flag = false;
			break;
		}
		i++;
	}
	return flag;
}
int to_int_number(char* s)	//Если строка является целым десятичным числом, возвращает ее числовое значение
{
	int number = 0;
	int len_s = StringLength(s);
	int i = 0;
	if (is_int_number(s))
	{
		while (*s != '\0')
		{
			number += (*s - '0') * Power(10, len_s - 1 - i);
			i++;
			s++;
		}
	}
	return number;
}
bool is_bin_number(char* s)	//Проверяет, является ли строка двоичным числом
{
	bool flag = true;
	
	while (*s != '\0')
	{
		if (*s != '0' && *s != '1')
		{
			flag = false;
			break;
		}
		s++;
	}
	return flag;
}
int bin_to_dec(char* s)	//Если строка является двоичным числом, возвращает ее десятичное значение
{
	int number = 0;
	int len_s = StringLength(s);
	int i = 0;
	if (is_bin_number(s))
	{
		while (*s != '\0')
		{
			number += (*s - '0') * Power(2, len_s - 1 - i);
			
			i++;
			s++;
		}
	}
	return number;
}
bool is_hex_number(const char* s)	//Проверяет, является ли строка шестнадцатеричным числом
{
	bool flag = true;
	int i = 0;
	while (*(s + i) != '\0')
	{
		if (!(*(s + i) >= '0' && *(s + i) <= '9' || *(s + i) >= 'A' && *(s + i) <= 'F' || *(s + i) >= 'a' && *(s + i) <= 'f'))
		{
			flag = false;
			break;
		}
		i++;
	}
	return flag;
}
int hex_to_dec(const char* s)	//Если строка является шестнадцатеричным числом, возвращает ее десятичное значение
{
	if (!is_hex_number(s)) return 0;
	int number = 0;

	while (*s)
	{
		int el;
		if (*s >= '0' && *s <= '9') el = *s - '0';
		else if	(*s >= 'a' && *s <= 'f') el = 10 + (*s - 'a');
		else if	(*s >= 'A' && *s <= 'F') el = 10 + (*s - 'A');

		number = number * 16 + el;
		s++;
	}
	return number;
}

bool isIPaddress(const char* s)	//Проверяет, является ли строка IP-адресом
{
	int len_s = StringLength(s);

	if (len_s < 7 || len_s > 15) return false;
	
	int count_sep = 0;
	int num_el = 0;
	int triad = 0;
	while (*s)
	{
		if (isdigit(*s))
		{
			triad = triad * 10 + (*s - '0');
			num_el++;
			if (triad > 255 || num_el > 3) return false;
		}
		else if (*s == '.')
		{
			if (num_el == 0) return false;

			triad = 0;
			num_el = 0;
			count_sep++;

			if (count_sep > 3) return false;
		}
		else return false;
		s++;
	}

	if (count_sep != 3 || num_el == 0) return false;

	return true;
}
bool isMACaddress(const char* s)	//Проверяет, является ли строка MAC-адресом
{
	int len_s = StringLength(s);
	int octet = 0;
	if (len_s != 17) return false;
	for (int i = 0; i < len_s; i++)
	{
		if (i % 3 == 2)
		{
			if (s[i] != ':' && s[i] != '-') return false;
			octet = 0;
		}
		else
		{
			int el;
			if (s[i] >= '0' && s[i] <= '9') el = s[i] - '0';
			else if (s[i] >= 'a' && s[i] <= 'f') el = 10 + (s[i] - 'a');
			else if (s[i] >= 'A' && s[i] <= 'F') el = 10 + (s[i] - 'A');
			else return false;

			octet = octet * 16 + el;

			if (octet > 255) return false;
		}
	}
	return true;
}

