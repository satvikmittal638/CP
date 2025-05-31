#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n;cin>>n;
    vector<int> p(n),c(n);
    for(int i=0;i<n;i++){
        cin>>p[i]>>c[i];
        p[i]--;
    }
    vector<bool> canDel(n,1);
    for(int i=0;i<n;i++){
        if(c[i]==0) canDel[i]=canDel[p[i]]=0;
    }
    int cnt=count(all(canDel),1);
    for(int i=0;i<n;i++){
        if(canDel[i]) cout<<i+1<<" ";
    }
    if(cnt==0) {
        cout<<-1;
    }
    return 0;
}