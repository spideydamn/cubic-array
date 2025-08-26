#pragma once
#include <cinttypes>

bool CheckBit(uint8_t& number, uint8_t pos);
bool CheckBit(uint64_t& number, uint8_t pos);
void SetBit(uint8_t& number, uint8_t pos);
void ClearBit(uint8_t& number, uint8_t pos);
void ToggleBit(uint8_t& number, uint8_t pos);
void CopyArray(uint16_t*& destination, uint16_t*& source, uint64_t size);
void CopyArray(uint8_t*& destination, uint8_t*& source, uint64_t size);