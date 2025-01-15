#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n,k;cin>>n>>k;
    if(k<__builtin_popcount(n) || k>n){
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    vector<ll> ans(32,0ll);
    queue<int> q;
    for(int i=0;i<32;i++){
        if(n&(1<<i)){
            ans[i]++;
            if(i>0)q.push(i);
        }
    }
    int cnt=__builtin_popcount(n);
    while(cnt<k && q.size()){
        int z=q.front();
        q.pop();
        ans[z]--;
        ans[z-1]+=2;
        if(z>1){
            q.push(z-1);
            q.push(z-1);
        }
        cnt++;
    }
    for(int i=0;i<32;i++){
        for(int j=0;j<ans[i];j++){
            cout<<(1<<i)<<" ";
        }
    }
    
    return 0;
}