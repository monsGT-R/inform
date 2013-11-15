#include <iostream>
#include <ctime>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	const int N = 10; // Размер массива.
	float mas[N];
	srand(time(0));
	cout << "Сформированный массив: ";
	for (int i = 0; i < N; i++) // Ввод массива.
	{
		mas[i] = float(rand() % 1000 - 500) / 100;
		cout << mas[i] << " ";
	}
	cout << endl;

	// a) найти сумму положительных эл-тов массива.
	float sum = 0;
	for (int i = 0; i < N; i++) 
	{
		if (mas[i] > 0) sum += mas[i];
	}
	cout << "Сумма положительных элементов = " << sum << endl;

	// б) вычислить количество элементов, больше 1'го положительного эл-та.
	float firstPositive = 0;
	int index;
	for (int i = 0; i < N - 1; i++) // Находим 1'ый положительный
	{
		if (mas[i] > 0)
		{
			firstPositive = mas[i];
			index = i + 1; // сохраняем номер следующего элемента.
			break;
		}
	}
	if (firstPositive == 0) cout << "Во всем массиве нету положительных элементов!!!" << endl;
	else
	{
		int count = 0;
		for (int i = index; i < N; i++) // начинаем цикл с 1'го положительного эл-та
		{
			if (mas[i] > firstPositive) count++;
		}
		cout << "Количество элементов, больше 1'го положительного эл-та = " << count << endl;
	}

	// в) найти произведение эл-тов, между 1'ым и 2'ым отрицательными эл-тами.
	float multiplication = 1;
	float firstNegative = 0, secondNegative = 0;
	for (int i = 0; i < N - 1; i++) // Находим 1'ый отрицательный эл-т
	{
		if (mas[i] < 0)
		{
			firstNegative = mas[i];
			index = i + 1;
			break;
		}
	}
	if (firstNegative == 0) cout << "Во всем массиве нету отрицательных элементов!!!" << endl;
	else
	{
		for (int i = index; i < N; i++) // Начинаем цикл с 1'го эл-та. Находим 2'ой отриц. эл-т.
		{
			if (mas[i] < 0) {
				secondNegative = mas[i];
				break;
			}
			multiplication *= mas[i]; // Умножаем эл-ты массива, между 1'ым и 2'ым отриц. эл-тами.
		}
		if (secondNegative == 0) cout << "Во всем массиве нету 2'го отрицательного элемента!" << endl;
		else cout << "Произведение эл-тов, между 1'ым и 2'ым отрицательными эл-тами = " << multiplication << endl;
	}

	// г) сформировать из положительных элементов массива второй массив и распечатать.
	float mas2[N];
	index = 0;
	for (int i = 0; i < N; i++)
	{
		if (mas[i] > 0)
		{
			mas2[index] = mas[i];
			index++;
		}
	}
	cout << "Второй массив: ";
	for (int i = 0; i < index; i++)
	{
		cout << mas2[i] << " ";
	}
	cout << endl;
}
