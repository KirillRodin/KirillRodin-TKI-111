#define _USE_MATH_DEFINES


#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

double Calculate(const double x);

/**
 * \brief Точка входа в программу
 * \return Возвращает нуль, в случае успеха
 */
int main()
{
	const auto left = 2.0;
	const auto right = 3.0;
	const auto step = 0.1;

	auto x = left;
	cout << "x" << setw(15) << "y\n";

	while ((x < right) || (abs(x - right) < step))
	{
	 if (Calculate(x))
	 {
	  const auto y = Calculate(x);
	  cout << setw(10) << setprecision(2) << x << setw(15)
          << setprecision(5) << y << endl;
	  }
	 else
	  {
	   cout << setw(10) << setprecision(2) << x << setw(15)
	   << "Отсутствие решения" << endl;
    }
	x = x + step;
	}
	return 0;
}

bool isCalculated(const double x) 
{
return x >= numeric_limits<double>::min();
}

double Calculate(const double x) 
{
return 3 * sin(sqrt(x)) + 0.39 * x - 3.8;
}
