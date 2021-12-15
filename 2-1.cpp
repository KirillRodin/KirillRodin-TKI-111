#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>
#include <iomanip>

/**
 *\brief Функция для поиска площади поверхности шара
 *\param radius Радиус вводимый пользователем
 *\return Выводит значение плоащади поверхности шара
 */
double getArea(const double radius);

/**
 *\brief Функция для поиска объёма шара
 *\param radius Радиус вводимый пользователем
 *\return Выводит значение объёма шара
 */
double getVolume(const double radius);
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
        << "\nОбъём - " << static_cast<int>(Choice::VOLUME)
        << "\nПлощадь - " << static_cast<int>(Choice::AREA)
        << "\n ";

    int input;
    std::cin >> input;


    const auto RESULT = static_cast<Choice>(input);
    switch (RESULT)
    {
        case Choice::AREA:{
        
             std::cout << "Площадь поверхности = " << getArea(radius);
            break;}
        case Choice::VOLUME:{
          
            std::cout << "Объём = " << getVolume(radius);
            break;}

    }

    return 0;
}
double getArea(const double radius){
  return pow(radius, 2) * M_PI * 4;
}
double getVolume(const double radius){
  return pow(radius, 3) * ((4 * M_PI)/3);
}