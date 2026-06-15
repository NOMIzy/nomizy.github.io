#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, string> m;
    m[1] = "one";
    m[2] = "two";
    m[3] = "three";


    // 读取元素
    cout << "Key 2 has value: " << m[2] << endl;

    // 遍历容器方法1 (范围for循环，C++11及以上)
    cout << "Map elements (range-based for): ";
    for (const auto& pair : m) {
        cout << "{" << pair.first << ", " << pair.second << "} ";
    }
    cout<< endl;

    // 修改元素
    m[2] = "TWO";

    // 增加元素
    m[4] = "four";

    // 删除元素
    m.erase(1);
    
    // 遍历容器方法2 (迭代器)
    cout << "Map elements (iterator): ";
    for (map<int, string>::iterator it = m.begin(); it != m.end(); ++it) {
        cout << "{" << it->first << ", " << it->second << "} ";
    }
    cout << endl;

    // 反向遍历容器 (反向迭代器)
    cout << "Map elements (reverse iterator): ";
    for (map<int, string>::reverse_iterator rit = m.rbegin(); rit != m.rend(); ++rit) {
        cout << "{" << rit->first << ", " << rit->second << "} ";
    }
    cout << endl;


}

