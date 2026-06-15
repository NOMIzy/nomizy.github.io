/*
283. 移动零
已解答
简单
相关标签
相关企业
提示
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。

 

示例 1:

输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
示例 2:

输入: nums = [0]
输出: [0]
*/

#include<iostream>
#include<vector>
using namespace std;

//双指针法移除某个特定元素
int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }

int moveZeroes(vector<int>& nums) {
    int len=removeElement(nums,0);
    for(int i=len;i<nums.size();i++){
        nums[i]=0;
    }

    return len;
}
int main(){
    vector<int> nums = {1,0,0,0,1,1,2,2}; // 输入数组
    vector<int> expectedNums = {1,2,3,4,5,6}; // 长度正确的期望答案

    int k = moveZeroes(nums);
    cout<<k<<endl;
    
    for (int i = 0; i < nums.size(); i++) {
        cout<<nums[i] <<" ";
    }

}