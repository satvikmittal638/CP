#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        vector<int> a(n+1,LLONG_MAX);
        for(int i=0;i<n;i++){
            cin>>k;
            a[k]=1;
        }
        for(int i=2;i<=n;i++){
            if(a[i]==LLONG_MAX)continue;
            for(int j=i;i*j<=n;j++){
                if(a[j]==LLONG_MAX)continue;
                a[i*j]=min(a[i*j],a[i]+a[j]);
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i]==LLONG_MAX)cout<<-1<<" ";
            else cout<<a[i]<<" ";
        }
        cout<<endl;
    }
}