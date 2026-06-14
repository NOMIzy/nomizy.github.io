#include<string>
#include<iostream>
using namespace std;

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

    for(int times=0;times<i;times++){
        for(int x=0;x<r;x++){
            for(int y=0;y<c;y++){
                if(matrix[x][y]){
                    //live
                    int flag=matrix[(x-1+r)%r][(y-1+c)%c];//左上
                    //上
                    flag+=matrix[(x-1+r)%r][(y+c)%c];
                    //右上
                    flag+=matrix[(x-1+r)%r][(y+1+c)%c];
                    //右
                    flag+=matrix[(x+r)%r][(y+1+c)%c];
                    //右下
                    flag+=matrix[(x+1+r)%r][(y+1+c)%c];
                    //下
                    flag+=matrix[(x+1+r)%r][(y+c)%c];
                    //左下
                    flag+=matrix[(x+1+r)%r][(y-1+c)%c];
                    //左
                    flag+=matrix[(x+r)%r][(y-1+c)%c];
                    if(flag<2 || flag>3){
                       matrix[x][y]=0; 
                    }
                }else{
                    //die
                    int flag=matrix[(x-1+r)%r][(y-1+c)%c];//左上
                    //上
                    flag+=matrix[(x-1+r)%r][(y+c)%c];
                    //右上
                    flag+=matrix[(x-1+r)%r][(y+1+c)%c];
                    //右
                    flag+=matrix[(x+r)%r][(y+1+c)%c];
                    //右下
                    flag+=matrix[(x+1+r)%r][(y+1+c)%c];
                    //下
                    flag+=matrix[(x+1+r)%r][(y+c)%c];
                    //左下
                    flag+=matrix[(x+1+r)%r][(y-1+c)%c];
                    //左
                    flag+=matrix[(x+r)%r][(y-1+c)%c];
                    if(flag==3){
                       matrix[x][y]=1; 
                    }
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
