#include<iostream>
using namespace std;
/*
输入一个 int 型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。
保证输入的整数最后一位不是 0 。

数据范围： 
1
≤
�
≤
1
0
8
 
1≤n≤10 
8
  
输入描述：
输入一个int型整数

输出描述：
按照从右向左的阅读顺序，返回一个不含重复数字的新的整数


*/
int main(){
    int duplicate[10];
    for(int i=0;i<10;i++){
        duplicate[i]=0;
    }

    int n;
    cin>>n;
    int ans=0;
    while(n!=0){
        //取出个位数
        int temp=n%10;
        //cout<<"temp="<<temp<<endl;
        //如果该个位数还没重复就加入ans，即ans左移一位后加这个个位数，记录这个数的重复
        if(duplicate[temp]==0){
            ans=ans*10;
            ans+=temp;
            duplicate[temp]=1;

        }
        //右移1位n
        n=n/10;
        //cout<<"n="<<n<<endl;
    }
    cout<<ans;

}