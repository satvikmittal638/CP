#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    vector<int> pref(n+1,0);
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        pref[i]=pref[i-1]+a;
    }
    int m;cin>>m;
    while(m--){
        int q;cin>>q;
        // find i st q<=pref[i]
        auto it=lower_bound(pref.begin()+1,pref.end(),q);
        int i=it-pref.begin();
        cout<<i<<"\n";
    }

    return 0;
}