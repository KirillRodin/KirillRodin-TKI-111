#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>

using namespace std;

/**
* \brief Математическая функция, рассчитывающая площадь прямоугольника
* \param const double a - длина прямоугольника, имеющая тип данных с плавающей точкой двойной точности
* \param const double n - коэффициент, имеющий тип данных с плавающей точкой двойной точности
* \return Возвращает площадь чисел
**/
double getS(const double a, const double n);

/**
* \brief Математическая функция, рассчитывающая периметр прямоугольника
* \param const double a - длина прямоугольника, имеющая тип данных с плавающей точкой двойной точности
* \param const double n - коэффициент, имеющий тип данных с плавающей точкой двойной точности
* \return Возвращает периметр прямоугольника 
**/
double getP(const double a, const double n);


/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успешного выполнения.
 */
int main() {
  double a, n;

  cout << "Введите длину и коэффициент и нажмите Enter: \n";
  cin >> a >> n;

	const auto S = getS(a, n);
	const auto P = getP(a, n);

	cout << "Стророна a = " << a << "\nКоэффициент n = " << n << "\nПериметр = " << S << "\nПлощадь = " << P;
	return 0;
}

double getS(const double a, const double n) { return pow(a, 2) * n; } 
double getP(const double a, const double n) { return 2 * a * (1 + n); } 