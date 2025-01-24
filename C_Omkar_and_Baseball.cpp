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
       if(is_sorted(all(a))){
        cout<<"0\n";
       }
       else{
        // check if there exists a prefix/suffix of matching indices and everything else is unmatched
        vector<bool> match(n,0);
        for(int i=0;i<n;i++){
            match[i]=(a[i]==i+1);
        }
        // check for 1..10..01..1 so that we apply only 1 operation to 0..0
        int i=0;
        while(i<n && match[i]==1) i++;
        while(i<n && match[i]==0) i++;
        while(i<n && match[i]==1) i++;
        if(i==n) {
            cout<<"1\n";
            continue;
        }
        cout<<"2\n";
       }
    }
    return 0;
}