#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,x,y;cin>>n>>x>>y;
       if(y-x+1>=n){
        int d=(y-x)/(n-1);
        for(int a=x;a<=y;a+=d){
            cout<<a<<" ";
        }
       }else{
        deque<int> dq;
        for(int a=x;a<=y;a++){
            dq.push_back(a);
        }
        n-=(y-x+1);
        x--;
        while(x>0 && n>0){
            dq.push_front(x);
            x--;
            n--;
        }
        y++;
        while(n>0){
            dq.push_back(y);
            n--;
            y++;
        }

        while(dq.size()){
            cout<<dq.front()<<" ";
            dq.pop_front();
        }
       }
       cout<<"\n";
       
    }
    return 0;
}