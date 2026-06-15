#include <iostream>
#include<string>
using namespace std;

int main() {
    int ans;
    string stones;
    getline(cin,stones);
    getline(cin,stones);
    ans=0;
    for(int i=0;i<stones.size()-1;i++){
        if(stones[i]==stones[i+1]){
            ans++;
        }

    }
    cout<<ans<<endl;

    

}
// 64 位输出请用 printf("%lld")