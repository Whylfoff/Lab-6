#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
bool startsAndEndsWithSameDigit(int num) { // для 4 задачи
    int lastDigit = num % 10;
    while (num >= 10) {
        num /= 10;
    }
    int firstDigit = num;
    return firstDigit == lastDigit;
}

bool startsWithThree(int num) { // для 4 задачи
    while (num >= 10) {
        num /= 10;
    }
    return num == 3;
}
int sumofdigits(int num) { // для первой и второй
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int firstdigit(int num) { // для второй
    while (num >= 10) {
        num /= 10;
    }
    return num;
}
bool customCompare(int a, int b) { // кастомный компайрер для сорта по условию для второй задачи сделан на костылях но рабочий
    int sumA = sumofdigits(a);
    int sumB = sumofdigits(b);

    if (sumA != sumB) {
        return sumA < sumB;
    }
    int firstA = firstdigit(a);
    int firstB = firstdigit(b);

    if (firstA != firstB) {
        return firstA < firstB;
    }
    return a < b;
}

int main() {
    //1.
    int n;
    cout << "Введите количество чисел в последовательности (n <= 10000): ";
    cin >> n;

    int array[10000];
    bool lol = false;

    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
        if (sumofdigits(array[i]) == 19) {
            lol = true;
        }
    }

    if (!lol) {
        sort(array, array + n, greater<int>());
    }   

    cout << "Последовательность: ";
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    //2.
    int n;
    cout << "Введите количество чисел в последовательности (n <= 1000): ";
    cin >> n;

    int arr[1000];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr, arr + n, customCompare);

    cout << "Последовательность: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;

    //3.
    int n, m;
    cout << "Введите размеры матрицы (n, m <= 100): ";
    cin >> n >> m;

    int matrix[100][100];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    int maxsumindex = -1;
    int maxsum = numeric_limits<int>::min();

    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < m; ++j) {
            sum += std::abs(matrix[i][j]);
        }
        if (sum > maxsum) {
            maxsum = sum;
            maxsumindex = i;
        }
    }

    for (int j = 0; j < m; ++j) {
        matrix[maxsumindex][j] = 9999;
    }

    cout << "ИТоговая матрица:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    //4.
    int n;
    cout << "Введите количество чисел в последовательности (n <= 10000): ";
    cin >> n;

    int arr[10000];
    int newsize = 0;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (!startsAndEndsWithSameDigit(num)) {
            arr[newsize++] = num;
            if (startsWithThree(num)) {
                arr[newsize++] = num; // дублирую число
            }
        }
    }

    cout << "Итоговая последовательность: ";
    for (int i = 0; i < newsize; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

}

