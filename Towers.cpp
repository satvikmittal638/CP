#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n;cin>>n;
    multiset<int> tops;
    for(int i=0;i<n;i++){
        int k;cin>>k;
        auto it=tops.upper_bound(k);
        if(it!=tops.end()){
            tops.erase(it);
        }
        tops.insert(k);
    }
    cout<<tops.size();
    return 0;
}