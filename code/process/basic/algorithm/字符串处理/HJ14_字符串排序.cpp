#include<iostream>
#include<string>
using namespace std;

/*
描述
给定 n 个字符串，请对 n 个字符串按照字典序排列。

数据范围： 
1
≤
�
≤
1000
 
1≤n≤1000  ，字符串长度满足 
1
≤
�
�
�
≤
100
 
1≤len≤100 
输入描述：
输入第一行为一个正整数n(1≤n≤1000),下面n行为n个字符串(字符串长度≤100),字符串中只含有大小写字母。
输出描述：
数据输出n行，输出结果为按照字典序排列的字符串。
*/

int Compare_Str_Is_Back(string str1,string str2){
    int small_len=str1.size();
    if(str1.size() > str2.size()){
        small_len=str2.size();
    }

    for(int i=0;i<str2.size();i++){
        if(int(str2[i])<int(str1[i])){
            return 1;
        }
        if(int(str2[i])>int(str1[i])){
            return -1;
        }
    }

    if(str1.size()==str2.size()){
        return 0;
    }
    if(str1.size()>str2.size()){
        return 1;
    }
    if(str1.size()<str2.size()){
        return -1;
    }


}


int main(){
    
    int n;
    cin>>n;
    string str_list[n];
    for(int i=0;i<n;i++){
        cin>>str_list[i];
    }

    int small_index;
    string temp;
    for(int i=0;i<n;i++){
        small_index=i;
        for(int j=i;j<n;j++){
            if(Compare_Str_Is_Back(str_list[small_index],str_list[j])==1){
                small_index=j;
            }
        }

        temp=str_list[small_index];
        str_list[small_index]=str_list[i];
        str_list[i]=temp;
        
    }

    for(int i=0;i<n;i++){
        cout<<str_list[i]<<endl;
    }



}