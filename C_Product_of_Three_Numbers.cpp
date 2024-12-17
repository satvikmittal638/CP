#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       set<int> used;
       // find minm divisor of n
       for(int i=2;i*i<=n;i++){
        if(n%i==0 && !used.count(i)){
            used.insert(i);
            n/=i;
            break;
        }
       }

    // find minm divisor of n/a
       for(int i=2;i*i<=n;i++){
        if(n%i==0 && !used.count(i)){
            used.insert(i);
            n/=i;
            break;
        }
       }

       if(used.size()<2 || used.count(n)!=0 || n==1){
        cout<<"NO\n";
       }
        // if we found a and b, n/ab is not same as a,b or 1
       else{
        cout<<"YES\n";
        used.insert(n);
        for(auto it:used) cout<<it<<" ";
        cout<<"\n";
       }
    }
    return 0;
}