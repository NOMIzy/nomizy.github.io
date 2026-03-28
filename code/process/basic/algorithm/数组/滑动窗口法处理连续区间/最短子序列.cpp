#include<iostream>
#include<vector>
using namespace std;

//滑动窗口法可以处理对一段连续数组区间的判断
//这个判断是固定的，和当前这段连续数组有关，要么为真要么为假
//那么是否能判断完全部的区间呢？
//如果我们要找的是满足某个条件的连续数组区间，是可以的
//从某个位置开始，一直找到满足条件的区间的末位置
//然后再从这个位置开始走，节省的是嵌套循环O（n^2)中内部循环逐步累加的过程

//计算复杂度，前后两个指针都要走完整个数组 2n
//前面一个走一下判断一下，后面一个走一下判断一下，判断次数 2n
//总体是O（n）的计算复杂度


//判断条件是连续数组子序列元素和是否大于等于s
int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0; // 滑动窗口数值之和
        int i = 0; // 滑动窗口起始位置
        int subLength = 0; // 滑动窗口的长度
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
            while (sum >= s) {
                subLength = (j - i + 1); // 取子序列的长度
                result = result < subLength ? result : subLength;
                sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
            }
        }
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }

int main(){
    vector<int> test={1,2,1,3,4,2,4,5};
    cout<<minSubArrayLen(8,test)<<endl;
}