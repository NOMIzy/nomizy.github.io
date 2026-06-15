#include <iostream>

int main() {
    char character = 'A'; // 你要查看的字符
    int charCode = static_cast<int>(character); // 转换为整数编码
    std::cout << "Character: " << character << ", Encoding: " << charCode << std::endl;
    return 0;
}
