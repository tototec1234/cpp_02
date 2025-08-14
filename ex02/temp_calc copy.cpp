#include <iostream>
#include <climits>
int main() {
    const float b_value = 2897.31f;
    const int scale = 256;
    long long b_raw = static_cast<long long>(roundf(b_value * scale));
    std::cout << "b_value = " << b_value << std::endl;
    std::cout << "b_raw = " << b_raw << std::endl;
    std::cout << "b_raw * b_raw = " << (b_raw * b_raw) << std::endl;
    std::cout << "(b_raw * b_raw) >> 8 = " << ((b_raw * b_raw) >> 8) << std::endl;
    std::cout << "INT_MAX = " << INT_MAX << std::endl;
    std::cout << "Overflow? " << (((b_raw * b_raw) >> 8) > INT_MAX ? "Yes" : "No") << std::endl;
    return 0;
}
