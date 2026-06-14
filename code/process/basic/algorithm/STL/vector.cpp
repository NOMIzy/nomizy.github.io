#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};

    // 读取元素
    cout << "Element at index 2: " << v[2] << endl;

    // 修改元素
    v[0] = 0;

    // 增加元素
    v.push_back(6); // 尾部
    v.insert(v.begin() + 2, 10); // 随机位置

    // 遍历容器方法1 (范围for循环，C++11及以上)
    cout << "Vector elements (range-based for): ";
    for (int elem : v) {
        cout << elem << " ";
    }
    cout << endl;

    // 删除元素
    v.pop_back(); // 尾部
    v.erase(v.begin()); // 开头
    v.erase(v.begin() + 2); // 随机位置

    

    // 遍历容器方法2 (迭代器)
    cout << "Vector elements (iterator): ";
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 反向遍历容器 (反向迭代器)
    cout << "Vector elements (reverse iterator): ";
    for (vector<int>::reverse_iterator rit = v.rbegin(); rit != v.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    return 0;
}
