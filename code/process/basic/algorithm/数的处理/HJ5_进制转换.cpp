#include<iostream>
#include<string>
#include<cmath>
using namespace std;

/*
 描述
写出一个程序，接受一个十六进制的数，输出该数值的十进制表示。

数据范围：保证结果在 
1
≤
�
≤
2
31
−
1
 
1≤n≤2 
31
 −1 
输入描述：
输入一个十六进制的数值字符串。

输出描述：
输出该数值的十进制字符串。不同组的测试用例用\n隔开。

示例1
输入：
0xAA
复制
输出：
170
复制
*/

/*
10+10*16
*/

int my_exp_more_than_0(int cardinal,int index){
    if(index==0){
        return 1;
    }
    
    int base_cardinal=cardinal;
    for(int i=1;i<index;i++){
        cardinal*=base_cardinal;
    }
    return cardinal;

}
int main(){

    string hex_str;
    cin>>hex_str;
    int dex_num=0;
    int r=0;
    
    for(int i=hex_str.size()-1;i>1;i--){
        if(int(hex_str[i])>=65 && int(hex_str[i])<=90){
            dex_num += (int(hex_str[i])+10-65) * my_exp_more_than_0(16,r);
        }else{
            dex_num += (int(hex_str[i])-48) * my_exp_more_than_0(16,r);
        }
        
        r++;

        
    }
    cout<<dex_num;


}