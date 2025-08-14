#include "Fixed.hpp"
#include <iostream>

// 値渡し版
std::ostream &operator_by_value(std::ostream &str, const Fixed fixed) {
    std::cout << "=== 値渡し版が呼ばれました ===" << std::endl;
    return str << fixed.toFloat();
}

// const参照版
std::ostream &operator_by_const_ref(std::ostream &str, const Fixed &fixed) {
    std::cout << "=== const参照版が呼ばれました ===" << std::endl;
    return str << fixed.toFloat();
}

int main() {
    std::cout << "\n--- 値渡し版のテスト ---" << std::endl;
    {
        Fixed a(42.42f);
        std::cout << "operator呼び出し前" << std::endl;
        operator_by_value(std::cout, a);
        std::cout << "\noperator呼び出し後" << std::endl;
    }
    
    std::cout << "\n--- const参照版のテスト ---" << std::endl;
    {
        Fixed b(42.42f);
        std::cout << "operator呼び出し前" << std::endl;
        operator_by_const_ref(std::cout, b);
        std::cout << "\noperator呼び出し後" << std::endl;
    }
    
    return 0;
}
