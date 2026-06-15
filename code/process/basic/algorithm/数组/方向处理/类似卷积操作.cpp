#include<string>
#include<iostream>
#include<vector>
using namespace std;
//请注意，面板上所有格子需要同时被更新：你不能先更新某些格子，然后使用它们的更新后的值再更新其他格子。

/*
生命游戏
给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态： 1 即为 活细胞 （live），或 0 即为 死细胞 （dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：

如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。给你 m x n 网格面板 board 的当前状态，返回下一个状态。

m == board.length
n == board[i].length
1 <= m, n <= 25
board[i][j] 为 0 或 1
*/


class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[8]={-1,-1,-1,0,1,1,1,0};
        int dy[8]={-1,0,1,1,1,0,-1,-1};
        vector<vector<int>> matrix(board);
        int r=matrix.size();
        int c=matrix[0].size();
        for(int x=0;x<r;x++){
            for(int y=0;y<c;y++){
                if(matrix[x][y]){
                   int flag=0;
                    for(int pos=0;pos<8;pos++){
                        
                        if(x+dx[pos]>=0 && x+dx[pos]<r && y+dy[pos]>=0 && y+dy[pos] <c ){
                            flag+=matrix[x+dx[pos]][y+dy[pos]];
                        }
                    }
                    if(flag<2 || flag>3){
                       board[x][y]=0; 
                    }
                }else{
                    int flag=0;
                    for(int pos=0;pos<8;pos++){
                        
                        if(x+dx[pos]>=0 && x+dx[pos]<r && y+dy[pos]>=0 && y+dy[pos] <c ){
                            flag+=matrix[x+dx[pos]][y+dy[pos]];
                        }
                    }
                    if(flag==3){
                       board[x][y]=1; 
                    }
                }

            }
        }

    }
};

int matrix[3][100]={};

int main(){
    int r,c,i;
    string temp;
    cin>>r>>c>>i;

    for(int x=0;x<r;x++){
        cin>>temp;
        for(int y=0;y<c;y++){
            matrix[x][y]=int(temp[y])-int('0');
        }
    }

    int dx[8]={-1,-1,-1,0,1,1,1,0};
    int dy[8]={-1,0,1,1,1,0,-1,-1};
    for(int times=0;times<i;times++){
        for(int x=0;x<r;x++){
            for(int y=0;y<c;y++){
                if(matrix[x][y]){
                    int flag=0;
                    for(int pos=0;pos<8;pos++){
                        //flag+=matrix[(x+dx[pos]+r)%r][(y+dy[pos]+c)%c];//无限面板，拼接的坐标算法
                        if(x+dx[pos]>0 && x+dx[pos]<r && y+dy[pos]>0 && y+dy[pos] <c ){
                            flag+=matrix[x+dx[pos]][y+dy[pos]];
                        }
                    }

                    if(flag<2 || flag>3){
                       matrix[x][y]=0; 
                    }
                    cout<<flag<<endl;
                }else{
                    int flag=0;
                    for(int pos=0;pos<8;pos++){
                        flag+=matrix[(x+dx[pos]+r)%r][(y+dy[pos]+c)%c];
                    }
                    if(flag==3){
                       matrix[x][y]=1; 
                    }
                    cout<<flag<<endl;
                }

            }
        }
    }

    for(int x=0;x<r;x++){
        for(int y=0;y<c;y++){
            cout<<matrix[x][y];
        }
        cout<<endl;
    }
}
