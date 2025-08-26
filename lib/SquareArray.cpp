#include "SquareArray.h"

LineArray SquareArray::operator[](uint64_t y) {
    return {cubic_array_, start_position_ + y * size_z_};
}

SquareArray::SquareArray(CubicArray* cubic_array, uint64_t start_position, uint64_t size_z) {
    cubic_array_ = cubic_array;
    start_position_ = start_position;

    size_z_ = size_z;
}
