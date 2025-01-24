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
       vector<int> pos(n+1);
       for(int i=1;i<=n;i++){
        int a;cin>>a;
        pos[a]=i;
       }
       int l=(n+1)/2,r=(n+2)/2;
       // increase the segment size until it becomes unsorted
       while(l>0 && (l==r || pos[l]<pos[l+1] && pos[r-1]<pos[r])){
        l--;
        r++;
       }
       cout<<(n-(r-l-1))/2<<"\n";
       

    }
    return 0;
}