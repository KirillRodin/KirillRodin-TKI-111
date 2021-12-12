#include <iostream>

using namespace std;

/**
* \brief Функция для рассчета факториала
* \param iK - целое число, факториал, которого будет вычисляться
* \param i - счетчик
* \param iRes - переменная для хранения текущего результата
* \return Возвращает значение y1
**/
double dFactorial(int iK) {
	int iRes = 1;
	for (int i = 1; i <= iK; i++) {
		iRes = iRes * i;
	}
	return iRes;
}

// Функция расчета i-го члена последовательности последовательности
double dSequence(int i) {
	return 1 / (dFactorial(i + 2) * dFactorial(i + 3));
}

// Вычисляет сумму первых n членов последовательности
void vSumN() {

	int n = 0;
	cout << "Введите количество членов последовательности:" << endl;
	cin >> n;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Введите число!" << endl;
	}

	double dSum = 0;
	int k = 0;
	while (k < n)
	{
		dSum += dSequence(k);
		k++;
	}
	cout << "Итоговая сумма: " << dSum << endl;
}

// Вычисляет сумму всех членов последовательности, не меньших заданного числа e
void vSumE() {
	
	double dEpsilon = 0.0;
	cout << "Введите число Epsilon:" << endl;
	cin >> dEpsilon;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Введите число!" << endl;
	}

	double dSum = 0;
	int k = 0;
	while (abs(dSequence(k)) > dEpsilon)
	{
		dSum += dSequence(k);
		k++;
	}

	cout << "Итоговая сумма: " << dSum << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int iMenu = 0;
	while (iMenu != 3) {

		cout << "1 - Вычислить сумму первых n членов последовательности" << endl
			 << "2 - Вычислить сумму всех членов последовательности, не меньших заданного числа e" << endl
			 << "3 - Выход" << endl;

		cin >> iMenu;
		while (cin.fail() || iMenu < 1 || iMenu > 3) {
			if (cin.fail()) { 
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Введите верное число!" << endl;
			}
			else { 
				cin >> iMenu;
			}
		}

		switch (iMenu) {
			case 1: {
				vSumN();
				break;
			}
			case 2: {
				vSumE();
				break;
			}
			case 3: {
				break;
			}
		}
	}
}