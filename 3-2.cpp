#include <iostream>

using namespace std;

/**
 * \brief Пользовательский ввод необходимой точности вычисления.
 * \param message Мотивационное сообщение
 * \return Точность вычисления
 * \exception invalid_argument В случае, если epsilon меньше 0
 */
double getEpsilon(const string& message);

/**
 * \brief Рассчитывает сумму последовательность с точностью epsilon
 * \param eps Точность вычисления
 * \return Сумма последовательности с точностью epsilon
 */
double getSumE(const double eps);

/**
 * \brief Пользовательский ввод количества членов последовательности
 * \param message Мотивационное сообщение
 * \return Размер последовательности
 * \exception invalid_argument В случае, если размер последовательности меньше 1
 */
size_t getSequenceSize(const string& message);

/**
 * \brief Рассчитывает значение рекуррентного члена в зависимости от индекса
 * \param index Индекс, номер итерации
 * \return Значение рекуррентного члена
 */
double getRecurrentNumber(const size_t index) noexcept;

/**
 * \brief Точка входа в программу.
 * \return 0 – в случае успеха,<br/>1 – в противном случае.
 */
int main() noexcept
{
    setlocale(LC_ALL, "Russian");
    try
    {
        const auto size = getSequenceSize("Введите количество членов последовательности n = ");
        double current = 0;
        double sum = 0;
        for (int i = 0; i < size; i++) {
            if (i == 0) {
                current = 1;
            }
            else {
                current *= getRecurrentNumber(i - 1);
            }
            sum += current;
        }
        cout << "Итоговая сумма равна: " << sum << endl;
        const auto eps = getEpsilon("Введите точность вычислений ");
        const double sumE = getSumE(eps);
        cout << "Сумма последовательности c точностью " << eps << " равна: " << sumE << endl;
        return 0;
    }
    catch (const exception& e)
    {
        cerr << e.what() << endl;
        return 1;
    }
}
double getSumE(const double eps) {
    size_t i = 0;
    double sumE = 0;
    double current = eps + 1;
    while (abs(current) >= eps) {
        if (i == 0) {
            current = 1;
        }
        else {
            current *= getRecurrentNumber(i - 1);
        }
        sumE += current;
        i++;
    }
    return sumE;
}
double getEpsilon(const string& message)
{
    cout << message;
    double eps = 0;
    cin >> eps;
    if (eps < 0)
    {
        throw invalid_argument("Значение должно быть больше 0!");
    }

    return eps;
}

size_t getSequenceSize(const string& message)
{
    cout << message;
    int size = 0;
    cin >> size;
    if (size < 1)
    {
        throw invalid_argument("Значение должно быть больше 0!");
    }

    return size;
}

double getRecurrentNumber(const size_t index) noexcept
{
    return -1.0 / ((index + 3) * (index + 4));
}