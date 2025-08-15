#include <iostream>
#include <cmath>
#include <climits>

int main() {
    const int MIN_SAFE_INT = INT_MIN / (1 << 8);
    
    // NaNをroundfに渡した場合の動作をテスト
    float nan_value = static_cast<float>(sqrt(MIN_SAFE_INT));
    std::cout << "nan_value = " << nan_value << std::endl;
    
    float rounded = roundf(nan_value * (1 << 8));
    std::cout << "roundf(nan_value * 256) = " << rounded << std::endl;
    std::cout << "rounded is NaN? " << (rounded != rounded) << std::endl;
    
    // long longにキャストした場合
    long long result = static_cast<long long>(rounded);
    std::cout << "static_cast<long long>(rounded) = " << result << std::endl;
    
    // intにキャストした場合
    int final_result = static_cast<int>(result);
    std::cout << "static_cast<int>(result) = " << final_result << std::endl;
    
    return 0;
}
