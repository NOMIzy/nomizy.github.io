#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<int, string> um;
    um[1] = "one";
    um[2] = "two";
    um[3] = "three";

    // 修改元素
    um[2] = "TWO";

    // 增加元素
    um[4] = "four";

    // 删除元素
    um.erase(1);

    // 读取元素
    cout << "Key 2 has value: " << um[2] << endl;

    // 遍历容器方法1 (范围for循环，C++11及以上)
    cout << "Unordered map elements (range-based for): ";
    for (const auto& pair : um) {
        cout << "{" << pair.first << ", " << pair.second << "} ";
    }
    cout << endl;

    // 遍历容器方法2 (迭代器)
    cout << "Unordered map elements (iterator): ";
    for (unordered_map<int, string>::iterator it = um.begin(); it != um.end(); ++it) {
        cout << "{" << it->first << ", " << it->second << "} ";
    }
    cout << endl;






}
