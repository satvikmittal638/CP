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
       int n,q;cin>>n>>q;
       vector<int> a(n);
       set<int> pos;// tracks position of first and last 1
       int sum=0;
       for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        if(a[i]==1) pos.insert(i);
       }
       
       while(q--){
        int op;cin>>op;
        if(op==1){
            int s;cin>>s;
            if(sum>=s){
                if((sum-s)%2==0){
                    cout<<"YES\n";
                }
                // need largest sum of opposite parity
                else{
                    if(pos.empty()){
                        cout<<"NO\n";
                        continue;
                    }
                    int x=*pos.begin(),y=*pos.rbegin();
                    // find max(sum[x+1,n-1],sum[0,y-1])
                    int curS=max(sum-(2*x+1),sum-(2*(n-y-1)+1)); // this has opposite parity
                    cout<<(curS>=s?"YES":"NO")<<'\n';
                }
            }
            else{
                cout<<"NO\n";
            }
        }
        else{
            int i,v;cin>>i>>v;i--;
            if(a[i]!=v) pos.erase(i);

            sum+=v-a[i];
            a[i]=v;
            if(a[i]==1) pos.insert(i);
        }
       }
    }
    return 0;
}