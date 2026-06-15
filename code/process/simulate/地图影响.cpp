#include<iostream>
using namespace std;

int map[1000][1000]={};

int main(){
    int n,q;
    cin>>n;
    int x,y,r;
    for(int i=0;i<n;i++){
        cin>>x>>y>>r;
        x=x+500;
        y=y+500;

        int xd=0,xu=999,yd=0,yu=999;
        if(x-r>=0) xd=x-r;
        if(x+r<=999) xu=x+r;
        if(y-r>=0) yd=y-r;
        if(y+r<=999) yu=y+r;
        

        for(int xx=xd;xx<=xu;xx++){
            for(int yy=yd;yy<=yu;yy++){
                map[xx][yy]++;
            }
        }
    }

    cin>>q;
    for(int i=0;i<q;i++){
        cin>>x>>y;
        cout<<map[x+500][y+500]<<endl;
    }

}
