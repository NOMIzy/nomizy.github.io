#include <iostream>
#include <list>

using namespace std;

//双端队列
int main() {
    list<int> l = {1, 2, 3, 4, 5};
    //遍历容器1
    cout << "List elements: ";
    for (int elem : l) {
        cout << elem << " ";
    }
    cout<<endl;

    //增加元素
    l.push_back(6);
    l.push_front(0);

    // 遍历容器2
    cout << "List elements: ";
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    //取出元素
    cout << "First element: " << l.front() << endl;
    cout << "Last element: " << l.back() << endl;

    // 遍历容器2
    cout << "List elements: ";
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    //反向遍历
    // 使用 reverse_iterator 进行反向遍历
    cout << "Reverse List elements: ";
    for (list<int>::reverse_iterator it = l.rbegin(); it != l.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;


    return 0;
}
