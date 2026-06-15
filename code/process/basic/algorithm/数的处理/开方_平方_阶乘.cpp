#include <iostream>
#include <cmath>   // 包含数学库，用于开平方
#include <cassert> // 包含断言库，用于测试
using namespace std;

// 计算平方
int square(int x) {
    return x * x;
}

// 计算开平方（平方根）
double squareRoot(double x) {
    // 确保输入为非负数
    assert(x >= 0);
    return sqrt(x);
}

// 计算阶乘（递归实现）
int factorial(int n) {
    // 确保输入为非负整数
    assert(n >= 0);
    if (n == 0) {
        return 1; // 0的阶乘是1
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    // 计算平方
    int num = 5;
    int num_squared = square(num);
    cout << "Square of " << num << " is " << num_squared << std::endl;

    // 计算开平方
    double num2 = 25.0;
    double num2_sqrt = squareRoot(num2);
    cout << "Square root of " << num2 << " is " << num2_sqrt << std::endl;

    // 计算阶乘
    int num3 = 5;
    int num3_factorial = factorial(num3);
    cout << "Factorial of " << num3 << " is " << num3_factorial << std::endl;


}
