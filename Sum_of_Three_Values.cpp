#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    int n,x;cin>>n>>x;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i+1;
    }
    sort(all(a));
    bool done=0;
    for(int i=0;i<n && !done;i++){
        int l=i+1,r=n-1;
        while(l<r){
            if(a[l].first+a[r].first+a[i].first>x){
                r--;
            }
            else if(a[l].first+a[r].first+a[i].first<x){
                l++;
            }
            else{
                cout<<a[i].second<<" "<<a[l].second<<" "<<a[r].second;
                done=1;
                break;
            }
        }
    }
    if(!done) cout<<"IMPOSSIBLE";
    return 0;
}