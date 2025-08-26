#pragma once
#include <cinttypes>
#include <iostream>
#include "BitFunctions.h"
#include "CubicArray.h"

class CubicArray;

class ArrayElement {
public:
    ArrayElement(CubicArray* cubic_array, uint64_t position);

    ArrayElement& operator=(const uint64_t& value);

    explicit operator int();

    [[nodiscard]] CubicArray* GetCubicArray() const;
    [[nodiscard]] uint64_t GetPosition() const;
private:
    CubicArray* cubic_array_;
    uint64_t position_;
};

std::ostream& operator<<(std::ostream& stream, const ArrayElement& array_element);
