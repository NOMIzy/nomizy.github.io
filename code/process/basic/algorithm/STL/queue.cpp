#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    // 读取元素 (访问队首和队尾元素)
    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;

    // 删除元素 (弹出队首元素)
    q.pop();

    // 遍历容器 (只能访问队首元素)
    cout << "Queue elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
