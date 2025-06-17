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
       int n,x;cin>>n>>x;
       vector<int>a(n);for(auto &i:a) cin>>i;
       auto getFirst=[&](){
        for(int i=0;i<n;i++){
            if(a[i]>x){
                return i;
            }
        }
        return -1;
       };
       // the only thing we can do is to apply the operation to the first elt >x
       int ans=0;
       while(!is_sorted(all(a))){
        int ind=getFirst();
        if(ind<0) break;
        swap(a[ind],x);
        ans++;
       }
       cout<<(is_sorted(all(a))?ans:-1)<<"\n";
    }
    return 0;
}