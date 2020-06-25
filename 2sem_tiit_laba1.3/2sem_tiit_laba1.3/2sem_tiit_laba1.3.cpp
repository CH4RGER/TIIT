#include "Lib.h"
#include "iostream"
#include <ctime>
#include <Windows.h>
//#include "Lib.h"
//#include <stdio.h>
//#include <conio.h>
//#include <iostream>
//#include <string>
//#include <ctype.h>



using namespace std;

int main() 
{
    srand(time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_CTYPE, "Russian");
    
    cout << "Введите количество элементов массива:\n";
    int size;
    cin >> size;
    int* arr = FillArr(size);

    cout << "Cозданный массив:\n";
    PrintArr(arr, size);

    cout << "Отсортированный массив:\n";
    Sort(arr, size);
    PrintArr(arr, size);

    cout << "Введите число которое хотите найти в массиве:\n";
    int ret, num;
    cin >> num;
    if ((ret = binsearch(num, arr, size)) < 0)
        printf("\nЧисло %d отсутствует в массиве\n", num);
    else
        printf("\nЧисло %d находится в a[%d]\n", num, ret);
    
    cout << "Введите число которое хотите вставить в массив:\n";
    int numb;
    cin >> numb;
    Insert(arr, size, numb);
    cout << "Cозданный массив:\n";
    PrintArr(arr, size);

    cout << "Введите число которое хотите найти в массиве:\n";
    int ret2, num2;
    cin >> num2;
    if ((ret2 = binsearch(num2, arr, size)) < 0)
        printf("\nЧисло %d отсутствует в массиве\n", num2);
    else
        printf("\nЧисло %d находится в a[%d]\n", num2, ret2);

    cout << "Введите количество элементов массива:\n";
    int size2;
    cin >> size2;
    int* arr2 = FillArr(size2);
    cout << "Cозданный массив:\n";
    PrintArr(arr2, size2);

    cout << "Отсортированный массив:\n";
    Sort(arr2, size2);
    PrintArr(arr2, size2);

    int sizeU = 0;
    int* Unionarr = Union(arr, size, arr2, size2, sizeU);
    cout << "\n" << "Обединение массивов\n";
    PrintArr(Unionarr, sizeU);

    int sizeI = 0;
    int* Interarr = Intersection(arr, size, arr2, size2, sizeI);
    cout << "Пересечение массивов" << endl;
    PrintArr(Interarr, sizeI);
}