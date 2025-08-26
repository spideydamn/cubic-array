#pragma once
#include "LineArray.h"
#include "CubicArray.h"

class CubicArray;

class LineArray;

class SquareArray {
public:
    SquareArray(CubicArray* cubic_array, uint64_t start_position, uint64_t size_z);

    LineArray operator[](uint64_t y);
private:
    CubicArray* cubic_array_;
    uint64_t start_position_;

    uint64_t size_z_;
};