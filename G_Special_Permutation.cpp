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
       vector<int> ans;
       // all odds in descending
       for(int i=(n%2==0?n-1:n);i>=1;i-=2){
        ans.push_back(i);
       }
       // last element is 1
       ans.push_back(4);
       ans.push_back(2);
       // put all evens from 6 onwards
       for(int i=6;i<=n;i+=2){
        ans.push_back(i);
       }
       bool ok=1;
       for(int i=1;i<n;i++){
        int dif=abs(ans[i]-ans[i-1]);
        if(dif<2 || dif>4 || ans[i]>n){
            ok=0;
            break;
        }
       }
       if(ok) for(auto e:ans) cout<<e<<" ";
       else cout<<-1;
       cout<<"\n";

    }
    return 0;
}