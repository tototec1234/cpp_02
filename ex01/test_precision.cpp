#include <iostream>
#include <iomanip>
#include <climits>

int main() {
    // 正確な境界値を計算
    float candidates[] = {8388607.0f, 8388606.0f, 8388605.0f, 8388604.0f};
    
    std::cout << std::fixed << std::setprecision(1);
    for (int i = 0; i < 4; i++) {
        float candidate = candidates[i];
        long long result = static_cast<long long>(candidate * 256);
        std::cout << "candidate=" << candidate << " * 256 = " << result;
        if (result <= INT_MAX) {
            std::cout << " ✓ (安全)";
        } else {
            std::cout << " ✗ (オーバーフロー)";
        }
        std::cout << std::endl;
    }
    
    // より精密なテスト
    std::cout << "\nINT_MAX = " << INT_MAX << std::endl;
    std::cout << "INT_MAX / 256 = " << (static_cast<double>(INT_MAX) / 256.0) << std::endl;
    
    return 0;
}
