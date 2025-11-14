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
       vector<int> a(n),even;
       for(auto &i:a) {
        cin>>i;
        // if(i%2==0) even.push_back(i);
       }
    //    if(even.size()>=2){
    //     cout<<even[0]<<' '<<even[1]<<'\n';
    //     continue;
    //    }

       bool found=0;
       for(int i=0;i<n && !found;i++){
        for(int j=i+1;j<n;j++){
            if((a[j]%a[i])%2==0){
                cout<<a[i]<<' '<<a[j]<<'\n';
                found=1;
                break;
            }
        }
       }
       if(found) continue;
       cout<<"-1\n";
    }
    return 0;
}