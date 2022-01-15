#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <iomanip>

/**
 * \brief Рассчитывает значение y при заданном x.
 * \param x Значение x
 * \return Значение y при заданном x
 */
double Count(double x);

/**
 * \brief Проверка y при заданном х
 * \param x Значение x
 * \return true, y существует при заданном х
 */
bool isCalculated(double x);

/**
 * \brief Точка входа в программу
 * \return (Код 0) Успех
 */
int main()
{
    const double x_0 = 2;
    const double x_1 = 3.1;
    const double step = 0.1;
    double x = x_0;
    while(x < x_1)
    {
        if (isCalculated(x))
        {
            const double y = Count(x);
            std::cout << "x = " << std::setw(10) << std::left << std::setprecision(4) << x << " y = " << y << "\n";
        }
        else
        {
            std::cout << "При x = " << x << " y не существует" << "\n";
        }

        x += step;
    }
    return 0;
}

double Count(const double x){
    return 3 * sin(sqrt(x)) + 0.39 * x - 3.8;
}

bool isCalculated(const double x){
    return x >= 0;
}