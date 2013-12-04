#include <iostream>
#include <ctime>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	const int length = 5; // Размерность
	int	matr[length][length];
	srand(unsigned(time(0)));

	
	//---[Random Ввод и вывод матрицы]-------------
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			//matr[i][j] = rand() % 10;
			cin >> matr[i][j];
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
	//---------------------------------------------

	//---[Вывод седловых индексов матрицы]---------
	bool min, max;
	cout << "Седловые индексы точек: ";
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			// Ищем в каждой строке минимальную и максимальную ячейку и сохраняем индексы.
			min = max = true;
			for (int j1 = 0; j1 < length; j1++) {
				if (matr[i][j1] < matr[i][j]) min = false;
				if (matr[i][j1] > matr[i][j]) max = false;
			}
			if (min) {
				max = true;
				for (int i1 = 0; i1 < length; i1++)
					if (matr[i1][j] > matr[i][j]) max = false;
			}
			if (max) {
				min = true;
				for (int i1 = 0; i1 < length; i1++)
				if (matr[i1][j] < matr[i][j]) min = false;
			}
			if (min && max) cout << "(" << i << ", " << j << ") ";
		}
	}
}
