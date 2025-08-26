#include "CubicArray.h"

CubicArray::CubicArray(uint64_t size_x, uint64_t size_y, uint64_t size_z) {
    size_x_ = size_x;
    size_y_ = size_y;
    size_z_ = size_z;
    sixteen_bit_tails_ = new uint16_t[size_x * size_y * size_z]{};
    most_significant_bits_ = new uint8_t[(size_x * size_y * size_z + 7) / 8]{};
}

CubicArray::~CubicArray() {
    delete[] sixteen_bit_tails_;
    delete[] most_significant_bits_;
}

CubicArray::CubicArray(const CubicArray& cubic_array) {
    *this = CubicArray(cubic_array.size_x_, cubic_array.size_y_, cubic_array.size_z_);
    for (int i = 0; i < cubic_array.size_x_ * cubic_array.size_y_ * cubic_array.size_z_; ++i) {
        sixteen_bit_tails_[i] = cubic_array.sixteen_bit_tails_[i];
    }
    for (int i = 0; i < (cubic_array.size_x_ * cubic_array.size_y_ * cubic_array.size_z_ + 7) / 8; ++i) {
        most_significant_bits_[i] = cubic_array.most_significant_bits_[i];
    }
}



CubicArray CubicArray::make_array(uint64_t n, uint64_t m, uint64_t k) {
    return {n, m, k};
}



uint64_t CubicArray::GetSizeX() const {
    return this->size_x_;
}

uint64_t CubicArray::GetSizeY() const {
    return this->size_y_;
}

uint64_t CubicArray::GetSizeZ() const {
    return this->size_z_;
}



uint64_t CubicArray::GetValue(uint64_t n) const {
    return ((CheckBit(most_significant_bits_[n / 8], n % 8) << 16) | sixteen_bit_tails_[n]);
}

void CubicArray::SetValue(uint64_t n, uint64_t value) {
    this->sixteen_bit_tails_[n] = value;
    if (CheckBit(value, 16)) {
        SetBit(most_significant_bits_[n / 8], n % 8);
    } else {
        ClearBit(most_significant_bits_[n / 8], n % 8);
    }
}



CubicArray& CubicArray::operator=(const CubicArray& cubic_array) {
    size_x_ = cubic_array.size_x_;
    size_y_ = cubic_array.size_y_;
    size_z_ = cubic_array.size_z_;
    delete[] sixteen_bit_tails_;
    sixteen_bit_tails_ = new uint16_t[size_x_ * size_y_ * size_z_]{};
    delete[] most_significant_bits_;
    most_significant_bits_ = new uint8_t[(size_x_ * size_y_ * size_z_ + 7) / 8]{};
    for (int i = 0; i < cubic_array.size_x_ * cubic_array.size_y_ * cubic_array.size_z_; ++i) {
        sixteen_bit_tails_[i] = cubic_array.sixteen_bit_tails_[i];
    }
    for (int i = 0; i < (cubic_array.size_x_ * cubic_array.size_y_ * cubic_array.size_z_ + 7) / 8; ++i) {
        most_significant_bits_[i] = cubic_array.most_significant_bits_[i];
    }
    return *this;
}

CubicArray CubicArray::operator-() {
    CubicArray new_cubic_array(this->size_x_, this->size_y_, this->size_z_);
    for (uint64_t i = 0; i < this->size_x_ * this->size_y_ * this->size_z_; ++i) {
        new_cubic_array.SetValue(i, 131072-this->GetValue(i));
    }

    return new_cubic_array;
}

CubicArray CubicArray::operator+(const CubicArray& rhs) {
    CubicArray new_cubic_array = make_array(this->size_x_, this->size_y_, this->size_z_);

    for (uint64_t i = 0; i < this->size_x_ * this->size_y_ * this->size_z_; ++i) {
        new_cubic_array.SetValue(i, this->GetValue(i) + rhs.GetValue(i));
    }

    return new_cubic_array;
}

CubicArray CubicArray::operator-(const CubicArray& rhs) {
    CubicArray new_cubic_array = make_array(this->size_x_, this->size_y_, this->size_z_);

    for (uint64_t i = 0; i < this->size_x_ * this->size_y_ * this->size_z_; ++i) {
        new_cubic_array.SetValue(i, this->GetValue(i) - rhs.GetValue(i));
    }

    return new_cubic_array;
}

CubicArray CubicArray::operator*(const uint64_t value) {
    CubicArray new_cubic_array = make_array(this->size_x_, this->size_y_, this->size_z_);

    for (uint64_t i = 0; i < this->size_x_ * this->size_y_ * this->size_z_; ++i) {
        new_cubic_array.SetValue(i, this->GetValue(i) * value);
    }

    return new_cubic_array;
}

SquareArray CubicArray::operator[](uint64_t x) {
    return {this, x * size_y_ * size_z_, size_z_};
}

std::ostream& operator<<(std::ostream& stream, const CubicArray& cubic_array) {
    uint64_t size_x = cubic_array.GetSizeX();
    uint64_t size_y = cubic_array.GetSizeY();
    uint64_t size_z = cubic_array.GetSizeZ();
    for (int x = 0; x < size_x; ++x) {
        for (int y = 0; y < size_y; ++y) {
            for (int z = 0; z < size_z; ++z) {
                stream << cubic_array.GetValue(x * size_y * size_z + y * size_z + z);
                if (z < size_z - 1) {
                    stream << ' ';
                }
            }
            if (y < size_y - 1) {
                stream << '\n';
            }
        }
        if (x < size_x - 1) {
            stream << '\n' << '\n';
        }
    }
    return stream;
}
