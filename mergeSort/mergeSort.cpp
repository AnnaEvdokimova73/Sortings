#include <iostream>

void merge(int* targetArr, int* arr1, int* arr2, int size1, int size2)
{
    int iTarget = 0;
    int iArr1 = 0;
    int iArr2 = 0;

    while (iArr1 < size1 && iArr2 < size2)
    {
        if (arr1[iArr1] <= arr2[iArr2])
        {
            targetArr[iTarget] = arr1[iArr1];
            ++iArr1;
        }
        else
        {
            targetArr[iTarget] = arr2[iArr2];
            ++iArr2;
        }
        ++iTarget;
    }
    while (iArr1 < size1)
    {
        targetArr[iTarget] = arr1[iArr1];
        ++iArr1;
        ++iTarget;
    }
    while (iArr2 < size2)
    {
        targetArr[iTarget] = arr2[iArr2];
        ++iArr2;
        ++iTarget;
    }
}

void merge_sort(int* arr, int size)
{
    if (size < 2)
    {
        return;
    }

    int mid = size / 2;
    int* left = new int[mid];
    int* right = new int[size - mid];

    for (int i = 0; i < mid; ++i)
    {
        left[i] = arr[i];
    }

    for (int i = mid; i < size; ++i)
    {
        right[i - mid] = arr[i];
    }

    merge_sort(left, mid);
    merge_sort(right, size - mid);
    merge(arr, left, right, mid, size - mid);

    delete[] left;
    delete[] right;
}

void printArrays(int* arr, int size)
{
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    merge_sort(arr, size);

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

