#include <iostream>
#include <ctime>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	const int length = 5; // Размерность
	int matr[length][length];
	srand(unsigned(time(0)));

	cout << char(25) << char(25) << " Матрица " << char(25) << char(25) << endl;
	//---[Random Ввод и вывод матрицы]-------------
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			matr[i][j] = rand() % 10-5;
			//cin >> matr[i][j];
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	//---------------------------------------------
	cout << char(25) << char(25) << " Сумма отриц. нечетных столбцов\n";
	int sum[length]{};
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j += 2) {
			if (matr[j][i] < 0) {
				sum[i] += matr[j][i];
			}
		}
		cout << sum[i] << " ";
	}
	cout << endl << endl;
	// Сортировка выбором
	for (int i = 0; i < length; i++) {
		int tmp = sum[i];
		int pos = i;
		for (int j = i + 1; j < length; j++){
			// цикл выбора наибольшего элемента. a[j] - следующий элемент
			if (sum[j] < tmp) {
				tmp = sum[j]; // Запоминаем наибольший элемент.
				pos = j; // Запоминаем позицию наибольшего эл-та.
			}
		}
		if (pos != i) {  // Для быстродействия
			sum[pos] = sum[i]; // меняем местами наименьший с a[i].
			sum[i] = tmp;
			for (int j = 0; j < length; j++) {
				tmp = matr[j][i];
				matr[j][i] = matr[j][pos];
				matr[j][pos] = tmp;
			}
		}
	}
	cout << char(25) << char(25) << " Новая матрица " << char(25) << char(25) << endl;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			cout << matr[i][j] << "  ";
		}
		cout << endl;
	}
}
