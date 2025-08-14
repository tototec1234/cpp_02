#include <iostream>
#include <cmath>

int main() {
    // NaNを作成
    double nan_value = sqrt(-1);
    
    std::cout << "nan_value = " << nan_value << std::endl;
    std::cout << std::endl;
    
    // 通常の値での比較
    double normal_value = 5.0;
    std::cout << "=== 通常の値での比較 ===" << std::endl;
    std::cout << "normal_value = " << normal_value << std::endl;
    std::cout << "normal_value == normal_value: " << (normal_value == normal_value) << std::endl;
    std::cout << "normal_value != normal_value: " << (normal_value != normal_value) << std::endl;
    std::cout << std::endl;
    
    // NaNでの比較
    std::cout << "=== NaNでの比較 ===" << std::endl;
    std::cout << "nan_value == nan_value: " << (nan_value == nan_value) << std::endl;
    std::cout << "nan_value != nan_value: " << (nan_value != nan_value) << std::endl;
    std::cout << std::endl;
    
    // NaN同士の比較
    double another_nan = sqrt(-2);
    std::cout << "=== 異なるNaN同士の比較 ===" << std::endl;
    std::cout << "nan_value == another_nan: " << (nan_value == another_nan) << std::endl;
    std::cout << "nan_value != another_nan: " << (nan_value != another_nan) << std::endl;
    std::cout << std::endl;
    
    // NaNと通常の値の比較
    std::cout << "=== NaNと通常の値の比較 ===" << std::endl;
    std::cout << "nan_value == 5.0: " << (nan_value == 5.0) << std::endl;
    std::cout << "nan_value != 5.0: " << (nan_value != 5.0) << std::endl;
    std::cout << "nan_value > 5.0: " << (nan_value > 5.0) << std::endl;
    std::cout << "nan_value < 5.0: " << (nan_value < 5.0) << std::endl;
    
    return 0;
}
