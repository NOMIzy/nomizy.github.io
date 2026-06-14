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
int main(){
    vector<int> nums = {1,1,1,2,2}; // 输入数组
    vector<int> expectedNums = {1,2,3,4,5,6}; // 长度正确的期望答案

    int k = removeElement(nums,1);
    cout<<k<<endl;
    
    for (int i = 0; i < k; i++) {
        cout<<nums[i] <<" ";
    }

}