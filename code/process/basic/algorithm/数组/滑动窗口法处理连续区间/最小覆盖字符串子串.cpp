#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

/*
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：

对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。
如果 s 中存在这样的子串，我们保证它是唯一的答案。
 

示例 1：

输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"
解释：最小覆盖子串 "BANC" 包含来自字符串 t 的 'A'、'B' 和 'C'。
示例 2：

输入：s = "a", t = "a"
输出："a"
解释：整个字符串 s 是最小覆盖子串。
示例 3:

输入: s = "a", t = "aa"
输出: ""
解释: t 中两个字符 'a' 均应包含在 s 的子串中，
因此没有符合条件的子字符串，返回空字符串。
*/
//滑动窗口法可以处理对一段连续数组区间的判断
//这个判断是固定的，和当前这段连续数组有关，要么为真要么为假
//那么是否能判断完全部的区间呢？
//如果我们要找的是满足某个条件的连续数组区间，是可以的
//从某个位置开始，一直找到满足条件的区间的末位置
//然后再从这个位置开始走，节省的是嵌套循环O（n^2)中内部循环逐步累加的过程

//计算复杂度，前后两个指针都要走完整个数组 2n
//前面一个走一下判断一下，后面一个走一下判断一下，判断次数 2n
//总体是O（n）的计算复杂度




string minSubStringCover(string base,string cover_limit){
    //把需要覆盖的字符记到哈希表
    map<char,int> need_cover_chars;
    map<char,int> chars_count;
    for(int i=0;i<cover_limit.size();i++){
        if(need_cover_chars.find(cover_limit[i])!=need_cover_chars.end()){
            need_cover_chars[cover_limit[i]]++;
        }else{
            need_cover_chars[cover_limit[i]]=1;
            chars_count[cover_limit[i]]=0;
        }
    }

    //初始化滑动窗口前端，子串长度，结果记录的序列变量
    int i=0;
    int subLength=0;
    int resultLen=INT32_MAX;
    int resultI=0;
    int resultJ=0;
    int coveredFlag;
    
    //开始滑动窗口检查
    for(int j=0;j<base.size();j++){
        //新增后端元素时处理
        if(need_cover_chars.find(base[j])!=need_cover_chars.end()){
            chars_count[base[j]]++;
        }


        coveredFlag=1;
        for (map<char, int>::iterator it = need_cover_chars.begin(); it != need_cover_chars.end(); ++it) {
                if (it->second > chars_count[it->first]){
                    coveredFlag=0;
                }
        }

        //条件是，map中的每个元素都不为0
        while(coveredFlag==1){
            //记录最小区间
            subLength = (j - i + 1); // 取子序列的长度
            if(resultLen>subLength){
                resultLen=subLength;
                resultI=i;
                resultJ=j;
            }

            //减少前端元素的处理
            if(need_cover_chars.find(base[i])!=need_cover_chars.end()){
                chars_count[base[i]]--;
            }
            i++;
            //重新计算是否满足条件
            coveredFlag=1;
            for (map<char, int>::iterator it = need_cover_chars.begin(); it != need_cover_chars.end(); ++it) {
                    if (it->second > chars_count[it->first]){
                        coveredFlag=0;
                    }
            }
        }
    }

    string ans="";
    cout<<resultI<<" "<<resultJ<<endl;

    if(resultLen!= INT32_MAX) {
        for(int i=resultI;i<=resultJ;i++){
            ans+=base[i];
        }
    }

    return ans;

}


int main(){
   
    string s="a", t = "aa";
    cout<<minSubStringCover(s,t)<<endl;
}