#include <iostream>
#include <vector>
#include <random>
#include <chrono>
using namespace std;

// 生成指定尺寸的包含 int 类型随机数的 vector 对象
std::vector<int> generateRandomVector(int size, int min = 0, int max = 10000) {
    std::vector<int> array(size);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);

    for (int& num : array) {
        num = dis(gen);
    }

    return array;
}

// 合并两个已排序的子数组
void merge(vector<int>& array, int left, int mid, int right) {
    //确定两个子数组的长度
    int n1 = mid - left + 1;
    int n2 = right - mid;

    //申请额外空间
    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; ++i) {
        L[i] = array[left + i];
    }
    for (int i = 0; i < n2; ++i) {
        R[i] = array[mid + 1 + i];
    }

    //merge过程，当两个子数组都不为空
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    //处理剩余部分，直接全部复制
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

// 归并排序
void mergeSort(vector<int>& array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}

int main() {

        for(int j=10;j<1000000;j*=10){
            vector<int> test=generateRandomVector(j);
             // 计时开始
            auto start = std::chrono::high_resolution_clock::now();
            // 调用归并排序算法
            mergeSort(test, 0, test.size() - 1);
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
