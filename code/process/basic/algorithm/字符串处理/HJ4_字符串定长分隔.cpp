#include<iostream>
#include<string>
using namespace std;

/*
  描述
•输入一个字符串，请按长度为8拆分每个输入字符串并进行输出；

•长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
输入描述：
连续输入字符串(每个字符串长度小于等于100)

输出描述：
依次输出所有分割后的长度为8的新字符串

示例1
输入：
abc
复制
输出：
abc00000
复制
*/

int main(){
    string str;
    getline(cin,str);
    //补齐为8的整数倍
    if(str.size()%8 != 0){
        int need_add=8-(str.size() % 8); 
        string add_str(need_add,'0');
        str=str+add_str;
    }
    
    
    for(int i=0;i<str.size();i++){
        cout<<str[i];
        if((i+1)%8 == 0){
            cout<<endl;
        }
    }
    

}