#include<iostream>
#include<string>
#include<cmath>
using namespace std;

//AACGT ACCGGT
/*
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
 

示例 1：

输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2：

输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
*/

int tests=1;
int dp[1000][1000];
int main(){

    string s1,s2;
    cin>>tests;
    while(tests>0){
        tests--;
       
        cin>>s1;
        cin>>s2;
        
        int len1=s1.size();
        int len2=s2.size();
       

        for(int i=0;i<=len1;i++){
            for(int j=0;j<=len2;j++){
                dp[i][j]=INT32_MAX-1;

            }
        }
        for(int j=0;j<=len2;j++){
            dp[0][j]=j;
        }
        for(int i=0;i<=len1;i++){
            dp[i][0]=i;
        }
        for(int i=1;i<=len1;i++){
            for(int j=1;j<=len2;j++){
                int flag;
                if(s1[i-1]==s2[j-1]){
                    flag=0;
                }else{
                    flag=1;
                }

                //更新dp
                //cout<<min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+flag))<<endl;
                dp[i][j]=min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+flag));

            }
        }
        cout<<dp[len1][len2]<<endl;

        for(int i=0;i<=len1;i++){
            for(int j=0;j<=len2;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
}
