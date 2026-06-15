# include<iostream>
# include<vector>

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
    int n;
    cin>>n;
    int num_exist_map[501]={};
    int num;
    vector<int> ans_list;
    for(int i=0;i<n;i++){
        cin>>num;
        if(num_exist_map[num]==0){
            num_exist_map[num]=1;
            ans_list.push_back(num);
        }
    }

    quicksort(0,ans_list.size()-1,ans_list);
    for(int i=0;i<ans_list.size();i++){
        cout<<ans_list[i]<<endl;
    }

}