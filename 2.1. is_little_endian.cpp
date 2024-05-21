#include <iostream>

// Task 2. Find out if CPU Arch is LE
bool isLittleEndianArch() {
    int16_t x = 0x0204;
    if (*(uint8_t *)(&x) == 0x04)
        return true;

    return false;
}

int main() {
    std::cout << isLittleEndianArch() << std::endl;
}
