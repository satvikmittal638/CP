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
       vector<int> a(n);for(auto &i:a) cin>>i;
       sort(all(a));
       bool ok=1;
       // 1st step->transfer a[0] to 2nd bag
       for(int i=1;i<n;i++){
        if(a[i]>a[i-1]){
            ok=0;
            break;
        }
        else{
            // block a[i] since a[i]==a[i-1]
            // apply operation-2 on all numbers(indices>i) equal to a[i]
            for(int j=i+1;j<n && a[j]==a[i];j++){
                a[j]++;
            }
        }
       }
       cout<<(ok?"Yes":"No")<<"\n";
    }
    return 0;
}