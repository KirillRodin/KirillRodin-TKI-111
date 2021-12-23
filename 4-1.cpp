#include <iostream>
#include <sstream>
#include <random>

using namespace std;

/**
 * \brief Способы задания массива
 */
enum class Choice
{
    /**
     * \brief Ввод вручную
     */
    Manual,

    /**
     * \brief Ввод с помощью рандномных чисел
     */
     Random
};

/**
 * \brief Метод заполнения массива
 * \param size Размер массива
 * \param selection Выбор создания массива (вручную или случайными числами)
 * \param MinValue Минимальное значение в интервале (-10)
 * \param MaxValue Максимальное значение в интервале (10)
 * \return Массив
 */
int* GetArray(const size_t size, const int selection, const int MinValue, const int MaxValue);

/**
 * \brief Получение массива
 * \param message Мотивоционное сообщение для пользователя
 * \return Размер массива
 */
size_t GetSize(const string& message);

/**
 * \brief Вывод элементов массива
 * \param size Размер массива
 * \return Строка со значениями индексов массива
 */
string InString(const int*, const size_t size);

/**
 * \brief Функция для нахождения суммы элементов, имеющих нечетное значение
 * \param size Размер массива
 * \return Сумма элементов, имеющих нечетное значение
 */
int Sum(int*, const size_t size);

/**
 * \brief Находит индексы элементов значения которых меньше A
 * \param size Размер массива
 * \param A Число A
 * \return Индексы элементов
 */
void Index(int*, const size_t size, const int A);

/**
 * \brief Функция для замены второго элемента массива на максимальный (математически) среди отрицательных
 * \param size Размер массива
 * \return Массив с совершенной заменой
 */
void Replace(int*, const size_t size);

/**
 * \brief Точка входа в программу
 * \return (Код ошибки 0) успех
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    auto error_code = 0;
    int* my_array = nullptr;
    const int MinValue = -11;
    const int MaxValue = 11;
    try
    {
        const auto size = GetSize("Введите размер массива: ");
        cout << "Выберите способ создания массива: " << static_cast<int>(Choice::Manual) << " - вручную, " << static_cast<int>(Choice::Random) << " - заполнить случайными числами ";
        int input_type;
        cin >> input_type;
        my_array = GetArray(size, input_type, MinValue, MaxValue);
        cout << "Итоговый массив:\n";
        cout << InString(my_array, size);
        cout << "\nСумма элементов, имеющих нечетное значение: " << Sum(my_array, size) << '\n';
        int A;
        cout << "Введите число A: ";
        cin >> A;
        cout << "Индексы: ";
        Index(my_array, size, A);
        cout << "\nМассив после замены второго элемента массива на максимальный (математически) среди отрицательных:\n";
        Replace(my_array, size);
        cout << InString(my_array, size);
    }
    catch (exception& e)
    {
        cout << e.what();
        error_code = 1;
    }

    if (my_array != nullptr)
    {
        delete[] my_array;
        my_array = nullptr;
    }
    return error_code;
}

size_t GetSize(const string& message)
{
    int size = -1;
    cout << message;
    cin >> size;

    if (size <= 0)
    {
        throw out_of_range("Неправильный размер массива");
    }

    return size;
}

int* GetArray(const size_t size, const int selection, const int MinValue, const int MaxValue)
{
    const auto array = new int[size];
    //Will be used to obtain a seed for the random number engine
    random_device rd;

    //Standard mersenne_twister_engine seeded with rd()
    mt19937 gen(rd());
    const uniform_int_distribution<> uniformIntDistribution(MinValue, MaxValue);
    for (size_t index = 0; index < size; index++)
    {
        switch (selection)
        {
        case static_cast<int>(Choice::Manual):
        {
            cout << "Введите " << index + 1 << " элемент массива в диапозоне [-10;10]: ";
            cin >> array[index];
            break;
        }
        case static_cast<int>(Choice::Random):
        {
            array[index] = uniformIntDistribution(gen);
            break;
        }
        }
    }

    return array;
}

string InString(const int* array, const size_t size)
{
    if (array == nullptr)
        throw invalid_argument("Массив не существует");

    stringstream buffer;
    buffer << "{";
    for (size_t index = 0; index < size - 1; index++)
    {
        buffer << array[index] << ", ";
    }
    buffer << array[size - 1] << "}";
    return buffer.str();
}

int Sum(int* array, const size_t size) {
    int Sum = 0;
    for (size_t i = 0; i < size; i++) {
        if (array[i] % 2)
            Sum += array[i];
    }
    if (Sum == 1)
        Sum = 0;
    return Sum;
}

void Index(int* array, const size_t size, const int A) {
    for (size_t i = 0; i < size; i++) {
        if ((array[i]) < A) {
            cout << i << endl;
        }
    }
}

void Replace(int* array, const size_t size) {
    const int UnderMin = -11;
    int Value = UnderMin;
    for (size_t i = 0; i < size; i++) {
        if (array[i] < 0 && array[i] > Value) {
            Value = array[i];
        }
    }

    if (Value != UnderMin) {
        array[2] = Value;
    }
    else {
        cout << "Массив остался прежним. В массиве отсутствуют отрицательные элементы!" << endl;
    }
}