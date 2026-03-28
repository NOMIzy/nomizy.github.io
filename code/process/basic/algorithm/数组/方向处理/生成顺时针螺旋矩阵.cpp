#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generateMatrix(int n){
    vector<vector<int>> ans(n,vector<int>(n,0));
    int startX=0;
    int startY=0;
    int content=1;
    int mid=n/2;
    int offset=1;
    int i,j;

    //层数
    int loop=n/2;
    //每层的四个方向遍历
    while(loop--){
        i=startX;
        j=startY;
        //转一个圈
        //--》
        for(j=startY;j<startY+n-offset;j++){
            ans[startX][j]=content;
            content++;
        }
        //|
        for(i=startX;i<startX+n-offset;i++){
            ans[i][j]=content;
            content++;
        }
        //《——
        for(;j>startY;j--){
            ans[i][j]=content;
            content++;
        }
        //|
        for(;i>startX;i--){
            ans[i][j]=content;
            content++;
        }
        startX++;
        startY++;
        offset+=2;


    }
    if(n%2){
        ans[mid][mid]=content;
    }

    
    return ans;
    
}

int main(){
    
    vector<vector<int>> ans=generateMatrix(5);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;

    }
}
