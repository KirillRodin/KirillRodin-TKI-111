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
 * \param min_value Минимальное значение в интервале (-10)
 * \param maxv_alue Максимальное значение в интервале (10)
 * \return Массив
 */
int* GetArray(const size_t size, const int selection, const int min_value, const int max_value);

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
string toString(const int*, const size_t size);

/**
 * \brief Функция для замены второго элемента массива на максимальный среди отрицательных
 * \param size Размер массива
 */
void Replace(int*, const size_t size);

/**
 * \brief Функция для добавления в массив числа K
 * \param size Размер массива
 * \param index Номер элемента
 * \param k Число K вводимое пользователем
 */
void AddElement(int*&, size_t& size, const size_t index, const int k);

/**
 * \brief Функция для вставки числа К перед всеми элементами в которых есть цифра 1
 * \param size Размер массива
 * \param k Число K вводимое пользователем
 */
void Paste(int*&, size_t& size, const int k);

/**
 * \brief Формирует из массива D массив A по правилу (если номер четный, то значение элемента находится по формуле Ai = Di^2, а если нечетный, то по формуле Ai = Di / i)
 * \param size Размер массива
 * \return массив А
 */
int* FormArray(int*, const size_t size);

/**
 * \brief Точка входа в программу
 * \return (Код ошибки 0) успех
 */
int main()
{
    setlocale(LC_ALL, "Russian");
    auto error_code = 0;
    int* my_array = nullptr;
    const int min_value = -10;
    const int max_value = 10;
    try
    {
        auto size = GetSize("Введите размер массива: ");
        cout << "Выберите способ создания массива: " << static_cast<int>(Choice::Manual) << " - вручную, " << static_cast<int>(Choice::Random) << " - заполнить случайными числами ";
        int input_type;
        cin >> input_type;
        my_array = GetArray(size, input_type, min_value, max_value);
        cout << "Итоговый массив:\n";
        cout << toString(my_array, size);
        cout << "\nМассив после замены второго элемента массива на максимальный среди отрицательных:\n ";
        Replace(my_array, size);
        cout << toString(my_array, size);
        int k;
        cout << "\nВведите число K: ";
        cin >> k;
        cout << "Массив после вставки числа К перед всеми элементами имеющими цифру 1:\n ";
        Paste(my_array, size, k);
        cout << toString(my_array, size);
        cout << "\nНовый массив:\n ";
        cout << toString(FormArray(my_array, size), size);
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

int* GetArray(const size_t size, const int selection, const int min_value, const int max_value)
{
    const auto array = new int[size];
    //Will be used to obtain a seed for the random number engine
    random_device rd;

    //Standard mersenne_twister_engine seeded with rd()
    mt19937 gen(rd());
    const uniform_int_distribution<> uniformIntDistribution(min_value, max_value);
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

string toString(const int* array, const size_t size)
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

void Replace(int* array, const size_t size) {
    int Value = 0;
    for (size_t i = 0; i < size; i++) {
        if (array[i] < Value) {
            Value = array[i];
            array[2] = Value;
        }
    }
}

void AddElement(int*& array, size_t& size, const size_t index, const int k) {
    int* new_array = new int[size + 1];
    new_array[index] = k;
    for (size_t i = 0; i < index; i++) {
        new_array[i] = array[i];
    }
    for (size_t i = index + 1; i < size + 1; i++) {
        new_array[i] = array[i - 1];
    }
    delete[] array;
    array = new_array;
    size = size + 1;
}

void Paste(int*& array, size_t& size, const int k) {
    for (size_t i = 0; i < size; i++) {
        int value = (array[i]);
        if (value % 10 == 1) {
            AddElement(array, size, i, k);
            i++;
        }
        if (value / 10 == 1) {
            AddElement(array, size, i, k);
            i++;
        }
        if (value / 10 == -1) {
            AddElement(array, size, i, k);
            i++;
        }
    }
}

int* FormArray(int* array_d, const size_t size) {
    int* array_a = new int[size];
    for (size_t i = 0; i < size; i++) {
        if (i % 2 == 0) {
            array_a[i] = pow(array_d[i],2);
        }
        else {
            array_a[i] = array_d[i] / i;
        }
    }
    return array_a;
}