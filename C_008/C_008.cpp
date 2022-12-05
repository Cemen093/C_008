#include <iostream>
using namespace std;
void deleteColumn(int** array, int& x, int& y, int index);

void view(int** array, int x, int y)
{
    for (size_t i = 0; i < x; i++)
    {
        for (size_t j = 0; j < y; j++)
        {
            cout << array[i][j] << "\t";
        }
        cout << endl;
    }
}

//Задание 1. Написать функцию, удаляющую столбцы двумерному массиву имеющих хотя бы один нулевой элемент.
void task01(int** array, int& x, int& y)
{
    for (size_t i = 0; i < x; i++)
    {
        int index = -1;
        for (size_t j = 0; j < y; j++)
        {
            if (array[i][j] == 0)
            {
                index = j;
                break;
            }
        }

        if (index > -1)
        {
            deleteColumn(array, x, y, index);
        }
    }
}

//Задание 2. Написать функцию, которая удаляет столбец двумерного массива по указанному номеру.
void deleteColumn(int** array, int& x, int& y, int index)
{
    for (size_t i = 0; i < x; i++)
    {
        int* tmp = new int[y - 1];
        int tmpIndex = 0;
        for (size_t j = 0; j < y; j++)
        {
            if (j != index)
            {
                tmp[tmpIndex] = array[i][j];
                tmpIndex++;
            }
        }
        delete[] array[i];
        array[i] = tmp;
    }
    y--;
}

int main()
{
    int x = 5, y = 10;
    int** array = new int* [x];
    for (size_t i = 0; i < x; ++i) array[i] = new int[y];
    for (size_t i = 0; i < x; i++)
    {
        for (size_t j = 0; j < y; j++)
        {
            array[i][j] = i + j - 2;
        }
    }

    view(array, x, y);
    cout << endl;
    task01(array, x, y);
    view(array, x, y);

    deleteColumn(array, x, y, 2);
    cout << endl;
    view(array, x, y);

    for (size_t i = 0; i < x; ++i) delete[] array[i];
    delete[] array;
}