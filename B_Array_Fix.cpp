#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n;cin>>n;
       vector<int> a(n);for(auto &i:a) cin>>i;
       bool canSort=1;
       for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            int t,o;
            o=a[i]%10;
            t=a[i]/10;
            vector<int> tmp={i>=1?a[i-1]:INT_MIN,t,o,a[i+1]};
            if(!is_sorted(tmp.begin(),tmp.end())){
                canSort=0;break;
            }
        }
       }
       cout<<(canSort?"YES\n":"NO\n");
    }
    return 0;
}