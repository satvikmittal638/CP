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
       int k;cin>>k;
       // express k as a sum of triangular no.s
       // for (n*(n-1)/2) form, we store n
       vector<int> ns;
       while(k){
        int n=(1+sqrt(1+8*k))/2;
        if(n>0) ns.push_back(n);
        k-=n*(n-1)/2;
       }
       int total=accumulate(all(ns),0);
       cout<<total<<"\n";
       int x=0,y=0;
       for(auto n:ns){
        while(n){
            cout<<x<<" "<<y<<"\n";
            x++;
            n--;
        }
        y++;
       }


    }
    return 0;
}