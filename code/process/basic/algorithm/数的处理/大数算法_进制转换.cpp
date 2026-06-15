#include<iostream>
#include<list>
using namespace std;

// 打印大数
void printBigNum(const list<int>& num) {
    for (auto it = num.rbegin(); it != num.rend(); ++it) {
        cout << *it;
    }
    cout << endl;
}
//十进制大数加法
list<int> DexBigNumSum(list<int> num1,list<int> num2){
    list<int> result;
    auto it1 = num1.begin();
    auto it2 = num2.begin();
    int carry = 0;

    while (it1 != num1.end() || it2 != num2.end() || carry) {
        int sum = carry;
        if (it1 != num1.end()) {
            sum += *it1;
            ++it1;
        }
        if (it2 != num2.end()) {
            sum += *it2;
            ++it2;
        }
        result.push_back(sum % 10);
        carry = sum / 10;
    }

    return result;

}
//十进制大数减法
//十进制大数乘法
//十进制大数除法

//十进制转x进制大数
//x进制转十进制大数


int main(){
    list<int> num1 = {1,1,1,1,1,1,1}; // 243
    list<int> num2 = {1,1,1,1,1,1,1}; // 678
    list<int> sum = DexBigNumSum(num1, num2); // 243 + 678 = 921

    printBigNum(sum); // 921
}