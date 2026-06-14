#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<int> us = {3, 1, 4, 1, 5, 9};

    // 读取元素
    if (us.find(4) != us.end()) {
        cout << "Element 4 is in the unordered set." << endl;
    }

    // 遍历容器方法1 (范围for循环，C++11及以上)
    cout << "Unordered set elements (range-based for): ";
    for (int elem : us) {
        cout << elem << " ";
    }
    cout << endl;

    // 增加元素
    us.insert(2);

    // 删除元素
    us.erase(3);

    // 遍历容器方法2 (迭代器)
    cout << "Unordered set elements (iterator): ";
    for (unordered_set<int>::iterator it = us.begin(); it != us.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;


    // unordered_set 没有提供反向迭代器，因为它没有特定的顺序。

}
