#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
你正在探访一家农场，农场从左到右种植了一排果树。这些树用一个整数数组 fruits 表示，其中 fruits[i] 是第 i 棵树上的水果 种类 。

你想要尽可能多地收集水果。然而，农场的主人设定了一些严格的规矩，你必须按照要求采摘水果：

你只有 两个 篮子，并且每个篮子只能装 单一类型 的水果。每个篮子能够装的水果总量没有限制。
你可以选择任意一棵树开始采摘，你必须从 每棵 树（包括开始采摘的树）上 恰好摘一个水果 。采摘的水果应当符合篮子中的水果类型。每采摘一次，你将会向右移动到下一棵树，并继续采摘。
一旦你走到某棵树前，但水果不符合篮子的水果类型，那么就必须停止采摘。
给你一个整数数组 fruits ，返回你可以收集的水果的 最大 数目。

 

示例 1：

输入：fruits = [1,2,1]
输出：3
解释：可以采摘全部 3 棵树。
示例 2：

输入：fruits = [0,1,2,2]
输出：3
解释：可以采摘 [1,2,2] 这三棵树。
如果从第一棵树开始采摘，则只能采摘 [0,1] 这两棵树。
示例 3：

输入：fruits = [1,2,3,2,2]
输出：4
解释：可以采摘 [2,3,2,2] 这四棵树。
如果从第一棵树开始采摘，则只能采摘 [1,2] 这两棵树。
示例 4：

输入：fruits = [3,3,3,1,2,1,1,2,3,3,4]
输出：5
解释：可以采摘 [1,2,1,1,2] 这五棵树。
 
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


//判断条件是连续数组子序列元素数目
int maxSubArrayLenElemNumLimit(int limit, vector<int>& nums) {
        int result = 0;
        int i = 0; // 滑动窗口起始位置
        int subLength = 0; // 滑动窗口的长度
        int elemType=0;
        map<int,int> elemNum;

        for (int j = 0; j < nums.size(); j++) {
            // 新增一个后端元素时，判断条件的变化
                //如果元素不存在，新增map，改变元素计数值
                if(elemNum.find(nums[j])==elemNum.end()){
                    elemNum[nums[j]]=1;
                    elemType++;
                }else{//如果元素存在，在map中记录元素个数变化
                    elemNum[nums[j]]++;
                }

                if(elemType<=limit){
                    subLength = (j - i + 1); // 取子序列的长度
                    result = result > subLength ? result : subLength;
                }

                // 使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
                //条件是当元素个数太多，慢指针要走到直至元素个数不超
                while (elemType>limit) {//满足条件时，慢指针移动 
                    //减少一个前端元素，判断条件的变化   
                    elemNum[nums[i]]--;
                    if(elemNum[nums[i]]==0){
                        elemNum.erase(nums[i]);
                        elemType--;
                    }  
                    i++;
                }   

        }
        // 如果result没有被赋值的话，就返回说明没有符合条件的子序列
        return result == 0 ? -1 : result;
    }

int main(){
    vector<int> test={3,3,3,1,2,1,1,2,3,3,4};
    cout<<maxSubArrayLenElemNumLimit(2,test)<<endl;
}