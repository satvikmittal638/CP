#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       deque<int> dq(n);for(auto &i:dq) cin>>i;
       int total_a=0,total_b=0,moves=0,cur_a=0,cur_b=0;
       while(!dq.empty()){
        // Alice's chance
        cur_a=0;
        while(cur_a<=cur_b && !dq.empty()){
            cur_a+=dq.front();
            dq.pop_front();
        }
        if(cur_a>0) moves++;

        // Bob's chance
        cur_b=0;
        while(cur_b<=cur_a && !dq.empty()){
            cur_b+=dq.back();
            dq.pop_back();
        }
        if(cur_b>0) moves++;

        total_a+=cur_a;
        total_b+=cur_b;
       }
        cout<<moves<<" "<<total_a<<" "<<total_b<<"\n";
    }
    return 0;
}