#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define rall(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()
int main()
{
fastio;
    auto maxPowOf3=[](int x){
        int val=1,pow=0;
        while(val<=x){
            val*=3;
            pow++;
        }
        return pow;
    };
    const int MAX=2*1e5;
    vector<int> p(MAX+1,0);
    for(int i=1;i<=MAX;i++){
        p[i]=p[i-1]+maxPowOf3(i);
    }
    
    int tt;cin>>tt;
    while(tt--){
       int l,r;cin>>l>>r;
       cout<<(maxPowOf3(l))+(p[r]-p[l-1])<<"\n";
    }
    return 0;
}