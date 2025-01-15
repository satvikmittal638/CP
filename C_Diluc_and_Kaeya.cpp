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
       string s;cin>>s;
       int cnt_d=0,cnt_k=0;
       map<pair<int,int>,int> mp; // slope(k/d),freq
       for(int i=0;i<n;i++){
        cnt_d+=s[i]=='D';
        cnt_k+=s[i]=='K';
        int num=cnt_k,den=cnt_d,h=gcd(cnt_d,cnt_k);
        if(num==0){
            den=1;
        }
        else if(den==0){
            num=1;
        }
        else{
            num/=h;den/=h;
        }
        mp[{num,den}]++;
        cout<<mp[{num,den}]<<" ";
       }
       cout<<"\n";
    }
    return 0;
}