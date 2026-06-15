#include<iostream>
#include<string>
using namespace std;

/*
描述
输入一个整数，将这个整数以字符串的形式逆序输出
程序不考虑负数的情况，若数字含有0，则逆序形式也含有0，如输入为100，则输出为001


数据范围： 
0
≤
�
≤
2
30
−
1
 
0≤n≤2 
30
 −1 
*/

int main(){
    string num_str;
    getline(cin,num_str);
    for(int i=num_str.size()-1;i>=0;i--){
        cout<<num_str[i];
    }
    cout<<endl;

}