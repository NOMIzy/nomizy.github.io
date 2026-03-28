#include<iostream>
#include<string>
using namespace std;

/*
描述
将一个英文语句以单词为单位逆序排放。例如“I am a boy”，逆序排放后为“boy a am I”

所有单词之间用一个空格隔开，语句中除了英文字母外，不再包含其他字符

数据范围：输入的字符串长度满足 
1
≤
�
≤
1000
 
1≤n≤1000 

注意本题有多组输入
输入描述：
输入一个英文语句，每个单词用空格隔开。保证输入只包含空格和字母。

输出描述：
得到逆序的句子
*/

int main(){
    string num_str;
    getline(cin,num_str);
    int last_space=num_str.size();

    for(int i=num_str.size()-1;i>=0;i--){
        if(num_str[i] == ' '){
            for(int j=i+1;j<last_space;j++){
                cout<<num_str[j];
            }
            cout<<" ";
            last_space=i;
        }
       
    }
    int i=0;
    while(num_str[i] != ' '){
        cout<<num_str[i];
        i++;
    }

}