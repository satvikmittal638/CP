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
    cout<<(3*n-2)<<"\n";
    for(int i=0;i<n;i++){
        cout<<i<<" "<<i<<"\n";
        if(i>0)cout<<i<<" "<<i-1<<"\n";
        if(i<n-1)cout<<i<<" "<<i+1<<"\n";
    }
    return 0;
}