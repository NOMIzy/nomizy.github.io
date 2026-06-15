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
