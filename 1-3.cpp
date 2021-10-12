#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

/**
* \brief Математическая функция, рассчитывающая произведение
* \param const double m - масса, имеющая тип данных с плавающей точкой двойной точности
* \param const double v - скорость, имеющая тип данных с плавающей точкой двойной точности
* \return Возвращает Кинетическую энергию 
**/
double getE(const double m, const double v);

/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успешного выполнения.
 */
int main() {
  double m, v;

  cout << "Введите массу и скорость и нажмите Enter: \n";
  cin >> m >> v;

	const auto E = getE(m, v);
	
	cout << "Масса m = " << m << "\nСкорость v = " << v << "\nКинетическая энергия = " << E;
	return 0;
}

double getE(const double m, const double v) { 
  return (m * pow(v, 2)) / 2; } 