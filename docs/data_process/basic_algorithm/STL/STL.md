# C++STL容器的基本原理与使用

STL（标准模板库）容器是C++标准库的一部分，提供了常用的数据结构和算法。它们被设计成模板类，使得它们能够存储任何类型的数据。STL容器主要分为序列容器（如 `vector`、`deque`、`list`）、关联容器（如 `set`、`map`、`unordered_set`、`unordered_map`）和适配器容器（如 `stack`、`queue`、`priority_queue`）。可以说STL库已经为我们提供了很好的数据结构的轮子，妥善学习使用便可以应对许多算法问题。

本篇首先列出对于数据结构使用有关的基本概念，计算复杂度的对比信息，然后给出各个容器的基本使用示例。后续整理一些练手的基础算法题目使用STL解决的实现。

## 基本概念

1. **序列容器**：维护元素的顺序，允许元素的重复。
    - **vector**：动态数组，支持高效的随机访问和在末尾插入/删除操作。
    - **deque**：双端队列，支持高效的随机访问和在两端插入/删除操作。
    - **list**：双向链表，支持高效的插入/删除操作，但不支持随机访问。

2. **关联容器**：通过键值对存储数据，通常用于高效查找、插入和删除操作。
    - **set**：存储唯一元素的有序集合。
    - **map**：键值对集合，键唯一，有序。
    - **unordered_set**：存储唯一元素的无序集合。
    - **unordered_map**：键值对集合，键唯一，无序。

3. **适配器容器**：基于其他容器实现的抽象数据结构。
    - **stack**：基于 `deque` 或 `vector` 实现的后进先出（LIFO）数据结构。
    - **queue**：基于 `deque` 实现的先进先出（FIFO）数据结构。
    - **priority_queue**：基于 `vector` 实现的优先级队列，通常是一个最大堆。

### 底层数据结构

- **vector**：实现为动态数组，内存是连续的，因此支持快速的随机访问。当容量不足时，会重新分配内存并复制已有元素。
  
- **deque**：实现为双端队列，支持在两端高效地插入和删除元素，内部结构类似于多个固定大小数组的组合，因此随机访问也较快。

- **list**：实现为双向链表，插入和删除操作仅需修改指针，因此时间复杂度为O(1)，但由于链表不连续存储，随机访问的时间复杂度较高。

- **set**和**map**：底层实现是平衡二叉树，因此查找、插入和删除操作的时间复杂度为O(log n)。

- **unordered_set**和**unordered_map**：底层实现为哈希表，平均情况下查找、插入和删除操作的时间复杂度为O(1)，但在哈希冲突严重时最坏情况会退化为O(n)。

- **stack**、**queue**、**priority_queue**：这些适配器容器在其底层实现上进一步封装了特定的数据结构以提供特定的接口。`stack`和`queue`在插入和删除操作上都具有O(1)的复杂度，而`priority_queue`在插入和删除操作上都具有O(log n)的复杂度，因为它需要维护堆的性质。

### 计算复杂度

1. **vector**：
    - 访问元素：O(1)
    - 插入/删除元素（末尾）：摊销O(1)
    - 插入/删除元素（中间）：O(n)
    - 内存重新分配：O(n)

2. **deque**：
    - 访问元素：O(1)
    - 插入/删除元素（两端）：O(1)
    - 插入/删除元素（中间）：O(n)

3. **list**：
    - 访问元素：O(n)
    - 插入/删除元素（任意位置，给出迭代器）：O(1)

4. **set**：
    - 查找元素：O(log n)
    - 插入/删除元素：O(log n)

5. **map**：
    - 查找元素：O(log n)
    - 插入/删除元素：O(log n)

6. **unordered_set**：
    - 查找元素：O(1) 平均情况，O(n) 最坏情况
    - 插入/删除元素：O(1) 平均情况，O(n) 最坏情况

7. **unordered_map**：
    - 查找元素：O(1) 平均情况，O(n) 最坏情况
    - 插入/删除元素：O(1) 平均情况，O(n) 最坏情况

8. **stack**（基于 `deque` 或 `vector`）：
    - 访问顶元素：O(1)
    - 插入/删除元素：O(1)

9. **queue**（基于 `deque`）：
    - 访问头元素：O(1)
    - 插入/删除元素：O(1)

10. **priority_queue**（基于 `vector`，使用堆实现）：
    - 访问顶元素：O(1)
    - 插入元素：O(log n)
    - 删除顶元素：O(log n)



## 使用示例
包含操作：
- 初始化
- 读取元素
- 修改元素
- 增加元素（开头、尾部、随机位置）
- 删除元素（开头、尾部、随机位置）
- 遍历容器（正向/反向的c++11方法和一般迭代器方法）
### **vector**
~~~c++
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

~~~
### **deque**
~~~c++
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

~~~

### **list**
~~~c++
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


~~~
### **set**
~~~c++
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

~~~
### **map**
~~~c++
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

~~~

### **unordered_set**
~~~c++
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

~~~

### **unordered_map**
~~~c++
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
~~~

### **stack**
~~~c++
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

~~~
### **queue**
~~~c++
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

~~~
### **priority_queue**
优先队列对于图，贪心问题的解决都很有用，往往需要自定义元素结构
~~~c++
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// 自定义类型 Person
struct Person {
    string name;
    int age;
    Person(string n, int a) : name(n), age(a) {}
    bool operator<(const Person &p2) const{
        // 定义优先级：年龄越大优先级越高
        return age < p2.age;
    }
};



int main() {
    // 使用 priority_queue 存储 Person 类型，并使用自定义比较函数
    priority_queue<Person, vector<Person>> pq;

    // 添加元素
    pq.push(Person("Alice", 30));
    pq.push(Person("Bob", 25));
    pq.push(Person("Charlie", 35));
    pq.push(Person("Diana", 28));

    // 读取并删除元素
    cout << "Priority queue elements (by age):" << endl;
    while (!pq.empty()) {
        Person p = pq.top();
        cout << p.name << " (" << p.age << ")" << endl;
        pq.pop();
    }

}

~~~
