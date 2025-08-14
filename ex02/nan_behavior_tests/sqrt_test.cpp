#include <iostream>
#include <cmath>
#include <climits>

int main() {
    const int MIN_SAFE_INT = INT_MIN / (1 << 8);
    
    std::cout << "MIN_SAFE_INT = " << MIN_SAFE_INT << std::endl;
    std::cout << "sqrt(MIN_SAFE_INT) = " << sqrt(MIN_SAFE_INT) << std::endl;
    std::cout << "sqrt(-1) = " << sqrt(-1) << std::endl;
    std::cout << "sqrt(-100) = " << sqrt(-100) << std::endl;
    
    // NaNかどうかチェック
    double result = sqrt(MIN_SAFE_INT);
    std::cout << "sqrt(MIN_SAFE_INT) is NaN? " << (result != result) << std::endl;
    
    // floatにキャストした場合
    float float_result = static_cast<float>(sqrt(MIN_SAFE_INT));
    std::cout << "static_cast<float>(sqrt(MIN_SAFE_INT)) = " << float_result << std::endl;
    std::cout << "float result is NaN? " << (float_result != float_result) << std::endl;
    
    return 0;
}
