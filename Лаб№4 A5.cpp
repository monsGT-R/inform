#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	char a = 'a', // Иницилизируем a = 'a' как начальная буква.
	     b = 'a'; // и b = 'a' как начальная буква.
	bool isOrder = true;// Предполагаем что порядок верный.
	cout << "Введите буквы: ";
	while (a != '0') // Цикл выполняестя пока не введем 0
	{
		if (a < b) {
			isOrder = false; // Порядок не верный.
		}
		b = a;
		cin >> a; // Обновляем a.
	}
	if (isOrder) { // Если порядок верный.
		cout << "Буквы расположены по порядку." << endl;
	} else {
		cout << "Буквы расположены НЕ по порядку." << endl;
	}
}
