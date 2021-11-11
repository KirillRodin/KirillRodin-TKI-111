#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

using namespace std;

/**
* \brief Функция для рассчета y1
* \param x Значение x
* \return Возвращает значение y1
**/
double GetFirst(const double x, const double a);

/**
* \brief Функция для рассчета y2* 
* \param x Значение x
* \return Возвращает значение y2
**/
double GetSecond(const double x, const double a);

/**
 * \brief Точка входа в программу.
 */
int main() {
  
  const double a = 2.5;
  double x;

  cout << "Введите чилсо x = ";
  cin >> x;
  if (x > a)
   {
      auto first = GetFirst(x,a);
      cout << first;
   }
  else
   {
      auto second = GetSecond(x,a);
      cout << second;
   }

}

double GetFirst(const double x, const double a) { return x * pow((x-a), 1.0 / 3.0); } 
double GetSecond(const double x, const double a) { return x * sin(a) * x;} 