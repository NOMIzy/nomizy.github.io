#include<iostream>
using namespace std;

class Character{
    public:
        int life;
        int attack;
    Character(){
        life=0;
        attack=0;
    }
    void Init_life(int l){
        life=l;
        
    }
    void Init_attack(int a){
        
        attack=a;
    }
};

class Player{
    public:
    int now_character;
    Character character_list[5];
    
    void Init(){
        now_character=0;
        int l,a;
        for(int i=0;i<5;i++){
            cin>>a;
            character_list[i].Init_attack(a);
        }
        for(int i=0;i<5;i++){
            cin>>l;
            character_list[i].Init_life(l);
        }
    }

};

void PVP(Player &p1,Player &p2){
    //一个回合，p1先手攻击
    p2.character_list[p2.now_character].life-=p1.character_list[p1.now_character].attack;
    if(p2.character_list[p2.now_character].life<=0){
        p2.now_character++;
    }
    if(p2.now_character<5){
        p1.character_list[p1.now_character].life-=p2.character_list[p2.now_character].attack;
        if(p1.character_list[p1.now_character].life<=0){
            p1.now_character++;
        }

    }
    
};   

int main(){
    Player p1,p2;
    p1.Init();
    p2.Init();
    
    while(p1.now_character<5 && p2.now_character<5){
        PVP(p1,p2);
        if(p2.now_character==5){
            cout<<"win"<<endl;
            cout<<5-p1.now_character<<endl;
        }
        if(p1.now_character==5){
            cout<<"lose"<<endl;
            cout<<5-p2.now_character<<endl;
        }

    }

}

