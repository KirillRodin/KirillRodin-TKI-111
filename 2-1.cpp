#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

using namespace std;

/**
* \brief Математическая функция, рассчитывающая объём шара
* \r - радиус шара
**/
double GetVolume(const double r);

/**
* \brief Математическая функция, рассчитывающая площадь поверхности шара
* \r - радиус шара
**/
double GetSurfaceArea(const double r);

/**
 * \brief Точка входа в программу.
 */
int main() {
  double r;

  cout << "Введите радиус и нажмите Enter: \n";
  cin >> r;

	const auto Volume = getVolume(r);
	const auto SurfaceArea = getSurfaceArea(r);

	cout << "Радиус r = " << r << "\nОбъём шара = " << Volume << "\nПлощадь поверхности шара = " << SurfaceArea;
	return 0;
}

double GetVolume(const double r) { return pow(r, 3) * ((4 * M_PI)/3); } 
double GetSurfaceArea(const double r) { return pow(r, 2) * M_PI * 4; } 