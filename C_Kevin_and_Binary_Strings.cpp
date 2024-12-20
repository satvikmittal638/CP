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
       string s;cin>>s;
       int n=s.length();
       // find position of 1st 0
       int k=0;
       while(k<n && s[k]=='1') k++;
    //    cout<<k<<"  ";
       // all 1s
        if(k==n){
            cout<<1<<" "<<n<<" "<<"1 1\n";
            continue;
        }

       int winSize=n-k; // length of the other substring
    //    cout<<winSize<<"  ";
       string xored=s,mask;
       int l,r;
       auto xorStr=[&](string toXor){
        for(int i=k;i<n;i++){
            if(toXor[i]!=mask[i-k]) toXor[i]='1';
            else toXor[i]='0';
        }
        return toXor;
       };
       for(int i=0;i<=n-winSize;i++){
        mask=s.substr(i,winSize);
        string curXored=xorStr(s);
        // cout<<curXored<<" "<<xored<<"\n";
        if(curXored>xored){
            // cout<<"YES";
            l=i;
            r=i+winSize-1;
            xored=curXored;
        }
       }
       cout<<1<<" "<<n<<" "<<l+1<<" "<<r+1<<"\n";
    }
    return 0;
}