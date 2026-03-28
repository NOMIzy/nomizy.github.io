#include<iostream>
using namespace std;

/*
描述
描述
写出一个程序，接受一个由字母、数字和空格组成的字符串，和一个字符，然后输出输入字符串中该字符的出现次数。（不区分大小写字母）

数据范围： 
1≤n≤1000 

输入描述：
第一行输入一个由字母、数字和空格组成的字符串，第二行输入一个字符（保证该字符不为空格）。

输出描述：
输出输入字符串中含有该字符的个数。（不区分大小写字母）

示例1
输入：
ABCabc
A
复制
输出：
2  
*/

/*
编码知识，可以用ascii码的数组来记录
A-Z 65-90
a-z 97-122
0-9 48-57
*/
void ASCII(){
    int char_map[75]={};
    string s1;
    char c;

    getline(cin,s1);

    cin>>c;
    for(int i=0;i<s1.size();i++){
        char_map[int(s1[i])-48]++;
    }
    
    cout<<c<<endl;
    cout<<int(c)<<endl;

    if(int(c)<=57){//是数字直接给出计数
        cout<<char_map[int(c)-48]<<endl;
    }
    if(int(c)<=90 && int(c)>57){
            cout<<char_map[int(c)-48]+char_map[int(c)+32-48]<<endl;
    }
    if(int(c)>=97 && int(c)<=122){
            cout<<char_map[int(c)-48]+char_map[int(c)-32-48]<<endl;
    }
    

}

/*
哈希表方法
*/

int main(){
    ASCII();

    
}