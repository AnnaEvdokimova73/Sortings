#include <iostream>

void quickSort(int* arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int left = start;
    int right = end;
    int pi = (left + right + 1) / 2; //индекс пивота
    int pivot = arr[pi];

    while (left < right)
    {
        while (arr[left] < pivot)
        {
            ++left;
        }
        while (arr[right] > pivot)
        {
            --right;
        }
        if (left <= right)
        {
            std::swap(arr[left], arr[right]);
            ++left;
            --right;
        }
    }

    quickSort(arr, start, right);
    quickSort(arr, left, end);
}

void quick_sort(int* arr, int size)
{
    if (size < 2)
    {
        return;
    }

    int left = 0;
    int right = size - 1;

    quickSort(arr, left, right);
}

void printArrays(int* arr, int size)
{
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    quick_sort(arr, size);

    std::cout << "Отсортированный массив: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    const int size = 10;
    int arr[size] = { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    const int size1 = 15;
    int arr1[size1] = { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    const int size2 = 18;
    int arr2[size2] = { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
    printArrays(arr, size);
    printArrays(arr1, size1);
    printArrays(arr2, size2);
}
