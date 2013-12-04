#include <iostream>
#include <ctime>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	const int length = 3; // Размерность
	int	matr[length][length];
	srand(unsigned(time(0)));

	//---[Random Ввод и вывод матрицы]-------------
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			matr[i][j] = rand() % 10;
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
	//---------------------------------------------

	//---[Вывод седловых индексов матрицы]---------
	bool flagMin = true, flagMax = true;
	int min, max, minJ, maxJ, minI, maxI;
	cout << "Седловые точки: ";
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			// Ищем в каждой строке минимальную и максимальную ячейку и сохраняем индексы.
			if (j == 0 || matr[i][j] < min) {
				min = matr[i][j];
				minJ = j;
				minI = i;
			}
			if (j == 0 || matr[i][j] > max) {
				max = matr[i][j];
				maxJ = j;
				maxI = i;
			}
		}
		for (int k = 0; k < length; k++) {
			// Мин. элемент в строке проверяем, является ли он максимальным в столбце, максимальный наоборот.
			if (min < matr[k][minJ]) flagMin = false;
			if (max > matr[k][maxJ]) flagMax = false;
		}
		// Если все хорошо выводим индексы седловых элементов.
		if (flagMin) cout << "(" << minI << ", " << minJ << ") ";
		if (flagMax) cout << "(" << maxI << ", " << maxJ << ") ";
	}
}
