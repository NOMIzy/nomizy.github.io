#include <iostream>
#include <deque>

using namespace std;

int main() {
    deque<int> d = {1, 2, 3, 4, 5};

    // 读取元素
    cout << "Element at index 2: " << d[2] << endl;

    // 修改元素
    d[0] = 0;

    // 增加元素
    d.push_back(6); // 尾部
    d.push_front(-1); // 开头
    d.insert(d.begin() + 2, 10); // 随机位置
    
    // 遍历容器方法1 (范围for循环，C++11及以上)
    cout << "Deque elements (range-based for): ";
    for (int elem : d) {
        cout << elem << " ";
    }
    cout << endl;

    // 删除元素
    d.pop_back(); // 尾部
    d.pop_front(); // 开头
    d.erase(d.begin() + 2); // 随机位置



    // 遍历容器方法2 (迭代器)
    cout << "Deque elements (iterator): ";
    for (deque<int>::iterator it = d.begin(); it != d.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 反向遍历容器 (反向迭代器)
    cout << "Deque elements (reverse iterator): ";
    for (deque<int>::reverse_iterator rit = d.rbegin(); rit != d.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;

    return 0;
}
