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
       vector<int> p(n);for(auto &i:p) cin>>i;
       string x;cin>>x;
       bool ok=x[0]=='0' && x[n-1]=='0';
       int pos1,posn;
       for(int i=0;i<n;i++){
        if(p[i]==1) {
            ok&=(x[i]=='0');
            pos1=i+1;
        }
        else if(p[i]==n){
            ok&=(x[i]=='0');
            posn=i+1;
        }
       }
       if(!ok){
        cout<<"-1\n";
        continue;
       }
       cout<<"5\n";
       cout<<"1 "<<pos1<<'\n';
       cout<<"1 "<<posn<<'\n';
       cout<<pos1<<' '<<n<<'\n';
       cout<<posn<<' '<<n<<'\n';
       cout<<min(pos1,posn)<<' '<<max(pos1,posn)<<'\n';

    }
    return 0;
}