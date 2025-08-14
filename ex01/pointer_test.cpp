#include "Fixed.hpp"
#include <iostream>
#include "AnsiColor.hpp"

int main() {
    std::cout << ANSI_COLOR_GREEN << "=== ポインタ渡しoperator<<のテスト ===" << ANSI_COLOR_RESET << std::endl;
    
    // 通常のオブジェクト作成
    Fixed a(42.42f);
    Fixed b(10);
    
    std::cout << "\n--- 値渡し版（既存）vs ポインタ渡し版の比較 ---" << std::endl;
    
    // std::cout << ANSI_COLOR_BLUE << "値渡し版: " << ANSI_COLOR_RESET;
    // std::cout << a << std::endl;  // 値渡し版が呼ばれる
    
    std::cout << ANSI_COLOR_BLUE << "ポインタ渡し版: " << ANSI_COLOR_RESET;
    std::cout << &a << std::endl;  // ポインタ渡し版が呼ばれる
    
    std::cout << ANSI_COLOR_BLUE << "ポインタ渡し版（別の値）: " << ANSI_COLOR_RESET;
    std::cout << &b << std::endl;
    
    // NULLポインタのテスト
    std::cout << ANSI_COLOR_BLUE << "NULLポインタのテスト: " << ANSI_COLOR_RESET;
    Fixed* nullPtr = NULL;
    std::cout << nullPtr << std::endl;
    
    std::cout << ANSI_COLOR_GREEN << "=== テスト完了 ===" << ANSI_COLOR_RESET << std::endl;
    
    return 0;
}

/*
g++ -std=c++98 -Wall -Wextra -Werror pointer_test.cpp Fixed.cpp -o pointer_test && ./pointer_test
 */