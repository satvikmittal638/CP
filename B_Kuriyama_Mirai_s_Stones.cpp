#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int> v(n+1);
    vector<long long> pref(n+1,0),pref_sorted(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>v[i];
        pref[i]=pref[i-1]+v[i];
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++){
        pref_sorted[i]=pref_sorted[i-1]+v[i];
    }
    int m;cin>>m;
    while(m--){
        int type,l,r;cin>>type>>l>>r;
        if(type==1){
            cout<<pref[r]-pref[l-1];
        }else{
            cout<<pref_sorted[r]-pref_sorted[l-1];
        }
        cout<<"\n";
    }
    return 0;
}