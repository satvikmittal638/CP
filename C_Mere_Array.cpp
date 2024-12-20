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
       vector<int> a(n);
       for(auto &i:a) cin>>i;
       int m=*min_element(all(a));
       vector<int> val,ind;
       for(int i=0;i<n;i++){
        if(a[i]%m==0) {
            val.push_back(a[i]);
            ind.push_back(i);
        }
       }
       // any permutation of values divisible by m can be obtained
       sort(all(val));
       sort(all(ind));
       for(int i=0;i<val.size();i++){
        a[ind[i]]=val[i];
       }
       cout<<(is_sorted(all(a))?"YES":"NO")<<"\n";
    }
    return 0;
}