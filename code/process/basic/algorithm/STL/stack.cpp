#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    // 读取元素 (访问栈顶元素)
    cout << "Top element: " << s.top() << endl;

    // 删除元素 (弹出栈顶元素)
    s.pop();

    // 遍历容器 (只能访问栈顶元素)
    cout << "Stack elements: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
