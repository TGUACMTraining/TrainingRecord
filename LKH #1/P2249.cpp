//https://www.luogu.com.cn/problem/P2249

#include <algorithm>
#include <iostream>
using namespace std;

int* inputArray(int total) {
    int* array = new int[total];
    for (int i = 0; i < total; i++) {
        cin >> array[i];
    }
    return array;
}

//recursion
// int locate(const int* array, int value, int begin, int end) {
//     int mid = (begin + end) / 2;
//     if (array[mid] == value)
//         return mid;
//     if (mid == end) {
//         return -1;
//     }
//     if (value > array[mid])
//         locate(array, value, mid + 1, end);
//     else
//         locate(array, value, begin, mid - 1);
// }

//non-recursion
int locate(const int* array, int value, int begin, int end) {
    int mid = (begin + end) / 2;
    while (array[mid] != value) {
        if (value > array[mid])
            begin = mid + 1;
        else
            end = mid - 1;
        mid = (begin + end) / 2;
        if (mid == end) break;
    }
    if (array[mid] == value)
        return mid;
    return -1;
}

int* find(int* array, int* value, int arrayTotal, int findTotal) {
    int* result = new int[findTotal];
    for (int i = 0; i < findTotal; i++) {
        int pos = locate(array, value[i], 0, arrayTotal - 1);
        if (pos != -1 && pos != 0) {
            while (array[--pos] == value[i])
                ;
            pos += 2;
        }
        if (pos == 0)
            pos++;
        result[i] = pos;
    }
    return result;
}

int main() {
    int arrayTotal;
    int findTotal;
    cin >> arrayTotal;
    cin >> findTotal;
    int* array = inputArray(arrayTotal);
    int* value = inputArray(findTotal);
    int* result = find(array, value, arrayTotal, findTotal);
    for (int i = 0; i < findTotal; i++)
        cout << result[i] << ' ';
    return 0;
}
