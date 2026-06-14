#include<iostream>
using namespace std;

int map[1000][1000]={};
class Arch{
    public:
    int x,y,r;

    bool IsIn(int x0, int y0){
        int xd=0,xu=999,yd=0,yu=999;
        if(x-r>=0) xd=x-r;
        if(x+r<=999) xu=x+r;
        if(y-r>=0) yd=y-r;
        if(y+r<=999) yu=y+r;
        return x0>=xd && x0<=xu && y0>=yd && y0<=yu;
    }
};

int main(){
    int n,q;
    cin>>n;
    Arch arch_list[n];
    int x,y,r;
    for(int i=0;i<n;i++){
        cin>>x>>y>>r;
        arch_list[i].x=x+500;
        arch_list[i].y=y+500;
        arch_list[i].r=r;

    }

    cin>>q;
    for(int i=0;i<q;i++){
        int count=0;
        cin>>x>>y;
        x=x+500;
        y=y+500;
        for(int j=0;j<n;j++){
            if(arch_list[j].IsIn(x,y)){
                count++;
            }
        }
        cout<<count<<endl;

    }

}
