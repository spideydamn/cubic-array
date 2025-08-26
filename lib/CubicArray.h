#pragma once
#include "SquareArray.h"

class SquareArray;

class CubicArray {
public:
    CubicArray(uint64_t _size_x, uint64_t _size_y, uint64_t _size_z);
    ~CubicArray();
    CubicArray(const CubicArray& cubic_array);

    static CubicArray make_array(uint64_t n, uint64_t m, uint64_t k);

    [[nodiscard]] uint64_t GetSizeX() const;
    [[nodiscard]] uint64_t GetSizeY() const;
    [[nodiscard]] uint64_t GetSizeZ() const;

    [[nodiscard]] uint64_t GetValue(uint64_t n) const;
    void SetValue(uint64_t n, uint64_t value);


    CubicArray& operator=(const CubicArray& cubic_array);
    CubicArray operator-();
    CubicArray operator+(const CubicArray& rhs);
    CubicArray operator-(const CubicArray& rhs);
    CubicArray operator*(const uint64_t value);


    SquareArray operator[](uint64_t x);
private:
    uint16_t* sixteen_bit_tails_;
    uint8_t* most_significant_bits_;

    uint64_t size_x_;
    uint64_t size_y_;
    uint64_t size_z_;
};

std::ostream& operator<<(std::ostream& stream, const CubicArray& array);
