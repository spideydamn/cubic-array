#include<iostream>
#include "lib/CubicArray.h"

using namespace std;

int main() {
    CubicArray arr = CubicArray::make_array(2, 2, 2);
    arr[0][0][0] = 100500;
    arr[1][1][0] = 100228;
    arr[0][1][1] = 1234;
    arr[1][0][1] = 15856;
    CubicArray arr2 = CubicArray::make_array(2, 2, 2);
    arr2[0][0][0] = 100500;
    arr2[1][1][0] = 100228;
    arr2[0][1][1] = 1234;
    arr2[1][0][1] = 15856;
    CubicArray arr3 = arr + arr2;
    cout << arr;
    cout << "\n\n\n";
    cout << arr2;
    cout << "\n\n\n";
    cout << arr3;
    CubicArray arr4 = arr3;
    cout << "\n\n\n";
    cout << arr4;
}