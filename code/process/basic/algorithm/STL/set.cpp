#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> s = {3, 1, 4, 1, 5, 9};


    // 读取元素
    if (s.find(4) != s.end()) {
        cout << "Element 4 is in the set." << endl;
    }

    // 遍历容器方法1 (范围for循环，C++11及以上) //可以看到降重
    cout << "Set elements (range-based for): ";
    for (int elem : s) {
        cout << elem << " ";
    }
    cout << endl;

    // 增加元素
    s.insert(2);

    // 遍历容器方法2 (迭代器)
    cout << "Set elements (iterator): ";
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // 删除元素
    s.erase(3);

    // 反向遍历容器 (反向迭代器)
    cout << "Set elements (reverse iterator): ";
    for (set<int>::reverse_iterator rit = s.rbegin(); rit != s.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;


}
