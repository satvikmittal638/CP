#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    const int MAX=1e3;
    int n;cin>>n;
    int k1;cin>>k1;
    deque<int> p1;
    for(int i=0;i<k1;i++){
        int x;cin>>x;
        p1.push_back(x);
    }
    int k2;cin>>k2;
    deque<int> p2;
    for(int i=0;i<k2;i++){
        int x;cin>>x;
        p2.push_back(x);
    }

    int cnt_chances=0;
    for(int i=0;i<MAX && p1.size() && p2.size();i++){
        int top1=p1.front(),top2=p2.front();
        p1.pop_front();p2.pop_front();
        if(top1>top2){
            p1.push_back(top2);
            p1.push_back(top1);
        }
        else{
            p2.push_back(top1);
            p2.push_back(top2);
        }
        cnt_chances++;
    }
    if(p1.size() && p2.size()){
        cout<<-1;
    }
    else{
        cout<<cnt_chances<<" ";
        if(p1.size()) cout<<1;
        else cout<<2;
    }
    return 0;
}