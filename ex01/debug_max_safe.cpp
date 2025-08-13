#include <iostream>
#include <iomanip>
#include <climits>
#include <cmath>

int main() {
    const float MAX_SAFE_FLOAT = 8388607.0f;
    
    std::cout << std::fixed << std::setprecision(10);
    std::cout << "MAX_SAFE_FLOAT = " << MAX_SAFE_FLOAT << std::endl;
    std::cout << "MAX_SAFE_FLOAT * 256 = " << (MAX_SAFE_FLOAT * 256) << std::endl;
    std::cout << "roundf(MAX_SAFE_FLOAT * 256) = " << roundf(MAX_SAFE_FLOAT * 256) << std::endl;
    
    long long result = static_cast<long long>(roundf(MAX_SAFE_FLOAT * 256));
    std::cout << "long long result = " << result << std::endl;
    std::cout << "INT_MAX = " << INT_MAX << std::endl;
    std::cout << "result > INT_MAX? " << (result > INT_MAX ? "Yes" : "No") << std::endl;
    
    return 0;
}
