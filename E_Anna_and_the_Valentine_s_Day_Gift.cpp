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
       int n,m;cin>>n>>m;
       vector<int> a(n);
       auto countTrail0=[](int x){
        int cnt=0;
        while(x%10==0) {
            cnt++;
            x/=10;
        }
        return cnt;
       };
       int totalDigs=0;
       for(int i=0;i<n;i++) {
        cin>>a[i];
        totalDigs+=to_string(a[i]).size();
       }
       // sort in decreasing number of trailing 0s
       sort(rall(a),[&](int x,int y){
        return countTrail0(x)<countTrail0(y);
       });
       int i=0;
       while(i<n){
        // anna's chance, removes maxm trailing 0s
        totalDigs-=countTrail0(a[i]);
        i++; 

        // sasha's chance, just concatenates a[i] with a[i-1](a[i-1] has no trialing 0s left)
        i++;
       }
       cout<<(totalDigs>=m+1?"Sasha":"Anna")<<"\n";
    }
    return 0;
}