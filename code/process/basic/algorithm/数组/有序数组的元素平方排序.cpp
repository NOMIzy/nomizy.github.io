#include<iostream>
#include<vector>
using namespace std;

//给定一个按从小到大顺序排列包含负数的数组
//返回其平方从小到大排序的数组
vector<int> sortedSquares(vector<int>& A) {
        int k = A.size() - 1;
        vector<int> result(A.size(), 0);
        for (int i = 0, j = A.size() - 1; i <= j;) { // 注意这里要i <= j，因为最后要处理两个元素，就是说当i==j时，这个元素也可以通过第二个else判断被放进去
            if (A[i] * A[i] < A[j] * A[j])  {
                result[k--] = A[j] * A[j];
                j--;
            }
            else {
                result[k--] = A[i] * A[i];
                i++;
            }
        }
        return result;
    }