#include <iostream>
#include <cassert> // 包含断言库，用于测试
using namespace std;

// 迭代方式计算指数
double powerIterative(double base, int exponent) {
    // 断言：对于负指数的情况，底数不应为0
    assert(!(base == 0 && exponent < 0));
    
    double result = 1.0;
    int exp = abs(exponent); // 处理负指数的情况
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    
    // 处理负指数
    if (exponent < 0) {
        result = 1 / result;
    }
    
    return result;
}

int main() {
    double base = 2.0;
    int exponent = 3;
    double result = powerIterative(base, exponent);
    cout << base << " raised to the power of " << exponent << " is " << result << std::endl;

    base = 2.0;
    exponent = -3;
    result = powerIterative(base, exponent);
    cout << base << " raised to the power of " << exponent << " is " << result << std::endl;

}
