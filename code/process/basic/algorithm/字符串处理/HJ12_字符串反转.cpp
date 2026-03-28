#include<iostream>
#include<string>
using namespace std;

/*
描述
接受一个只包含小写字母的字符串，然后输出该字符串反转后的字符串。（字符串长度不超过1000）

输入描述：
输入一行，为一个只包含小写字母的字符串。

输出描述：
输出该字符串反转后的字符串。

示例1
输入：
abcd
复制
输出：
dcba
复制
*/

int main(){
    string num_str;
    getline(cin,num_str);
    for(int i=num_str.size()-1;i>=0;i--){
        cout<<num_str[i];
    }
    cout<<endl;

}