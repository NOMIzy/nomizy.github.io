#include<iostream>
#include<string>
using namespace std;

/*
字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。

示例1:

 输入："aabcccccaaa"
 输出："a2b1c5a3"
示例2:

 输入："abbccd"
 输出："abbccd"
 解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。
提示：

字符串长度在[0, 50000]范围内。

*/

/*
编码知识，可以用ascii码的数组来记录
A-Z 65-90
a-z 97-122
0-9 48-57
*/
string ItoStr(int num){
    string ans;
    int n;
    while(num!=0){
        n=num%10;
        ans+=char(n+48);
        num=num/10;
    }
    int temp;
    int size=ans.size();
    for(int i=0;i<size/2;i++){
        temp=ans[i];
        ans[i]=ans[size-1-i];
        ans[size-1-i]=temp;
    }

    return ans;
}

int main(){
    string str;
    cin>>str;

    string ans;
    int same_char_count=1;
    for(int i=0;i<str.size()-1;i++){
        //从第一个字符开始，比较其与后一个字符是否一致，有一致和不一致两种情况
        //一致时，
        if(str[i]==str[i+1]){
            same_char_count++;
            if((i+2)==str.size()){
                ans+=str[i];
            ans+=ItoStr(same_char_count);
            same_char_count=1;

            }
        }else{
            ans+=str[i];
            ans+=ItoStr(same_char_count);
            same_char_count=1;
        }
    }

    cout<<ans<<endl;
}