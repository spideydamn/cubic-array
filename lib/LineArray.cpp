#include "LineArray.h"

LineArray::LineArray(CubicArray* cubic_array, uint64_t start_position) {
    cubic_array_ = cubic_array;
    start_position_ = start_position;
}

ArrayElement LineArray::operator[](uint64_t z) {
    return {cubic_array_, start_position_ + z};
}