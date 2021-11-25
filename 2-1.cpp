#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <iomanip>

enum class Choice
{
AREA,
VOLUME
};

/**
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успеха.
 */
 
int main()
{

  double radius;
	std::cout << "Введите радиус r ";
	std::cin >> radius;
    std::cout << "Введите что нужно найти (Объём или Площадь) "
        << "Объём - " << static_cast<int>(Choice::VOLUME)
        << "Площадь - " << static_cast<int>(Choice::AREA)
        << " ";

    int input;
    std::cin >> input;


    const auto RESULT = static_cast<Choice>(input);
    switch (RESULT)
    {
        case Choice::AREA:{
            const double Area=pow(radius, 3) * ((4 * M_PI)/3);
            std::cout << "Площадь поверхности =" << Area;
            break;}
        case Choice::VOLUME:{
           const double Volume=pow(radius, 2) * M_PI * 4;
            std::cout << "Объём=" << Volume;
            break;}
       
    }

    return 0;
}