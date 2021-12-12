#include <iostream>

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
	while (iChoice < 1 || iChoice > 2) {
		cin >> iChoice;
	}
	if (iChoice == 1) {
		cout << "Введите значения в диапазоне [-10;10]:" << endl;
		for (int i = 0; i < iSize; i++) {

			int iValue = -11;
			cin >> iValue;
			while (iValue < -10 || iValue > 10) {
				cout << "Введите значение в диапазоне [-10;10]" << endl;
				cin >> iValue;
			}
			piArray[i] = iValue;
          }
	}

	else if (iChoice == 2) {
	for (int i = 0; i < iSize; i++) {
	piArray[i] = rand() % 21 - 10;
	   }
	}
	vGetArray(iSize, piArray);
}
void vReplace(int iSize, int* piArray) {
	int iValue = -11;
	for (int i = 0; i < iSize; i++) {
	if (piArray[i] < 0 && piArray[i] > iValue) {
	iValue = piArray[i];
		}
	}

	// Замена на отрицательные элементы
	if (iValue != -11) {
	piArray[2] = iValue;
	}
	else {
		cout << "В массиве отсутствуют отрицательные элементы" << endl;
	     }

	vGetArray(iSize, piArray);
}

// Вставить число К перед всеми элементами, в которых есть цифра 1
// iSize - ссылка на размер массива
// piArray - ссылка на указатель на массив
void vPaste(int& iSize, int*& piArray) {

	int iK = 0;
	cout << "Введите число К:" << endl;
	cin >> iK;
	int iCount = 0;
	int* piIndexes = new int[iSize];

	for (int i = 0; i < iSize; i++) {

		bool bSign = false;
		int iValue = abs(piArray[i]);
		int iDigits = sizeof(iValue) / sizeof(int);
		for (int j = 0; j < iDigits; j++) {
			int iNum = pow(10, j);
			if (iValue / iNum == 1)
			{
				bSign = true;
				break;
			}
		}

		if (bSign) 
		{
			iCount += 1;
		}
		piIndexes[i] = i + iCount;
	}
	int iNewSize = piIndexes[iSize - 1] + 1;

	int* piNewArray = new int[iNewSize];
	for (int i = 0; i < iNewSize; i++) 
	{ 
		piNewArray[i] = iK;
	}

	for (int i = 0; i < iSize; i++) 
	{
		piNewArray[piIndexes[i]] = piArray[i];
	}

	delete[] piArray;
	piArray = piNewArray;
	iSize = iNewSize;

	vGetArray(iSize, piArray);
}

// Формирование массива А
void vInit(int iSize, int* piArray) {

	int* piNewArray = new int[iSize];
	for (int i = 0; i < iSize; i++) {
		if (i % 2) 
		{
			piNewArray[i] = piArray[i] / i;
		}
		else 
		{
			piNewArray[i] = pow(piArray[i], 2);
		}
	}

	vGetArray(iSize, piNewArray);
	delete[] piNewArray;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int iMenu = 0;

	int iSize = 0;

	cout << "Введите размерность массива:" << endl;
	cin >> iSize;

	int* piArray = new int[iSize];
	vSetArray(iSize, piArray);

	while (iMenu != 4) {

		cout << "1 - Заменить второй элемент массива на максимальный среди отрицательных" << endl
			 << "2 - Вставить число К перед всеми элементами, в которых есть цифра 1" << endl
			 << "3 - Cформировать массив A" << endl
			 << "4 - Выход" << endl;

		cin >> iMenu;
		while (iMenu < 1 || iMenu > 4) { 
			cin >> iMenu;
		}

		switch (iMenu) {
			case 1: {
				vReplace(iSize, piArray);
				break;
			}
			case 2: {
				vPaste(iSize, piArray);
				break;
			}
			case 3: {
				vInit(iSize, piArray);
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
