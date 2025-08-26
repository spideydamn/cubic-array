#pragma once
#include "ArrayElement.h"
#include "CubicArray.h"

class CubicArray;

class ArrayElement;

class LineArray {
public:
    LineArray(CubicArray* cubic_array, uint64_t start_position);

    ArrayElement operator[](uint64_t z);
private:
    CubicArray* cubic_array_;
    uint64_t start_position_;
};