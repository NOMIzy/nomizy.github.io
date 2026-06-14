# include<iostream>
# include<vector>
#include <random>
#include <chrono>
#include<algorithm>
using namespace std;

// 生成指定尺寸的包含 int 类型随机数的 vector 对象
std::vector<int> generateRandomVector(int size, int min = 0, int max = 100000) {
    std::vector<int> array(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);

    for (int& num : array) {
        num = dis(gen);
    }

    return array;
}

using namespace std;

void quicksort(int left,int right,vector<int> &a){
    int i,j,t,temp;
    if(left>right)return;


    temp=a[left];//以最左边的数为基准数

    i=left;
    j=right;//变量i,j从区间左右开始进行移动比较

    while(i!=j){
        //j先走，避免ij交错
        while(a[j]>=temp && i<j){
            j--;
        }

        while(a[i]<=temp && i<j){
            i++;
        }

        if(i<j){
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    //i和j将会在Pivot应该在的位置相遇，停下
    a[left]=a[i];
    a[i]=temp;

    quicksort(left,i-1,a);
    quicksort(i+1,right,a);

}

int main(){
    for(int j=10;j<1000000;j*=10){
            vector<int> test=generateRandomVector(j);
             // 计时开始
            auto start = std::chrono::high_resolution_clock::now();
            quicksort(0,test.size()-1,test);
            cout<<j<<"  ";
            
            // 计时结束
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;

            std::cout << "Sorting took " << elapsed.count() << " seconds.\n";

            // 打印前十个元素以验证排序结果
            for (int i = 0; i < 10 ; ++i) {
                cout << test[i] << " ";
            }
            cout << std::endl;
            
    }

}