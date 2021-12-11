#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

using namespace std;

/**
*\brief Рассчитывает площадь прямоугольника
 * \param a длина стороны
 * \param n коэффициент
 * \return Площадь прямоугольника
 */
double getSquare(const double a, const double n);

/**
 * \brief Вычисляет периметр прямоугольника
 * \param a длина стороны
 * \param n коэффициент
 * \return Периметр прямоугольника
 */
double getPerimeter(const double a, const double n);

/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успешного выполнения.
 */
int main() {
	setlocale(LC_ALL, "Russian");
	double a, n;
	cout << "Введите длину и коэффициент и нажмите Enter: \n";
	cin >> a >> n;
	const auto square = getSquare(a, n);
	const auto perimeter = getPerimeter(a, n);
	cout << "Стророна a = " << a << "\nКоэффициент n = " << n << "\nПериметр = " << perimeter << "\nПлощадь = " << square;
	return 0;
}

double getSquare(const double a, const double n) { return pow(a, 2) * n; }
double getPerimeter(const double a, const double n) { return 2 * a * (1 + n); }