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
    vector<int> idxA(n+1),idxB(n+1);
    for(int i=0;i<n;i++){
        int a;cin>>a;
        idxA[a]=i;
    }
    for(int i=0;i<n;i++){
        int b;cin>>b;
        idxB[b]=i;
    }
    vector<int> ansForMod(n,0);
    for(int i=1;i<=n;i++){
        int curMod=(idxB[i]-idxA[i]+n)%n;
        ansForMod[curMod]++;
    }
    int ans=*max_element(all(ansForMod));
    cout<<ans;
    return 0;
}