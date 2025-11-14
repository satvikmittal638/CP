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
       int n,k;cin>>n>>k;
       vector<int> g_ops(n+2,0);
       for(int i=0;i<n;i++){
        int a;cin>>a;
        // g=a
        g_ops[a]++;
        g_ops[a+1]--;
        // g=a/2
        if(a%2==0){
            g_ops[a/2]++;
            g_ops[(a/2)+1]--;
        }
        // g=a/3
        if(a%3==0){
            g_ops[a/3]++;
            g_ops[(a/3)+1]--;
        }
        // 1<=g<=floor(a/4)
        if(a>=4){
            g_ops[1]++;
            g_ops[(a/4)+1]--;
        }
       }
       partial_sum(all(g_ops),g_ops.begin());
       int g=n;
       while(g>=1 && g_ops[g]<(n-k)) g--;
       cout<<g<<'\n';
    }
    return 0;
}