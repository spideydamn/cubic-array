#include "BitFunctions.h"

bool CheckBit(uint8_t& number, uint8_t pos) {
    return (number >> (7 - pos)) & (uint8_t)1;
}

bool CheckBit(uint64_t& number, uint8_t pos) {
    return (number >> pos) & (uint64_t)1;
}

void SetBit(uint8_t& number, uint8_t pos) {
    number |= ((uint8_t)1 << (7 - pos));
}

void ClearBit(uint8_t& number, uint8_t pos) {
    number &= ~((uint8_t)1 << (7 - pos));
}

void ToggleBit(uint8_t& number, uint8_t pos) {
    number ^= ((uint8_t)1 << (7 - pos));
}
