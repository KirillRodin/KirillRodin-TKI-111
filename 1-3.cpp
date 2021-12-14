#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

using namespace std;

/**
* \brief Функция рассчитывающая кинетическую энергию
* \param m - масса
* \param v - скорость
* \return Выводит кинетическую энергию 
**/
double getEnergy(const double m, const double v);

/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успешного выполнения.
 */
int main() {
  setlocale(LC_ALL, "Russian");
  double m, v;
  cout << "Введите массу и скорость и нажмите Enter: \n";
  cin >> m >> v;

	const auto energy = getEnergy(m, v);
	
	cout << "Масса m = " << m << "\nСкорость v = " << v << "\nКинетическая энергия = " << energy;
	return 0;
}

double getEnergy(const double m, const double v) { 
  return (m * pow(v, 2)) / 2; } 