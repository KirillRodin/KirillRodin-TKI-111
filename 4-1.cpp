#include <iostream>
#include <cstdlib>

using namespace std;

// Вывод массива
// iSize - размер массива
// piArray - указатель на массив
void vGetArray(int iSize, int* piArray) {
	cout << "Итоговый массив: ";
	for (int i = 0; i < iSize; i++) {
		cout << piArray[i] << " ";
	}
	cout << endl;
}

// Заполнение массива
void vSetArray(int iSize, int* piArray) {

	int iChoice = 0;
	cout << "Заполнение массива" << endl
		 << "1 - Ввести значения вручную" << endl
		 << "2 - Заполнить массив случайными числами" << endl;
	cin >> iChoice;
	while (iChoice < 1 || iChoice > 2) { // Если введено неверное число
		cin >> iChoice;
	}
	
	// Заполнение вручную
	if (iChoice == 1) {
		cout << "Введите значения в диапазоне [-10;10]:" << endl;
		for (int i = 0; i < iSize; i++) {

			int iValue = -11;
			cin >> iValue;

			// Если введено значение вне диапазона
			while (iValue < -10 || iValue > 10) {
				cout << "Введите значение в диапазоне [-10;10]" << endl;
				cin >> iValue;
			}

			piArray[i] = iValue;
		}
	}

	// Заполнение случайными числами
	else if (iChoice == 2) {
    srand(time(NULL));
		for (int i = 0; i < iSize; i++) {
			piArray[i] = rand() % 21 - 10;
		}
	}

	vGetArray(iSize, piArray);
}

// Сумма элементов, имеющих нечетное значение
// iSize - размер массива
// piArray - указатель на массив
void vSum(int iSize, int* piArray) {
	int iSum = 0;
	for (int i = 0; i < iSize; i++) {
		if (piArray[i] % 2) { // Если число - нечетное (остаток от деления = 1)
			iSum += piArray[i];
		}
	}
	cout << "Сумма = " << iSum << endl;
}

// Вывести индексы элементов, значение которых меньше А
void vIndex(int iSize, int* piArray) {

	int iA = 0;
	cout << "Введите число А:" << endl;
	cin >> iA;
	cout << "Индексы: ";

	for (int i = 0; i < iSize; i++) {
		if (piArray[i] < iA) {
			cout << i << " ";
		}
	}
	cout << endl;
}

// Заменить второй элемент массива на максимальный среди отрицательных
void vReplace(int iSize, int* piArray) {

	int iValue = -11;
	// Поиск максимального отрицательного элемента
	for (int i = 0; i < iSize; i++) {
		if (piArray[i] < 0 && piArray[i] > iValue) {
			iValue = piArray[i];
		}
	}

	// Замена
	if (iValue != -11) {
		piArray[2] = iValue;
	}
	else {
		cout << "В массиве отсутствуют отрицательные элементы" << endl;
	}

	vGetArray(iSize, piArray);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	// Переменная управления
	int iMenu = 0;

	// Размерность массива
	int iSize = 0;

	cout << "Введите размерность массива:" << endl;
	cin >> iSize;

	int* piArray = new int[iSize];
	vSetArray(iSize, piArray);

	while (iMenu != 4) {

		cout << "1 - Сумма элементов, имеющих нечетное значение" << endl
			 << "2 - Вывести индексы элементов, значение которых меньше А" << endl
			 << "3 - Заменить второй элемент массива на максимальный среди отрицательных" << endl
			 << "4 - Выход" << endl;

		cin >> iMenu;
		while (iMenu < 1 || iMenu > 4) { // Если введено неверное число
			cin >> iMenu;
		}

		switch (iMenu) {
			case 1: {
				vSum(iSize, piArray);
				break;
			}
			case 2: {
				vIndex(iSize, piArray);
				break;
			}
			case 3: {
				vReplace(iSize, piArray);
				break;
			}
			case 4: {
				break;
			}
		}
	}

	delete[] piArray;
	return 0;
}