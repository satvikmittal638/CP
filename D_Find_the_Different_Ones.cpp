#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n+1);
       for(int i=1;i<=n;i++) cin>>a[i];
        // precomputation
        vector<int> p(n+1); // p[i] is index of nearest elt to the left of a[i] that is not equal to it
        // all elts b/w p[i-1] and i are equal to a[i] by construction
        p[1]=-1;
        for(int i=2;i<=n;i++){
            if(a[i]!=a[i-1]) p[i]=i-1;
            else p[i]=p[i-1];
        }

       int q;cin>>q;
       while(q--){
        int l,r;cin>>l>>r;
        
        // greedily fix the right index and get the nearest left index which has same element as a[r]
        if(l<=p[r]) cout<<p[r]<<" "<<r<<"\n";
        else cout<<"-1 -1\n";
       }
        cout<<"\n";
    }
    return 0;
}