#include "ArrayElement.h"

ArrayElement::ArrayElement(CubicArray* cubic_array, uint64_t position) {
    cubic_array_ = cubic_array;
    position_ = position;
}

ArrayElement& ArrayElement::operator=(const uint64_t& value) {
    cubic_array_->SetValue(position_, value);
    return *this;
}

CubicArray *ArrayElement::GetCubicArray() const {
    return cubic_array_;
}

uint64_t ArrayElement::GetPosition() const {
    return position_;
}

ArrayElement::operator int() {
    return cubic_array_->GetValue(position_);
}

std::ostream& operator<<(std::ostream& stream, const ArrayElement& array_element) {
    stream << array_element.GetCubicArray()->GetValue(array_element.GetPosition());
    return stream;
}