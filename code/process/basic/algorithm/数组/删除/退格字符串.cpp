#include<iostream>
#include<vector>
#include<string>
using namespace std;

//双指针法移除某个特定元素
int removeElement(vector<char>& nums, char val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }

int removeBackSpace(vector<char>& nums, char val) {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }else{
                slowIndex--;
            }

            /*
            for(int i=0;i<nums.size();i++){
                cout<<nums[i]<<" ";
            }
            cout<<endl;
            */
        }
    return slowIndex;
}

bool backspaceCompare(string s, string t) {
        int slowIndex = 0;
        char val='#';
        for (int fastIndex = 0; fastIndex < s.size(); fastIndex++) {
            if (val != s[fastIndex]) {
                s[slowIndex++] = s[fastIndex];
            }else{
                if(slowIndex!=0)slowIndex--;
            }         
        }
        int slow_1=slowIndex;
        slowIndex = 0;
        
        for (int fastIndex = 0; fastIndex < t.size(); fastIndex++) {
            if (val != t[fastIndex]) {
                t[slowIndex++] = t[fastIndex];
            }else{
                if(slowIndex!=0)slowIndex--;
            }         
        }
        if(slow_1 != slowIndex) return false;
        for(int i=0;i<slow_1;i++){
            if(s[i]!=t[i]){
                return false;
            }
        }
        return true;

    }
    
int main(){
    cout<<backspaceCompare("ab#","ac#");

}