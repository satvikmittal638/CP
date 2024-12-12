#include<bits/stdc++.h>
using namespace std;

int main()
{
    int tt;cin>>tt;
    while(tt--){
       int n,m,k;cin>>n>>m>>k;
       string s;cin>>s;
       int cnt_opn=0,l=0;
       for(int i=0;i<n;i++){
        if(s[i]=='0'){
            l++;
        }else{
            l=0;
        }
        if(l>=m){
            cnt_opn++;
            i+=k-1; // make all 1s starting from last 0 of the current 0-segment
            l=0;
        }
       }
       cout<<cnt_opn<<"\n";
    }
    return 0;
}