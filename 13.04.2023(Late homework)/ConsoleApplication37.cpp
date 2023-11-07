//Напишіть програму, яка приймає від користувача два масиви цілих чисел та
//об'єднує їх у третій масив, використовуючи вказівники. Програма повинна вивести на екран вміст третього масиву.

#include <iostream>
#include <Windows.h>

using namespace std;

void mergeArrays(int* arr1, int n1, int* arr2, int n2, int* result) {
    int i, j, k;
    i = j = k = 0;

    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            result[k] = arr1[i];
            i++;
        }
        else {
            result[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        result[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n2) {
        result[k] = arr2[j];
        j++;
        k++;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n1, n2;

    cout << "Введіть розмір першого масиву: ";
    cin >> n1;

    int* arr1 = new int[n1];

    cout << "Введіть елемент першого масиву: ";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    cout << "Введіть розмір другого масиву: ";
    cin >> n2;

    int* arr2 = new int[n2];

    cout << "Введіть елемент другого масиву: ";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    int* result = new int[n1 + n2];

    mergeArrays(arr1, n1, arr2, n2, result);

    cout << "Масив: ";

    for (int i = 0; i < n1 + n2; i++) {
        cout << result[i] << " ";
    }
}

