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

//定义上下左右边界，逐步缩小边界的做法
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ans;
        if(matrix.empty()) return ans; //若数组为空，直接返回答案
        int u = 0; //赋值上下左右边界
        int d = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;
        while(true)
        {
            for(int i = l; i <= r; ++i) ans.push_back(matrix[u][i]); //向右移动直到最右
            if(++ u > d) break; //重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
            for(int i = u; i <= d; ++i) ans.push_back(matrix[i][r]); //向下
            if(-- r < l) break; //重新设定右边界
            for(int i = r; i >= l; --i) ans.push_back(matrix[d][i]); //向左
            if(-- d < u) break; //重新设定下边界
            for(int i = d; i >= u; --i) ans.push_back(matrix[i][l]); //向上
            if(++ l > r) break; //重新设定左边界
        }
        return ans;
}



int main(){
    vector<int> test;
    vector<vector<int>> ans=generateMatrix(5);
    test=spiralOrder(ans);
    for(int i=0;i<test.size();i++){
        cout<<test[i]<<' ';
    }
    cout<<endl;

    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    test=spiralOrder(matrix);
    for(int i=0;i<test.size();i++){
        cout<<test[i]<<' ';
    }
    cout<<endl;
}
